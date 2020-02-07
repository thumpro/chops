#include <chops/detail/lenses/macro_all.hpp>
#include <chops/detail/lenses/for_each_tuple.hpp>

namespace chops ::lenses {

struct view_t{};
auto constexpr view = view_t{};

template<typename Lens>
auto const& operator*(Lens const& l, view_t const&) {
    return l().get();
}

template<typename Lens, typename T>
auto set(Lens const& l, T const& t) {
    using type = std::remove_cv_t<std::remove_reference_t<decltype(l().get())>>;
    const_cast<type &>(l * view) = t;
    return l;
}

template<typename Lens, typename F>
auto over(F&& f, Lens const& l) {
    using type = std::remove_cv_t<std::remove_reference_t<decltype(l().get())>>;
    auto const& val = l * view;
    const_cast<type &>(val) = f(val);
    return l;
}

template<typename L1, typename L2>
auto operator*(L1 const& l1, L2 const& l2) {
    if constexpr(std::is_invocable_v<L1>)
        return l2(l1());
    else
        return l2(l1);
}

template <typename T, typename Fn>
auto on_each(T const& s, Fn&& f) {
    return for_each(s * T::all, [&](auto const& lens) {
        auto in_lens = s * lens;
        using type = std::remove_cv_t<std::remove_reference_t<decltype(in_lens().get())>>;
        auto const& val = in_lens * view;
        return f(const_cast<type &>(val));
    });
}

}