/* Create a lens, which is a function returning a const ref to a member 
 * For lenses we follow a naming convention:
 * if struct foo wants to have a lens bar, it should call its corresponding
 * member bar_
 * See tests for usage examples
 */
#define MAKE_LENSE_(type, field) \
struct field##_lens { \
inline auto operator()(type const& s) const { \
    return [&](){ return std::cref(s.field##_); }; \
} \
}; \
auto static constexpr field = field##_lens{}; \

/* This macro creates a tuple of all lenses and generates serialization 
 * code for the type
 */
#define REGISTER_LENSES_(type,...) \
auto static constexpr has_lenses = true; \
static inline auto all(type const& s) { \
    (void)(s); \
    return std::make_tuple(__VA_ARGS__); \
} \
template <class T> \
void Serialize(T& archive) \
{ \
    using chops::lenses::on_each; \
    on_each(*this, [&](auto& x) { archive & x; }); \
}