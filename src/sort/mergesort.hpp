#ifndef SRC_SORT_MERGESORT_HPP_
#define SRC_SORT_MERGESORT_HPP_

#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>


namespace detail {
template<class RandomIt, class Key = std::less<>>
void mergesort0(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst || std::next(fst) == lst) {
        return;
    }

    auto mid = std::next(fst, std::distance(fst, lst) / 2);

    mergesort0(fst, mid, key);
    mergesort0(mid, lst, key);

    std::inplace_merge(fst, mid, lst, key);
}

template<class RandomIt, class Key = std::less<>>
void mergesort1(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst || std::next(fst) == lst) {
        return;
    }

    const auto dst = std::distance(fst, lst);

    auto mid = std::next(fst, dst / 2);

    mergesort1(fst, mid, key);
    mergesort1(mid, lst, key);

    std::vector<
        typename std::iterator_traits<RandomIt>::value_type
    >tmp(fst, lst);

    mid = std::next(tmp.begin(), dst / 2);
    std::merge(tmp.begin(), mid, mid, tmp.end(), fst, key);
}

template<typename RandomIt, typename Key = std::less<>>
void mergesort2(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst || std::next(fst) == lst) {
        // fst == lst is possible only when this function is:
        // 1) directly called by something from the outside
        // 2) that caller decided to pass an empty container
        return;  // no elements or one element to sort => already sorted
    }

    auto mid = std::next(fst, std::distance(fst, lst) / 2);

    mergesort2(fst, mid, key);
    mergesort2(mid, lst, key);

    auto tmp = std::vector<
        typename std::iterator_traits<RandomIt>::value_type
    >(fst, lst);

    auto lft = fst, rgt = mid, dst = tmp.begin();

    while (lft != mid && rgt != lst) {
        if (key(*lft, *rgt)) {
            *dst = *lft;

            lft = std::next(lft);
        } else {
            *dst = *rgt;

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
}
}  // namespace detail


template<class RandomIt, class Key = std::less<>>
void mergesort0(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) return;

    detail::mergesort0(fst, lst, key);
}

template<class RandomIt, class Key = std::less<>>
void mergesort1(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) {
        return;
    }

    detail::mergesort1(fst, lst, key);
}

template<typename RandomIt, typename Key = std::less<>>
void mergesort2(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) {
        return;
    }

    detail::mergesort2(fst, lst, key);
}

#endif  // SRC_SORT_MERGESORT_HPP_
