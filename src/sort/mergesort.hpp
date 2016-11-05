#include <iterator>
#include <algorithm>
#include <functional>


namespace detail {
template<class RandomIt, class Key=std::less<>>
void mergesort0(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst || std::next(fst) == lst) return;

    auto mid = std::next(fst, std::distance(fst, lst) / 2);

    mergesort0(fst, mid, key);
    mergesort0(mid, lst, key);

    std::inplace_merge(fst, mid, lst, key);
}

template<class RandomIt, class Key=std::less<>>
void mergesort1(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst || std::next(fst) == lst) return;

    const auto dst = std::distance(fst, lst);

    auto mid = std::next(fst, dst / 2);

    mergesort1(fst, mid, key);
    mergesort1(mid, lst, key);

    std::vector<
        typename std::iterator_traits<RandomIt>::value_type
    > tmp(fst, lst);

    mid = std::next(tmp.begin(), dst / 2);
    std::merge(tmp.begin(), mid, mid, tmp.end(), fst, key);
}
} // namespace detail


template<class RandomIt, class Key=std::less<>>
void mergesort0(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst) return;

    detail::mergesort0(fst, lst, key);
}

template<class RandomIt, class Key=std::less<>>
void mergesort1(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst) return;

    detail::mergesort1(fst, lst, key);
}
