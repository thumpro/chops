#include "catch.hpp"
#include <chops/variant.hpp>

TEST_CASE("basic variant functionality", "[fund]") { 
    chops::variant<int, std::string> v{std::string("foo")};

    SECTION("variants support std::get like access, returning pointer") {
        REQUIRE(*v.get<std::string>() == std::string("foo"));
    }

    SECTION("variants can be reassigned like unions") {
        v = 10;
        REQUIRE(*v.get<int>() == 10);
    }

    SECTION("get can be used for conditional comparisons") {
        v = 10;
        REQUIRE_FALSE(v.get<std::string>());
    }

    SECTION("variants support basic visitation") {
        v = 10;
        struct formatter {
            std::string operator()(const std::string & s) const { return s; }
            std::string operator()(int i) const { return "[" + std::to_string(i) + "]"; }
        };

        REQUIRE(v.visit(formatter{}) == std::string("[10]"));
    }

    SECTION("variants support overload-style modern visitation") {
        v = 10;
        std::string res = v.visit(overload{[](int i) -> std::string { return std::to_string(i); },
                                           [](std::string s) -> std::string { return s; }
        });
        REQUIRE(res == std::string("10"));
    }
}