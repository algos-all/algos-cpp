#define BOOST_TEST_MODULE test_esieve
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "esieve.hpp"

BOOST_AUTO_TEST_CASE(zero) {
    auto result = esieve(0);

    BOOST_TEST(result.size() == 0);
}

BOOST_AUTO_TEST_CASE(negative) {
    BOOST_CHECK_THROW(esieve(-42), std::bad_alloc);
}

BOOST_AUTO_TEST_CASE(one) {
    auto result = esieve(1);

    BOOST_TEST(result.size() == 1);
    BOOST_TEST(result[0] == 0);
}

BOOST_AUTO_TEST_CASE(two) {
    auto result = esieve(2);

    BOOST_TEST(result.size() == 2);
    BOOST_TEST(result[0] == 0);
    BOOST_TEST(result[1] == 0);
}

BOOST_AUTO_TEST_CASE(three) {
    auto result = esieve(3);

    BOOST_TEST(result.size() == 3);
    BOOST_TEST(result[0] == 0);
    BOOST_TEST(result[1] == 0);
    BOOST_TEST(result[2] == 2);
}

BOOST_AUTO_TEST_CASE(twenty_four) {
    auto result = esieve(24);

    BOOST_TEST(result.size() == 24);

    const auto primes = {2, 3, 7, 11, 13, 17, 19, 23};

    for (auto prime : primes) {
        BOOST_TEST(result[prime] == prime);
    }
}
