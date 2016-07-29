#define BOOST_TEST_MODULE test_quicksort
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "sort/quicksort.hpp"

BOOST_AUTO_TEST_CASE(empty_size) {
    vi xs = {};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 0);
}

BOOST_AUTO_TEST_CASE(one_element) {
    vi xs = {42};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 1);
    BOOST_TEST(xs[0] == 42);
}

BOOST_AUTO_TEST_CASE(two_elements_0) {
    vi xs = {41, 42};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST((xs[0] == 41 && xs[1] == 42));
}

BOOST_AUTO_TEST_CASE(two_elements_1) {
    vi xs = {42, 41};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST((xs[0] == 41 && xs[1] == 42));
}

BOOST_AUTO_TEST_CASE(two_elements_2) {
    vi xs = {42, 42};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST((xs[0] == 42 && xs[1] == 42));
}

BOOST_AUTO_TEST_CASE(two_elements_3) {
    vi xs = {-42, 42};

    quicksort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST((xs[0] == -42 && xs[1] == 42));
}

BOOST_DATA_TEST_CASE(
    random_qsort, bdata::xrange(1, 256) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    quicksort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    random_qsort_stress, bdata::make(1e4) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    quicksort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
