#ifndef INVERSIONS_H_
#define INVERSIONS_H_

#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>

namespace detail {
// Count the number of inversions in a collection. The underlying algorithm is
// merge sort, so the collection becomes sorted as a side effect.
template<typename RandomIt, typename Key=std::less<>>
uint64_t inversions(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (std::next(fst) == lst) {
        return 0;  // There is just one element, so there are zero inversions.
    }

    uint64_t total_inversions = 0;
    auto mid = std::next(fst, std::distance(fst, lst) / 2);

    total_inversions += inversions(fst, mid, key);
    total_inversions += inversions(mid, lst, key);

    auto tmp = std::vector<
        typename std::iterator_traits<RandomIt>::value_type
    >(fst, lst);

    auto lft = fst, rgt = mid, dst = tmp.begin();
    while (lft != mid && rgt != lst) {
        if (key(*lft, *rgt)) {
            *dst = *lft;

            lft = std::next(lft);
        } else {
            *dst = * rgt;

            total_inversions += std::distance(lft, mid);

            rgt = std::next(rgt);
        }

        dst = std::next(dst);
    }

    if (lft == mid) {
        std::copy(rgt, lst, dst);
    } else {
        std::copy(lft, mid, dst);
    }

    std::copy(tmp.begin(), tmp.end(), fst);

    return total_inversions;
}
}

template<typename RandomIt, typename Key=std::less<>>
uint64_t inversions(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst) {
        return 0;
    }

    return detail::inversions(fst, lst, key);
}

#endif  // INVERSIONS_H_
