#ifndef SRC_ESIEVE_HPP_
#define SRC_ESIEVE_HPP_

#include <map>
#include <cmath>
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

std::map<uint32_t, uint32_t> compute_primes(uint32_t n) {
    auto primes = std::map<uint32_t, uint32_t>();

    if (n == 0) {
        return primes;
    }

    uint32_t c = 0;

    for (; n % 2 == 0; n /= 2) {
        ++c;
    }

    if (c) {
        primes[2] = c;
    }

    for (uint32_t f = 3; f * f <= n; f += 2) {
        c = 0;
        for (; n % f == 0; n /= f) {
            ++c;
        }

        if (c) {
            primes[f] = c;
        }
    }

    if (n != 1) {
        primes[n] = 1;
    }

    return primes;
}

#endif  // SRC_ESIEVE_HPP_
