#ifndef SRC_ESIEVE_HPP_
#define SRC_ESIEVE_HPP_

#include <vector>

template <typename T>
std::vector<T> esieve(const T &n) {
    auto xs = std::vector<T>(n, 0);

    for (T i = 2; i < n; ++i) {
        if (xs[i] != 0) continue;

        for (T j = i; j < n; j += i) {
            xs[j] = i;
        }
    }

    return xs;
}

#endif  // SRC_ESIEVE_HPP_
