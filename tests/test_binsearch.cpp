#define BOOST_TEST_MODULE test_binsearch
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "binsearch.hpp"

BOOST_AUTO_TEST_CASE(empty_0) {
    const vi xs = {};

    const auto result = binsearch(xs.begin(), xs.end(), 42);

    BOOST_TEST((result == xs.end()));
}

BOOST_AUTO_TEST_CASE(single_hit_0) {
    const vi xs = {2};

    const auto result = binsearch(xs.begin(), xs.end(), 2);

    BOOST_TEST((result == xs.begin()));
    BOOST_TEST(*result == 2);
}

BOOST_AUTO_TEST_CASE(single_lmiss_0) {
    const vi xs = {2};

    const auto result = binsearch(xs.begin(), xs.end(), 1);

    BOOST_TEST((result == xs.end()));
}

BOOST_AUTO_TEST_CASE(single_rmiss_0) {
    const vi xs = {2};

    const auto result = binsearch(xs.begin(), xs.end(), 3);

    BOOST_TEST((result == xs.end()));
}

BOOST_AUTO_TEST_CASE(big_bool) {
    const auto sz = std::numeric_limits<uint>::max();

    try {
        std::vector<bool> xs(sz, false);

        const auto result0 = binsearch(xs.begin(), xs.end(), true);

        BOOST_TEST((result0 == xs.end()));

        *(xs.end() - 1) = true;

        const auto result1 = binsearch(xs.begin(), xs.end(), true);

        BOOST_TEST((result1 == xs.end() - 1));
    } catch (const std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
}

vi lengths = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 23, 30, 35, 37, 38, 40, 41, 42, 43,
    50, 51, 51, 57, 59, 60, 64, 68, 70, 73,
    75, 76, 77, 83, 84, 92, 93, 94, 98, 99,
    100, 101, 111, 121, 123, 128, 129, 149,
    10000, 10115, 10223, 10583, 15877, 20000
};

BOOST_DATA_TEST_CASE(
    random_100_retries, bdata::make(lengths) * bdata::xrange(100), n, s
) {
    vi xs = create_vector(n, s);

    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    auto fst = xs.begin(), lst = xs.end();

    for (auto x: xs) {
        BOOST_TEST(
            (binsearch(fst, lst, x) == std::lower_bound(fst, lst, x))
        );
    }

    vi ys = create_vector(100, s + 1);

    for (auto y: ys) {
        const auto t = std::lower_bound(fst, lst, y);

        if (*t == y) {
            BOOST_TEST((*binsearch(fst, lst, y) == y));
        } else {
            BOOST_TEST((binsearch(fst, lst, y) == lst));
        }
    }
}

BOOST_DATA_TEST_CASE(
    lb_100_retries, bdata::make(lengths) * bdata::xrange(100), n, s
) {
    vi xs = create_vector(n, s);

    std::sort(xs.begin(), xs.end());

    auto fst = xs.begin();
    auto lst = xs.end();

    for (auto x: xs) {
        xlower_bound(fst, lst, x) == std::lower_bound(fst, lst, x);
    }

    vi ys = create_vector(100, s + 1);

    for (auto y: ys) {
        xlower_bound(fst, lst, y) == std::lower_bound(fst, lst, y);
    }
}

BOOST_DATA_TEST_CASE(
    ub_100_retries, bdata::make(lengths) * bdata::xrange(100), n, s
) {
    vi xs = create_vector(n, s);

    std::sort(xs.begin(), xs.end());

    auto fst = xs.begin();
    auto lst = xs.end();

    for (auto x: xs) {
        xupper_bound(fst, lst, x) == std::upper_bound(fst, lst, x);
    }

    vi ys = create_vector(100, s + 1);

    for (auto y: ys) {
        xupper_bound(fst, lst, y) == std::upper_bound(fst, lst, y);
    }
}

BOOST_AUTO_TEST_CASE(swapped_iterators_0) {
    vi xs = {1, 2, 3, 4, 5};

    BOOST_TEST((binsearch(xs.end(), xs.begin(), 0) == xs.begin()));
    BOOST_TEST((binsearch(xs.begin()+3, xs.end()-3, 0) == xs.end()-3));
}

BOOST_AUTO_TEST_CASE(swapped_iterators_1) {
    vi xs = {1, 2, 3, 4, 5};

    BOOST_TEST((binsearch(xs.end(), xs.begin(), 1) == xs.begin()));
    BOOST_TEST((binsearch(xs.begin()+3, xs.end()-3, 1) == xs.end()-3));
}
