#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../include/iter8.hpp"

TEST_CASE("while loop using next") {
    using vint = std::vector<int>;
    vint v{ 42, 1337, 666, 90210 };
    auto iter = iter8::Iter{ v };

    while (auto opt_val = iter.next()) {
        *opt_val += 1;
    }
    CHECK(v[0] == 43);
    CHECK(v[1] == 1338);
    CHECK(v.size() == 4);
    CHECK(*iter.next() == 43);
    iter.next();
    iter.reset();
    CHECK(*iter.next() == 43);

}
