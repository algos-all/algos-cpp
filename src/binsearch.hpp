#include <iterator>
#include <iostream>

template<class RandomIt, typename T>
RandomIt binsearch(RandomIt fst, RandomIt lst, const T &v) {
    if (fst == lst)
        return lst;

    auto l = fst, r = lst - 1;

    while (l <= r) {
        const auto mid = std::next(l, std::distance(l, r) / 2);

        if (*mid == v) {
            return mid;
        }

        if (v < *mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return lst;
}
