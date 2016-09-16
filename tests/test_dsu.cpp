#define BOOST_TEST_MODULE test_dsu
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "dsu.hpp"

using bdata::make;
using bdata::xrange;


BOOST_AUTO_TEST_CASE(one) {
    auto dsu = DisjointSetUnion<int>();

    dsu.push_back(1);

    BOOST_TEST(dsu.xs[1] == 1);
    BOOST_TEST(dsu.ws[1] == 1);
}

BOOST_AUTO_TEST_CASE(two) {
    auto dsu = DisjointSetUnion<int>();

    dsu.push_back(1);
    dsu.push_back(2);

    BOOST_TEST(dsu.xs[1] == 1);
    BOOST_TEST(dsu.ws[1] == 1);

    BOOST_TEST(dsu.xs[2] == 2);
    BOOST_TEST(dsu.ws[2] == 1);
}

BOOST_AUTO_TEST_CASE(unite2) {
    auto dsu = DisjointSetUnion<int>({1, 2});

    dsu.unite(1, 2);

    BOOST_TEST((dsu.find(1) == dsu.find(2)));
}

BOOST_DATA_TEST_CASE(unite_all_0, xrange(2, 256) * xrange(10), n, s) {
    auto xs = create_vector(n, s);

    auto dsu = DisjointSetUnion<int>(xs.begin(), xs.end());

    for (auto i = 1; i < n; ++i) {
        dsu.unite(xs[0], xs[i]);
    }

    for (auto i = 1; i < n; ++i) {
        BOOST_TEST((dsu.find(xs[0]) == dsu.find(xs[i])));
    }
}

BOOST_DATA_TEST_CASE(unite_all_1, xrange(2, 256) * xrange(10), n, s) {
    auto xs = create_vector(n, s);

    auto dsu = DisjointSetUnion<int>(xs.begin(), xs.end());

    for (auto i = 1; i < n; ++i) {
        dsu.unite(xs[i - 1], xs[i]);
    }

    for (auto i = 1; i < n; ++i) {
        BOOST_TEST((dsu.find(xs[0]) == dsu.find(xs[i])));
    }
}


BOOST_DATA_TEST_CASE(check_xs_ys, xrange(2, 256) * xrange(10), n, s) {
    auto xs = create_vector(n, s);
    auto ys = xs;

    auto engine = std::default_random_engine{};
    std::shuffle(ys.begin(), ys.end(), engine);

    auto dsu = DisjointSetUnion<int>(xs.begin(), xs.end());

    for (auto i = 0; i < n; ++i) {
        dsu.unite(xs[i], ys[i]);
    }

    for (auto i = 0; i < n; ++i) {
        BOOST_TEST((dsu.find(xs[i]) == dsu.find(ys[i])));
    }
}
