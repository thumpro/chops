#pragma once

#include <chops/detail/lenses/macro_all.hpp>
#include <chops/detail/lenses/lenses_tuple_helpers.hpp>

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
auto visit(F&& f, Lens const& l) {
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
auto visit_each(T const& s, Fn&& f) {
    return detail::for_each(s * T::all, [&](auto const& lens) {
        auto in_lens = s * lens;
        using type = std::remove_cv_t<std::remove_reference_t<decltype(in_lens().get())>>;
        auto const& val = in_lens * view;
        return f(const_cast<type &>(val));
    });
}

template <typename T, typename Fn>
auto visit_by_name(T const& s, std::string_view const& member, Fn&& f) {
    auto i = T::member_index(s, member);
    return detail::apply_at(s, T::all(s), i, f);
}

template <typename T, typename Fn>
auto visit_at(T const& s, Fn&& f, std::size_t id) {
    return detail::apply_at_typesafe(s * T::all, [&](auto const& lens) {
        auto in_lens = s * lens;
        using type = std::remove_cv_t<std::remove_reference_t<decltype(in_lens().get())>>;
        auto const& val = in_lens * view;
        return f(const_cast<type &>(val));
    }, id);
}

}
