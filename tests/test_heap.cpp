#define BOOST_TEST_MODULE test_heap
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "heap.hpp"

template <typename Iterator>
bool is_valid_heap(const Iterator begin, const Iterator end) {
    for (auto i = begin; i != end; ++i) {
        auto lchild = i + 2 * std::distance(begin, i) + 1;
        auto rchild = i + 2 * std::distance(begin, i) + 2;

        if (lchild <= end) {
            if (*i > *lchild) {return false;}
        }
        if (rchild <= end) {
            if (*i > *rchild) {return false;}
        }
    }

    return true;
}

BOOST_AUTO_TEST_CASE(empty_0) {
    auto heap = Heap<int>();

    BOOST_TEST(heap.size() == 0);
}

BOOST_AUTO_TEST_CASE(empty_1) {
    auto heap = Heap<int, std::greater<int>>();

    BOOST_TEST(heap.size() == 0);
}

BOOST_AUTO_TEST_CASE(heap_0) {
    auto heap = Heap<int>();

    heap.push(1);
    heap.push(2);
    heap.push(3);

    BOOST_TEST(is_valid_heap(heap.begin(), heap.end()) == true);
}

BOOST_AUTO_TEST_CASE(heap_1) {
    auto heap = Heap<int>();

    heap.push(3);
    heap.push(2);
    heap.push(1);

    BOOST_TEST(is_valid_heap(heap.begin(), heap.end()) == true);
}

BOOST_AUTO_TEST_CASE(top_0) {
    auto heap = Heap<int>({42});

    BOOST_TEST(heap.top() == 42);
}

BOOST_AUTO_TEST_CASE(top_1) {
    auto heap = Heap<int, std::greater<int>>({42});

    BOOST_TEST(heap.top() == 42);
}

BOOST_AUTO_TEST_CASE(top_2) {
    auto heap = Heap<int>({43, 42});

    BOOST_TEST(heap.top() == 42);
}

BOOST_AUTO_TEST_CASE(top_3) {
    auto heap = Heap<int, std::greater<int>>({43, 42});

    BOOST_TEST(heap.top() == 43);
}

BOOST_AUTO_TEST_CASE(pop_0) {
    vi xs = {44, 43, 42, 41, 40};
    auto heap = Heap<int>(xs);

    std::sort(xs.begin(), xs.end());

    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }

    BOOST_TEST(heap.size() == 0);
}

BOOST_AUTO_TEST_CASE(pop_1) {
    vi xs = {44, 43, 42, 41, 40};
    auto heap = Heap<int, std::greater_equal<int>>(xs);

    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }

    BOOST_TEST(heap.size() == 0);
}

vi lengths0 = {9, 10, 15, 18, 100, 1000};

BOOST_DATA_TEST_CASE(
    pop_2, bdata::make(lengths0) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto heap = Heap<int>(xs);

    std::sort(xs.begin(), xs.end());
    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }

    BOOST_TEST(heap.size() == 0);
}

BOOST_DATA_TEST_CASE(
    pop_3, bdata::make(lengths0) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto heap = Heap<int, std::greater<int>>(xs);

    std::sort(xs.begin(), xs.end(), std::greater<int>());
    for (auto x : xs) {
        BOOST_TEST(x == heap.top());
        heap.pop();
    }

    BOOST_TEST(heap.size() == 0);
}

vi lengths1 = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 15, 17, 18, 19, 20, 21, 22,
    25, 28, 29, 30, 32, 33, 50, 59, 60, 65,
    100, 1000, 10000, 100000
};

BOOST_DATA_TEST_CASE(
    random_sort_0, bdata::make(lengths1) * bdata::xrange(10), n, s
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

BOOST_DATA_TEST_CASE(
    random_sort_1, bdata::make(lengths1) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto heap = Heap<int, std::greater<int>>(xs);

    vi ys = heap.sort();

    BOOST_TEST(xs.size() == ys.size());

    std::sort(xs.begin(), xs.end());

    for (typename vi::size_type i = 0; i < xs.size(); ++i) {
        BOOST_TEST(xs[i] == ys[i]);
    }

    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}
