#pragma once
#include <chops/function_traits.hpp>
#include <tuple>
#include <type_traits>

namespace chops::lenses::detail {

struct tuple_getter {
    template <typename M, typename... Ts>
    static auto all(M const& m, std::tuple<Ts...> const& t) {
        auto constexpr I = std::make_index_sequence<sizeof...(Ts)>{};
        return all_helper(m, t, I);
    }

private:
    template <typename M, typename... Ts, std::size_t... I>
    static auto all_helper(M const& m, std::tuple<Ts...> const& t, std::index_sequence<I...>) {
        return std::array<std::function<void*(void)>, sizeof...(Ts)> {
            [&]() { return (void *)&(((std::get<I>(t))(m)()).get()); }...
        };
    }
};

template <typename M, typename T, typename Fn>
auto apply_at(M const& m, T const& t, std::size_t i, Fn&& f) {
    using Traits = chops::type_traits::function_traits<decltype(std::move(f))>;
    using arg = typename Traits::template argument<0>::type;
    using param_type = std::remove_reference_t<arg>;
    using return_type = typename Traits::return_type;
    if constexpr(std::is_same_v<void, return_type>)
        f(*static_cast<param_type *>(tuple_getter::all(m, t)[i]()));
    else
        return f(*static_cast<param_type *>(tuple_getter::all(m, t)[i]()));
}

template <class Tuple, class F, std::size_t... I>
constexpr auto for_each_impl(Tuple&& t, F&& f, std::index_sequence<I...>)
{
    using result_type = decltype(std::forward<F>(f)(std::get<0>(std::forward<Tuple>(t))));
    if constexpr(std::is_same_v<void, result_type>) {
        auto x = {(f(std::get<I>(std::forward<Tuple>(t))),0)...};
        (void)(x); // unused
    }
    else
        return std::make_tuple(f(std::get<I>(std::forward<Tuple>(t)))...);
}

template <class Tuple, class F>
constexpr auto for_each(Tuple&& t, F&& f)
{
    using Tup = std::remove_reference_t<Tuple>;
    return for_each_impl(std::forward<Tuple>(t), std::forward<F>(f),
                         std::make_index_sequence<std::tuple_size<Tup>::value>{});
}

template<typename Tuple, typename Fn>
constexpr void apply_at_typesafe(Tuple&& tuple, Fn&& f, std::size_t id)
{
    size_t currentIndex = 0;
    for_each(tuple, [&](auto&& value)
                    {
                        if (currentIndex == id)
                        {
                            f(value);
                        }
                        ++currentIndex;
                    });
}

template<typename Tuple, typename Predicate>
constexpr size_t find_if(Tuple&& tuple, Predicate pred)
{
    size_t index = std::tuple_size<std::remove_reference_t<Tuple>>::value;
    size_t currentIndex = 0;
    bool found = false;
    for_each(tuple, [&](auto&& value)
                    {
                        if (!found && pred(value))
                        {
                            index = currentIndex;
                            found = true;
                        }
                        ++currentIndex;
                    });
    return index;
}

};