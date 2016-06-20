#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

namespace bdata = boost::unit_test::data;

using vi = std::vector<int>;
using uint = std::uint32_t;

vi create_vector(uint n, uint s, vi xs, vi ys, uint lo, uint hi) {
    std::mt19937 engine(s);
    std::uniform_int_distribution<> uniform(lo, hi);

    vi zs(n - ys.size());

    for (uint32_t i = 0; i < n - ys.size(); ++i) {
        auto z = uniform(engine);
        while (std::find(xs.begin(), xs.end(), z) != xs.end()) {
            z = uniform(engine);
        }

        zs[i] = z;
    }

    zs.insert(zs.end(), ys.begin(), ys.end());

    std::sort(zs.begin(), zs.end());

    return zs;
}

vi create_vector(uint n, uint s, vi xs, vi ys) {
    return create_vector(n, s, xs, ys, -127, 127);
}

vi create_vector(uint n, uint s) {
    return create_vector(n, s, {}, {});
}
