#define BOOST_TEST_MODULE test_heap
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "heap.hpp"

BOOST_AUTO_TEST_CASE(empty_size_0) {
    auto heap = Heap<int>();

    BOOST_TEST(heap.size() == 0);
}

BOOST_AUTO_TEST_CASE(top_1) {
    auto heap = Heap<int>({42});

    BOOST_TEST(heap.top() == 42);
}

BOOST_AUTO_TEST_CASE(top_2) {
    auto heap = Heap<int>({43, 42});

    BOOST_TEST(heap.top() == 42);
}

BOOST_AUTO_TEST_CASE(pop_0) {
    vi xs = {44, 43, 42, 41, 40};
    auto heap = Heap<int>(xs);

    std::sort(xs.begin(), xs.end());

    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }
}

BOOST_DATA_TEST_CASE(
    pop_1, bdata::make({9, 10, 15, 18, 100, 1000}) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto heap = Heap<int>(xs);

    std::sort(xs.begin(), xs.end());
    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }
}

vi lengths = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 15, 17, 18, 19, 20, 21, 22,
    25, 28, 29, 30, 32, 33, 50, 59, 60, 65,
    100, 1000, 10000, 100000
};

BOOST_DATA_TEST_CASE(
    random_sort, bdata::make(lengths) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto heap = Heap<int>(xs);

    vi ys = heap.sort();

    BOOST_TEST(xs.size() == ys.size());

    std::sort(xs.begin(), xs.end(), std::greater<int>());

    for (typename vi::size_type i = 0; i < xs.size(); ++i) {
        BOOST_TEST(xs[i] == ys[i]);
    }

    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
