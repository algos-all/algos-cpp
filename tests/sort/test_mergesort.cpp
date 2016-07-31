#define BOOST_TEST_MODULE test_mergesort
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "sort/mergesort.hpp"

using bdata::make;

BOOST_AUTO_TEST_CASE(empty_size) {
    vi xs = {};

    mergesort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 0);
}

BOOST_AUTO_TEST_CASE(one_element) {
    vi xs = {42};

    mergesort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 1);
    BOOST_TEST(xs[0] == 42);
}

BOOST_DATA_TEST_CASE(
    two_elements_0,
    make({41, 42}) * make({41, 42}),
    a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    mergesort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    two_elements_1,
    make(create_vector(10, 1)) * make(create_vector(10, 2)),
    a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    mergesort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    three_elements,
    make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ) * make(
        create_vector(10, 3)
    ),
    a, b, c
) {
    vi xs = {a, b, c};
    vi ys = xs;

    mergesort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == 3);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    random_mergesort, bdata::xrange(1, 256) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    mergesort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    random_mergesort_stress, bdata::make(1e4) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    mergesort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
