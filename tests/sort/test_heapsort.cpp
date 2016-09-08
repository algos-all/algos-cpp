#define BOOST_TEST_MODULE test_heapsort
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "sort/heapsort.hpp"

using bdata::make;

BOOST_AUTO_TEST_CASE(empty_size) {
    vi xs = {};

    heapsort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 0);
}

BOOST_AUTO_TEST_CASE(one_element) {
    vi xs = {42};

    heapsort(xs.begin(), xs.end());

    BOOST_TEST(xs.size() == 1);
    BOOST_TEST(xs[0] == 42);
}

BOOST_AUTO_TEST_CASE(pushheap0) {
    vi xs = {};

    for (auto i = 10; i != 0; --i) {
        xs.push_back(i);

        pushheap(xs.begin(), xs.end());
    }

    BOOST_TEST(std::is_heap(xs.begin(), xs.end(), std::greater<>{}));
}

BOOST_DATA_TEST_CASE(
    pushheap_random_0, bdata::xrange(1, 256) * bdata::xrange(100), n, s
) {
    vi xs = create_vector(n, s);

    for (auto it = xs.begin(); it != xs.end(); ++it) {
        pushheap(xs.begin(), it);
    }

    BOOST_TEST(std::is_heap(xs.begin(), xs.end(), std::greater<>{}));
}

BOOST_DATA_TEST_CASE(
    pushheap_random_1, bdata::xrange(1, 256) * bdata::xrange(100), n, s
) {
    vi xs = create_vector(14, 0);

    for (auto it = xs.begin(); it <= xs.end(); ++it) {
        pushheap(xs.begin(), it, std::greater<int>{});
    }

    // for (auto x: xs) {std::cerr << x << " ";} std::cerr << std::endl;

    BOOST_TEST(std::is_heap(xs.begin(), xs.end(), std::less<int>{}));
}

BOOST_DATA_TEST_CASE(
    two_elements_0,
    make({41, 42}) * make({41, 42}),
    a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    heapsort(xs.begin(), xs.end());
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

    heapsort(xs.begin(), xs.end());
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

    heapsort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == 3);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    random_heapsort, bdata::xrange(1, 256) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    heapsort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

BOOST_DATA_TEST_CASE(
    random_heapsort_stress, bdata::make(1e4) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);
    vi ys = xs;

    heapsort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    BOOST_TEST(xs.size() == ys.size());
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
