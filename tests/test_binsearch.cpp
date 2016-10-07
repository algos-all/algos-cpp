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

vi lengths = {9, 10, 11, 41, 42, 43, 50, 99, 100, 101, 10000};

BOOST_DATA_TEST_CASE(
    random_len_100, bdata::make(lengths) * bdata::xrange(100), n, s
) {
    vi xs = {1, 2, 3};
    vi ys = {4, 5, 6};

    vi zs = create_vector(n, s, xs, ys);

    std::sort(zs.begin(), zs.end());

    for (auto x : xs) {
        BOOST_TEST((binsearch(zs.begin(), zs.end(), x) == zs.end()));
    }

    for (auto y : ys) {
        const auto result = binsearch(zs.begin(), zs.end(), y);
        BOOST_TEST((result != zs.end()));
        BOOST_TEST(*result == y);
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
