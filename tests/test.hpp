#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <vector>
#include <random>
#include <limits>
#include <cassert>
#include <iostream>
#include <algorithm>

namespace bdata = boost::unit_test::data;

using vi = std::vector<int>;
using uint = std::uint32_t;

/**
 * Create a length-n vector<int> of random integers, use seed s;
 * Optional:
 *  Exclude all integers, if any, specified in xs
 *  Include all integers, if any, specified in ys
 *  Use random integers from the range [lo, hi)
 */
vi create_vector(uint n, uint s, vi xs, vi ys, int lo, int hi) {
    assert(n >= ys.size());

    std::mt19937 engine(s);
    std::uniform_int_distribution<> uniform(lo, hi);

    vi zs(n - ys.size());

    for (uint i = 0; i < n - ys.size(); ++i) {
        auto z = uniform(engine);

        while (std::find(xs.begin(), xs.end(), z) != xs.end()) {
            z = uniform(engine);
        }

        zs[i] = z;
    }

    zs.insert(zs.end(), ys.begin(), ys.end());

    return zs;
}

vi create_vector(uint n, uint s, vi xs, vi ys) {
    auto l = std::numeric_limits<int>::min();
    auto h = std::numeric_limits<int>::max();
    return create_vector(n, s, xs, ys, l, h);
}

vi create_vector(uint n, uint s) {
    return create_vector(n, s, {}, {});
}

bool equal_contents(vi xs, vi ys) {
    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());

    return std::equal(xs.begin(), xs.end(), ys.begin(), ys.end());
}
