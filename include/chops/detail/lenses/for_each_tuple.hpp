#include <tuple>
#include <type_traits>

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