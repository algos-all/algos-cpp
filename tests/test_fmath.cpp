#define BOOST_TEST_MODULE test_fmath
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "fmath.hpp"

BOOST_AUTO_TEST_CASE(gcf00) {
    BOOST_TEST(gcf(0, 0) == 0);
}

BOOST_AUTO_TEST_CASE(gcf10) {
    BOOST_TEST(gcf(1, 0) == 1);
}

BOOST_AUTO_TEST_CASE(gcf01) {
    BOOST_TEST(gcf(0, 1) == 1);
}

BOOST_AUTO_TEST_CASE(gcf11) {
    BOOST_TEST(gcf(1, 1) == 1);
}

BOOST_AUTO_TEST_CASE(gcf02) {
    BOOST_TEST(gcf(0, 2) == 2);
    BOOST_TEST(gcf(2, 0) == 2);
    BOOST_TEST(gcf(2, 2) == 2);
}

BOOST_AUTO_TEST_CASE(gcf42) {
    BOOST_TEST(gcf(2, 4) == 2);
    BOOST_TEST(gcf(4, 2) == 2);
}

BOOST_AUTO_TEST_CASE(gcf2n) {
    for (int i = 2; i != 1024; i *= 2) {
        BOOST_TEST(gcf(i, 1) == 1);
        BOOST_TEST(gcf(i, 2) == 2);
        BOOST_TEST(gcf(i, 1024) == i);

        BOOST_TEST(gcf(1, i) == 1);
        BOOST_TEST(gcf(2, i) == 2);
        BOOST_TEST(gcf(1024, i) == i);
    }
}

BOOST_AUTO_TEST_CASE(gcf_primes) {
    for (int t = 2; t != 10000; ++t) {
        if (t % 13 == 0) {
            BOOST_TEST(gcf(t, 13) == 13);
        } else {
            BOOST_TEST(gcf(t, 13) == 1);
        }

        if (t % 97 == 0) {
            BOOST_TEST(gcf(t, 97) == 97);
        } else {
            BOOST_TEST(gcf(t, 97) == 1);
        }
    }
}

BOOST_AUTO_TEST_CASE(xgcf00) {
    const auto result = xgcf(0, 0);

    BOOST_TEST(result[0] == 0);
    BOOST_TEST(result[1] == 1);
    BOOST_TEST(result[2] == 0);
}

BOOST_DATA_TEST_CASE(xgcf_random, bdata::make(100), i) {
    std::mt19937 engine(i);
    std::uniform_int_distribution<> uniform(-1'000'000, 1'000'000);

    const auto x = uniform(engine);
    const auto y = uniform(engine);

    const auto result = xgcf(x, y);

    BOOST_TEST(result[0] == result[1] * x + result[2] * y);
}
