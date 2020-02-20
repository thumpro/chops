#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

namespace detail::endian_swapper
{

class swap_byte_base
{
public:
    static bool should_swap()
    {
        static const uint16_t swap_test = 1;
        return (*((char*)&swap_test) == 1);
    }

    static void swap_bytes(uint8_t& v1, uint8_t& v2)
    {
        uint8_t tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
};

template <class T, int S>
class swap_byte : public swap_byte_base
{
public:
    static T swap(T v)
    {
        return v;
    }
};

template <class T>
class swap_byte<T, 1> : public swap_byte_base
{
public:
    static T swap(T v)
    {
        return v;
    }
};

template <class T>
class swap_byte<T, 2> : public swap_byte_base
{
public:
    static T swap(T v)
    {
        if(should_swap())
            return ((uint16_t)v >> 8) | ((uint16_t)v << 8);
        return v;
    }
};

template <class T>
class swap_byte<T, 4> : public swap_byte_base
{
public:
    static T swap(T v)
    {
        if(should_swap())
        {
            return (swap_byte<uint16_t, 2>::swap((uint32_t)v & 0xffff) << 16) 
                    | (swap_byte<uint16_t, 2>::swap(((uint32_t)v & 0xffff0000) >> 16));
        }
        return v;
    }
};

template <class T>
class swap_byte<T, 8> : public swap_byte_base
{
public:
    static T swap(T v)
    {
        if(should_swap()) {
            return (((uint64_t)swap_byte<uint32_t, 4>::swap((uint32_t)(v & 0xffffffffull))) << 32) 
                   | (swap_byte<uint32_t, 4>::swap((uint32_t)(v >> 32)));
        }
        return v;
    }
};

template <>
class swap_byte<float, 4> : public swap_byte_base
{
public:
    static float swap(float v)
    {
        union { float f; uint8_t c[4]; };
        f = v;
        if(should_swap())
        {
            swap_bytes(c[0], c[3]);
            swap_bytes(c[1], c[2]);
        }
        return f;
    }
};

template <>
class swap_byte<double, 8> : public swap_byte_base
{
public:
    static double swap(double v)
    {
        union { double f; uint8_t c[8]; };
        f = v;
        if(should_swap())
        {
            swap_bytes(c[0], c[7]);
            swap_bytes(c[1], c[6]);
            swap_bytes(c[2], c[5]);
            swap_bytes(c[3], c[4]);
        }
        return f;
    }
};

} // namespace detail::endian_swapper

namespace chops::serialization {

template <class StreamType>
class archive
{
public:
    archive(StreamType& stream) : m_stream(stream)
    {}

    template <class T>
    const archive& operator<<(const T& v) const
    {
        *this & v;
        return *this;
    }

    template <class T>
    archive& operator>>(T& v)
    {
        *this & v;
        return *this;
    }

    public:
    template <class T>
    archive& operator&(T& v)
    {
        v.Serialize(*this);
        return *this;
    }

    template <class T>
    const archive& operator&(const T& v) const
    {
        ((T&)v).Serialize(*this);
        return *this;
    }

    template <class T, size_t N>
    archive& operator&(T (&v)[N])
    {
        uint32_t len;
        *this & len;
        for(size_t i = 0; i < N; ++i)
            *this & v[i];
        return *this;
    }

    template <class T, size_t N>
    const archive& operator&(const T (&v)[N]) const
    {
        uint32_t len = N;
        *this & len;
        for(size_t i = 0; i < N; ++i)
            *this & v[i];
        return *this;
    }

    #define SERIALIZER_FOR_POD(type) \
    archive& operator&(type& v) \
    { \
        m_stream.read((char*)&v, sizeof(type)); \
        v = swap(v); \
        return *this; \
    } \
    const archive& operator&(type v) const \
    { \
        v = swap(v); \
        m_stream.write((const char*)&v, sizeof(type)); \
        return *this; \
    }

    SERIALIZER_FOR_POD(bool)
    SERIALIZER_FOR_POD(char)
    SERIALIZER_FOR_POD(unsigned char)
    SERIALIZER_FOR_POD(short)
    SERIALIZER_FOR_POD(unsigned short)
    SERIALIZER_FOR_POD(int)
    SERIALIZER_FOR_POD(unsigned int)
    SERIALIZER_FOR_POD(long)
    SERIALIZER_FOR_POD(unsigned long)
    SERIALIZER_FOR_POD(long long)
    SERIALIZER_FOR_POD(unsigned long long)
    SERIALIZER_FOR_POD(float)
    SERIALIZER_FOR_POD(double)

    #define SERIALIZER_FOR_STL(type) \
    template <class T> \
    archive& operator&(type<T>& v) \
    { \
        uint32_t len; \
        *this & len; \
        for(uint32_t i = 0; i < len; ++i) \
        { \
            T value; \
            *this & value; \
            v.insert(v.end(), value); \
        } \
        return *this; \
    } \
    template <class T> \
    const archive& operator&(const type<T>& v) const \
    { \
        uint32_t len = v.size(); \
        *this & len; \
        for(typename type<T>::const_iterator it = v.begin(); it != v.end(); ++it) \
        *this & *it; \
        return *this; \
    }

    #define SERIALIZER_FOR_STL2(type) \
    template <class T1, class T2> \
    archive& operator&(type<T1, T2>& v) \
    { \
        uint32_t len; \
        *this & len; \
        for(uint32_t i = 0; i < len; ++i) \
        { \
            std::pair<T1, T2> value; \
            *this & value; \
            v.insert(v.end(), value); \
        } \
        return *this; \
    } \
    template <class T1, class T2> \
    const archive& operator&(const type<T1, T2>& v) const \
    { \
        uint32_t len = v.size(); \
        *this & len; \
        for(typename type<T1, T2>::const_iterator it = v.begin(); it != v.end(); ++it) \
        *this & *it; \
        return *this; \
    }

    SERIALIZER_FOR_STL(std::vector)
    SERIALIZER_FOR_STL(std::deque)
    SERIALIZER_FOR_STL(std::list)
    SERIALIZER_FOR_STL(std::set)
    SERIALIZER_FOR_STL(std::multiset)
    SERIALIZER_FOR_STL2(std::map)
    SERIALIZER_FOR_STL2(std::multimap)

    template <class T1, class T2>
    archive& operator&(std::pair<T1, T2>& v)
    {
        *this & v.first & v.second;
        return *this;
    }
    
    template <class T1, class T2>
    const archive& operator&(const std::pair<T1, T2>& v) const
    {
        *this & v.first & v.second;
        return *this;
    }
    
    archive& operator&(std::string& v)
    {
        uint32_t len;
        *this & len;
        v.clear();
        char buffer[4096];
        uint32_t toRead = len;
        while(toRead != 0)
        {
            uint32_t l = std::min(toRead, (uint32_t)sizeof(buffer));
            m_stream.read(buffer, l);
            v += std::string(buffer, l);
            toRead -= l;
        }
        return *this;
    }

    const archive& operator&(const std::string& v) const
    {
        uint32_t len = static_cast<uint32_t>(v.length());
        *this & len;
        m_stream.write(v.c_str(), len);
        return *this;
    }

private:
    template <class T>
    T swap(const T& v) const
    {
        return detail::endian_swapper::swap_byte<T, sizeof(T)>::swap(v);
    }

    private:
        StreamType& m_stream;
};

} // namespace chops::serialization