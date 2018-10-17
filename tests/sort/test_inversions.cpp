#define BOOST_TEST_MODULE test_inversions
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "sort/inversions.hpp"


BOOST_AUTO_TEST_CASE(hello) {
    std::vector<int> xs = {};

    BOOST_TEST(inversions(xs.begin(), xs.end()) == 0);

    BOOST_TEST(inversions(xs.begin(), xs.end(), std::less<>()) == 0);
    BOOST_TEST(inversions(xs.begin(), xs.end(), std::greater<>()) == 0);
}

BOOST_AUTO_TEST_CASE(single_element) {
    std::vector<int> xs = {42};

    BOOST_TEST(inversions(xs.begin(), xs.end()) == 0);

    BOOST_TEST(inversions(xs.begin(), xs.end(), std::less<>()) == 0);
    BOOST_TEST(inversions(xs.begin(), xs.end(), std::greater<>()) == 0);
}

BOOST_AUTO_TEST_CASE(two_elements_0) {
    std::vector<int> xs = {41, 42};

    BOOST_TEST(inversions(xs.begin(), xs.end()) == 0);

    BOOST_TEST(inversions(xs.begin(), xs.end(), std::less<>()) == 0);
    BOOST_TEST(inversions(xs.begin(), xs.end(), std::greater<>()) == 1);
}

BOOST_AUTO_TEST_CASE(two_elements_1) {
    std::vector<int> xs = {42, 41}, ys;

    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end()) == 1);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::less<>()) == 1);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::greater<>()) == 0);
}

BOOST_AUTO_TEST_CASE(three_elements_0) {
    std::vector<int> xs = {41, 42, 43}, ys;

    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end()) == 0);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::less<>()) == 0);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::greater<>()) == 3);
}

BOOST_AUTO_TEST_CASE(five_elements_0) {
    std::vector<int> xs = {2, 4, 5, 1, 3}, ys;

    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end()) == 5);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::less<>()) == 5);
    ys = xs;
    BOOST_TEST(inversions(ys.begin(), ys.end(), std::greater<>()) == 5);
}
