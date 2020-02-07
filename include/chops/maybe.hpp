#pragma once
#include <chops/variant.hpp>

namespace chops {
struct maybe_error_t {};
auto constexpr static maybe_error = maybe_error_t{};

template <template <typename> class m>
struct monad {
    template <typename a>
    constexpr static m<a> mreturn(const a&);

    template <typename a, typename b>
    constexpr static m<b> mbind(const m<a>&, m<b>(*)(const a&));
};

template <typename T>
struct just { T value; };

struct nothing {};

template <typename T>
using maybe = chops::variant<nothing, just<T>>;

template <>
struct monad<maybe> {
    template <typename T>
    constexpr static maybe<T> mreturn(const T& v) noexcept {
        return maybe<T>{just<T>{v}};
    }

    template <typename T1, typename Fn,
              typename R = std::conditional_t<
              std::is_same_v<decltype(std::declval<Fn>()(std::declval<T1&>())), void>, 
              maybe<T1>, 
              maybe<decltype(std::declval<Fn>()(std::declval<T1&>()))>>>
    static R mbind(maybe<T1>& m, Fn&& f) noexcept {
        if(just<T1>* p = m.template get<just<T1>>())
        {
            f(p->value); 
            return m;
        }
        else
        {
            return R{nothing{}};
        }
    }

    template <typename T1, typename Fn,
              typename R = std::conditional_t<
              std::is_same_v<decltype(std::declval<Fn>()(T1{})), void>, 
              maybe<T1>, 
              maybe<decltype(std::declval<Fn>()(T1{}))>>>
    constexpr static R mbind(const maybe<T1>& m, Fn&& f) noexcept {
        if(const just<T1>* p = m.template get<just<T1>>())
        {

            (void)(m);
            return monad<maybe>::mreturn(f(p->value)); 

        }
        else
        {
            return R{nothing{}};
        }
    }
};

template <typename T1, typename Fn, 
          typename 
          std::enable_if_t<
          std::is_same_v<decltype(std::declval<Fn>()(std::declval<T1&>())), void>, T1>* = nullptr>
auto operator>>(maybe<T1>&& m, Fn&& function) noexcept{
    return monad<maybe>::mbind(m, function);
}

template <typename T1, typename Fn>
constexpr auto operator>>(const maybe<T1>& m, Fn&& function) noexcept {
    return monad<maybe>::mbind(m, function);
}

template <typename T1, typename Fn, 
          typename 
          std::enable_if_t<
          std::is_same_v<decltype(std::declval<Fn>()(std::declval<T1&>())), void>, T1>* = nullptr>
auto operator|(maybe<T1>&& m, Fn&& function) noexcept {
    return monad<maybe>::mbind(m, function);
}

template <typename T1, typename Fn>
constexpr auto operator|(const maybe<T1>& m, Fn&& function) noexcept {
    return monad<maybe>::mbind(m, function);
}

template <typename T1, typename Fn>
constexpr void operator&&(const maybe<T1>& m, Fn&& error_handler) {
    if(m.template get<nothing>())
    {
       error_handler(maybe_error);
    }
}

template<class InputIt, class T>
constexpr InputIt cfind(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

template <typename It, typename V = typename It::value_type>
constexpr auto maybeFind(It b, It e, V const& v) {
    auto it = cfind(b, e, v);
    if(it != e)
        return monad<maybe>::mreturn(*it);
    else
        return maybe<V>{nothing{}};
} 

} //namespace chops