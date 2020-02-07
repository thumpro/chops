#include "catch.hpp"
#include <chops/maybe.hpp>
#include <array>

TEST_CASE("basic maybe monad functionality", "[maybe]") { 
    std::array<int, 5> v{1, 2, 3, 42, 5};

    SECTION("maybe might contain a value, processed as pipe-like") {
        // 42 is in the array, maybeFind will return just<int> = 42
        chops::maybeFind(std::begin(v), std::end(v), 42)
            | [](int& v) { v *= 2; /* modify maybe*/ }
            | [](int v) { return v * 2.1f; /* value semantics maybe */}
            | [](float f) { REQUIRE( f == Approx(176.399994) ); }
            && [](chops::maybe_error_t) {
                // This won't be executed because maybe contains value
                REQUIRE(1 == 2);
            };
    }

    SECTION("maybe might be empty, && error processing") {
        // 13 is not in the array, maybeFind will return nothing
        chops::maybeFind(std::begin(v), std::end(v), 13)
            | [](int& v) { v *= 2; /* modify maybe*/ }
            | [](int v) { return v * 2.1f; /* value semantics maybe */}
            | [](float f) { 
                (void)(f); // unused param
                // This won't be executed because maybe does not contain value
                REQUIRE(1 == 2); 
            }
            && [](chops::maybe_error_t) {
                // error handling lambda will be executed instead
                REQUIRE(1 == 1);
            };
    }
}