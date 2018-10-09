#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "rational.h"
#include <sstream>

TEST_CASE("creation")
{
    rational r1;
    rational r2(1);
    rational r3(2, 3);
    rational r4{4};
    rational r5{5, 6};
    CHECK(((r1.num() == 0) && (r1.den() == 1)));
    CHECK(((r2.num() == 1) && (r2.den() == 1)));
    CHECK(((r3.num() == 2) && (r3.den() == 3)));
    CHECK(((r4.num() == 4) && (r4.den() == 1)));
    CHECK(((r5.num() == 5) && (r5.den() == 6)));
}

TEST_CASE("gcd")
{
    rational r1(1, 2);
    rational r2(2, 4);
    CHECK(((r1.num() == r2.num()) && (r1.den() == r2.den())));
}

TEST_CASE("copying and assignment")
{
    rational r(1, 2);
    rational r1(r);
    rational r2; r2 = r;
    CHECK(((r1.num() == 1) && (r1.den() == 2)));
    CHECK(((r2.num() == 1) && (r2.den() == 2)));
}

TEST_CASE("conversion")
{
    rational r1(1, 2);
    r1 = 2;
    CHECK(((r1.num() == 2) && (r1.den() == 1)));
    rational r2(22, 7);
    CHECK(static_cast<int>(r2) == 3);
    CHECK(static_cast<double>(r2) == doctest::Approx(3.141).epsilon(.01));
}

TEST_SUITE_BEGIN("operators");

TEST_CASE("boolean")
{
    rational r1(1, 2), r2(3, 4), r3(2, 4);
    CHECK(r1 != r2);
    CHECK(r1 == r3);
    CHECK(r1 < r2);
    CHECK(r2 > r3);
    CHECK(r1 <= r3);
    CHECK(r1 >= r3);
}

TEST_CASE("arithmetic")
{
    rational r1(1, 2), r2(3, 4);
    CHECK((r1 + r2) == rational(5, 4));
    CHECK((r2 - r1) == rational(1, 4));
    CHECK((r1 * r2) == rational(3, 8));
    CHECK((r1 / r2) == rational(2, 3));
}

TEST_CASE("io")
{
    rational r1(1, 2), r2(3, 4);
    std::ostringstream osstr;
    osstr << r1 + r2;
    CHECK(osstr.str() == "5/4");
    std::istringstream isstr;
    isstr.str("5/10");
    isstr >> r2;
    CHECK(r2 == rational(1, 2));
}

TEST_SUITE_END();
