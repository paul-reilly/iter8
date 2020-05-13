#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../include/iter8.hpp"

TEST_CASE("general tests") {
    using vint = std::vector<int>;
    vint v{ 42, 1337, 666, 90210 };
    auto iter = iter8::Iter{ v };
    SUBCASE("while loop exits") {
        while (auto opt_val = iter.next()) {
            *opt_val += 1;
        }
    }
    SUBCASE("check that references are used and values are updated") {
        while (auto opt_val = iter.next()) {
            *opt_val += 1;
        }
        CHECK(v[0] == 43);
        CHECK(v[1] == 1338);
    }
    SUBCASE("check size is the same") {
        CHECK(v.size() == 4);
    }
    SUBCASE("check reset") {
        iter.reset();
        CHECK(*iter.next() == 42);
        CHECK(*iter.next() == 1337);
        iter.reset();
        CHECK(*iter.next() == 42);
    }
}
