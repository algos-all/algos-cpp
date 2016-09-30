#include <iterator>
#include <algorithm>
#include <functional>


namespace detail {
template<class RandomIt, class Key=std::less<>>
void mergesort0(RandomIt ix, RandomIt iy, Key key=Key{}) {
    if (ix == iy || std::next(ix) == iy) {
        return;
    }

    auto mid = std::next(ix, std::distance(ix, iy) / 2);

    mergesort0(ix, mid, key);
    mergesort0(mid, iy, key);

    std::inplace_merge(ix, mid, iy, key);
}

template<class RandomIt, class Key=std::less<>>
void mergesort1(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst || std::next(fst) == lst) return;

    auto mid = std::next(fst, std::distance(fst, lst) / 2);

    mergesort1(fst, mid, key);
    mergesort1(mid, lst, key);

    std::vector<
        typename std::iterator_traits<RandomIt>::value_type
    > tmp(fst, lst);

    mid = std::next(tmp.begin(), std::distance(fst, lst) / 2);
    std::merge(tmp.begin(), mid, mid, tmp.end(), fst, key);
}
} // namespace detail


template<class RandomIt, class Key=std::less<>>
void mergesort0(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin >= end) return;

    detail::mergesort0(begin, end, key);
}

template<class RandomIt, class Key=std::less<>>
void mergesort1(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin >= end) return;

    detail::mergesort1(begin, end, key);
}
