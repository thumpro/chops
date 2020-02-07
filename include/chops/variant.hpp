#pragma once
#include <type_traits>
#include <cstddef> // for size_t
#include <cstdint> // for uint8_t
#include <utility> // for std::move

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

namespace detail {

template<typename F, typename... Ts>
struct variant_size_helper {
    static const size_t size = 
    sizeof(F) > variant_size_helper<Ts...>::size ? 
                            sizeof(F) : 
                            variant_size_helper<Ts...>::size;
};
 
template<typename F>
struct variant_size_helper<F>  {
    static const size_t size = sizeof(F);
};

template <typename T, typename... Ts>
constexpr bool in_pack = std::disjunction_v<std::is_same<T, Ts>...>;

template <uint8_t I, typename R, typename T, typename... Ts>
struct index_of_type_impl {
    constexpr static uint8_t id() {
        if constexpr(std::is_same_v<R, T>) {
            return I;
        }
        else {
            return index_of_type_impl<I + 1, R, Ts...>::id();
        }
    }
};

template <uint8_t I, typename R, typename T>
struct index_of_type_impl<I, R, T> {
    constexpr static uint8_t id() {
        if constexpr(std::is_same_v<R, T>) {
            return I;
        }
        else {
            return 255;
        }
    }
};

template <typename R, typename ...Ts>
constexpr uint8_t index_of_type = index_of_type_impl<0, R, Ts...>::id();

template<uint8_t i, typename F, typename... Ts>
struct destruct_helper {
    inline static void destroy(uint8_t id, void * data) 
    {
        if (i == id) 
            reinterpret_cast<F*>(data)->~F();
        else
            destruct_helper<i + 1, Ts...>::destroy(id, data);
    }
};
 
template<uint8_t i, typename F>
struct destruct_helper<i, F>  {
    inline static void destroy(uint8_t id, void * data) 
    {
        if (i == id)
            reinterpret_cast<F*>(data)->~F();       
    }
};

template<uint8_t i, typename F, typename... Ts>
struct copy_helper {
    inline static void copy(uint8_t id, void *dest, const void *src) 
    {
        if (i == id) {
            auto const& o = *reinterpret_cast<const F*>(src);
            new (dest) F(o);
        }
        else
            copy_helper<i + 1, Ts...>::copy(id, dest, src);
    }
};
 
template<uint8_t i, typename F>
struct copy_helper<i, F>  {
    inline static void copy(uint8_t id, void *dest, const void *src) 
    {
        if (i == id) {
            auto const& o = *reinterpret_cast<const F*>(src);
            new (dest) F(o);
        }       
    }
};

template<uint8_t i, typename F, typename... Ts>
struct move_helper {
    inline static void move(uint8_t id, void *dest, void *src) 
    {
        if (i == id) {
            auto const& o = *reinterpret_cast<F*>(src);
            new (dest) F(std::move(o));
        }
        else
            move_helper<i + 1, Ts...>::move(id, dest, src);
    }
};
 
template<uint8_t i, typename F>
struct move_helper<i, F>  {
    inline static void move(uint8_t id, void *dest, void *src) 
    {
        if (i == id) {
            auto const& o = *reinterpret_cast<F*>(src);
            new (dest) F(std::move(o));
        }       
    }
};

template<uint8_t i, typename Fn, typename F, typename... Ts>
struct visit_helper {
    inline static auto visit(uint8_t id,Fn const& f, void * data) 
    {
        if constexpr(std::is_invocable_v<Fn, F>) {
            if(i == id) 
                return f(*reinterpret_cast<F*>(data));
            else
                return visit_helper<i + 1, Fn, Ts...>::visit(id, f, data);
        }
        else
            return visit_helper<i + 1, Fn, Ts...>::visit(id, f, data);
    }
};
 
template<uint8_t i, typename Fn, typename F>
struct visit_helper<i, Fn, F>  {
    inline static auto visit(uint8_t id, Fn const& f, void * data) 
    {
        (void)(id);
        if constexpr (std::is_invocable_v<Fn, F>) {
            return f(*reinterpret_cast<F*>(data));
        }      
    }
};

template <std::size_t I, typename T, typename ...Ts>
struct nth_element_impl {
    using type = typename nth_element_impl<I-1, Ts...>::type;
};

template <typename T, typename ...Ts>
struct nth_element_impl<0, T, Ts...> {
    using type = T;
};

template <std::size_t I, typename ...Ts>
using nth_element = typename nth_element_impl<I, Ts...>::type;

}

namespace chops {

template <typename... Ts>
struct variant {
    variant() : i{255} {
        
    }

    variant(variant const& o) {
        detail::copy_helper<0, Ts...>::copy(o.i, data, o.data);
        i = o.i;
    }

    variant(variant&& o) {
        detail::move_helper<0, Ts...>::move(o.i, data, o.data);
        i = o.i;
    }

    variant& operator=(variant const& o) {
        detail::copy_helper<0, Ts...>::copy(o.i, data, o.data);
        i = o.i;
        return *this;
    }

    variant& operator=(variant&& o) {
        detail::move_helper<0, Ts...>::move(o.i, data, o.data);
        i = o.i;
        return *this;
    }

    template <typename T, 
                std::enable_if_t<detail::in_pack<T, Ts...>,int> = 0>
    variant(T&& t) {
        if constexpr(std::is_rvalue_reference_v<T>) {
            new (&data) T(std::move(t));
            i = detail::index_of_type<T, Ts...>;
        } else { 
            new (&data) T(t);
            i = detail::index_of_type<T, Ts...>;
        }
    }

    template <typename T, 
                std::enable_if_t<detail::in_pack<T, Ts...>,int> = 0>
    variant& operator=(T const& t) {
        if constexpr(!std::is_rvalue_reference_v<T>) {
            detail::destruct_helper<0, Ts...>::destroy(i, data);
            new (&data) T(std::move(t));
            i = detail::index_of_type<T, Ts...>;
            return *this;
        } else { // 
            detail::destruct_helper<0, Ts...>::destroy(i, data);
            new (&data) T(t);
            i = detail::index_of_type<T, Ts...>;
            return *this;
        }
    }

    ~variant() {
        detail::destruct_helper<0, Ts...>::destroy(i, data);
    }

    template <typename T>
    T *get() {
        if (i == detail::index_of_type<T, Ts...>) 
            return as<T>(data);
        else
            return nullptr;
    }

    template <typename T>
    const T *get() const {
        if (i == detail::index_of_type<T, Ts...>) 
            return as<const T>(data);
        else
            return nullptr;
    }

    template <typename Fn>
    auto visit(Fn const& f) {
        return detail::visit_helper<0, Fn, Ts...>::visit(i, f, data);
    }

private:
    template <typename T>
    T *as(uint8_t *buf) { return reinterpret_cast<T*>(buf); }

    template <typename T>
    const T *as(const uint8_t *buf) const { return reinterpret_cast<const T*>(buf); }

    uint8_t data[detail::variant_size_helper<Ts...>::size];
    uint8_t i;
};

} //namespace chops