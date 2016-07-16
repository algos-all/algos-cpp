#include <vector>

template <typename T>
std::vector<T> esieve(const T &n) {
    auto primes = std::vector<T>(n, 0);

    for (T i = 2; i < n; ++i) {
        if (primes[i] != 0) {continue;}

        for (T j = i; j < n; j += i) {
            primes[j] = i;
        }
    }

    return primes;
}
