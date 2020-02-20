#include "catch.hpp"
#include <chops/lenses.hpp>
#include <chops/archive.hpp>
#include <sstream>

struct job {
    // add constexpr has_lenses
    std::string position_;
    float salary_;
    MAKE_LENSE(job, position, salary)
};

struct person {
    std::string name_;
    job work_;
    MAKE_LENSE(person, name, work)
};

TEST_CASE("basic lense functionality", "[lenses]") {
    int n = VA_NARGS(a,b,c,d,e,f,g,h,i,j,k,l);
    REQUIRE(n == 12);
    auto t = std::make_tuple(STRINGIFY_VA(foo, bar, baz));
    REQUIRE(std::get<0>(t) == std::string_view{"foo"});
    REQUIRE(std::get<1>(t) == std::string_view{"bar"});
    REQUIRE(std::get<2>(t) == std::string_view{"baz"});
    
    using chops::lenses::view;
    using chops::lenses::set;
    using chops::lenses::operator*;
    using chops::lenses::visit_each;

    person p{"john", job{"architect", 3.14f}};
    // look over and view the name
    REQUIRE(p * person::name * view == std::string("john"));

    //change the position
    REQUIRE(p * person::work * job::position * view == std::string("architect"));
    REQUIRE(set(p * person::work * job::position, "programmer") * view == std::string("programmer"));

    // or filter on all the members of a struct, results are in a tuple
    auto r = visit_each(p, [](auto const& x) { return sizeof(x) > 16; });
    // r is std::tuple<bool, bool>
    REQUIRE(std::get<0>(r)); // std::string member has size 32 on gcc, 40 on msvc...
    REQUIRE(std::get<1>(r)); // job member has size 40

    // or serialize through lenses, any struct embelished with MAKE_LENSE macro
    // is serializable to any stream class like stringstream, filestream etc.
    std::stringstream s;
    chops::serialization::archive<std::stringstream> a(s);
    a << p; // serialize
    person pc;
    a >> pc; // deserialize
    REQUIRE(pc * person::work * job::position * view == std::string("programmer"));
}