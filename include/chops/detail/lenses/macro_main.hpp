#pragma once

/* Create a lens, which is a function returning a const ref to a member 
 * For lenses we follow a naming convention:
 * if struct foo wants to have a lens bar, it should call its corresponding
 * member bar_
 * See tests for usage examples
 */
#define MAKE_LENSE_(type, field) \
struct field##_lens { \
constexpr auto operator()(type const& s) const { \
    return [&](){ return std::cref(s.field##_); }; \
} \
}; \
auto static constexpr field = field##_lens{}; \

/* This macro creates a tuple of all lenses and generates serialization 
 * code for the type
 */
#define REGISTER_LENSES_(type,...) \
auto static constexpr has_lenses = true; \
auto static constexpr number_of_members = VA_NARGS(__VA_ARGS__); \
static constexpr auto all(type const& s) { \
    (void)(s); \
    return std::make_tuple(__VA_ARGS__); \
} \
static constexpr auto all_by_name(type const& s) { \
    (void)(s); \
    return std::make_tuple(STRINGIFY_VA(__VA_ARGS__)); \
} \
static constexpr auto has_member(type const& s, std::string_view const& member) { \
    (void)(s); \
    using chops::lenses::detail::find_if; \
    auto i = find_if(type::all_by_name(s), [&](auto const& m){ return m == member; }); \
    if(i < type::number_of_members) \
        return true; \
    else \
        return false; \
} \
static constexpr auto member_index(type const& s, std::string_view const& member) { \
    (void)(s); \
    using chops::lenses::detail::find_if; \
    return find_if(type::all_by_name(s), [&](auto const& m){ return m == member; }); \
} \
template <class T> \
void Serialize(T& archive) \
{ \
    using chops::lenses::visit_each; \
    visit_each(*this, [&](auto& x) { archive & x; }); \
}
