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

BOOST_AUTO_TEST_CASE(compute_primes_0) {
    auto primes = compute_primes(0);

    BOOST_TEST(primes.size() == 0);
}

BOOST_AUTO_TEST_CASE(compute_primes_1) {
    auto primes = compute_primes(1);

    BOOST_TEST(primes.size() == 0);
}

BOOST_AUTO_TEST_CASE(compute_primes_2) {
    auto primes = compute_primes(2);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[2] == 1);
}

BOOST_AUTO_TEST_CASE(compute_primes_3) {
    auto primes = compute_primes(3);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[3] == 1);
}

BOOST_AUTO_TEST_CASE(compute_primes_4) {
    auto primes = compute_primes(4);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[2] == 2);
}

BOOST_AUTO_TEST_CASE(compute_primes_6) {
    auto primes = compute_primes(6);

    BOOST_TEST(primes.size() == 2);
    BOOST_TEST(primes[2] == 1);
    BOOST_TEST(primes[3] == 1);
}

BOOST_AUTO_TEST_CASE(compute_primes_7) {
    auto primes = compute_primes(7);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[7] == 1);
}

BOOST_AUTO_TEST_CASE(compute_primes_8) {
    auto primes = compute_primes(8);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[2] == 3);
}

BOOST_AUTO_TEST_CASE(compute_primes_9) {
    auto primes = compute_primes(9);

    BOOST_TEST(primes.size() == 1);
    BOOST_TEST(primes[3] == 2);
}
