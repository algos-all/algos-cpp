#include <random>
#include <iterator>
#include <algorithm>
#include <functional>

namespace detail {
using gen = std::mt19937;
using uid = std::uniform_int_distribution<>;

gen g(42);

template<class RandomIt, class Key=std::less<>>
void quicksort0(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst >= lst) return;

    auto lft = fst;
    auto rgt = lst;

    auto mid = *std::next(fst, uid(0, std::distance(fst, lst))(g));

    while (lft <= rgt) {
        for (; key(*lft,  mid); ++lft);
        for (; key( mid, *rgt); --rgt);

        if (lft <= rgt) {
            std::iter_swap(lft++, rgt--);
        }
    }

    quicksort0(fst, rgt, key);
    quicksort0(lft, lst, key);
}

template<class RandomIt, class Key=std::less<>>
void quicksort1(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst >= lst) return;

    auto mid = *std::next(fst, uid(0, std::distance(fst, lst) - 1)(g));

    auto lft = std::partition(
        fst, lst, [mid, key](const auto& x) {return key(x, mid);}
    );

    auto rgt = std::partition(
        lft, lst, [mid, key](const auto& x) {return x == mid;}
    );

    quicksort1(fst, lft, key);
    quicksort1(rgt, lst, key);
}
} // namespace detail

template<class RandomIt, class Key=std::less<>>
void quicksort0(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin >= end) return;

    detail::quicksort0(begin, std::prev(end), key);
}


template<class RandomIt, class Key=std::less<>>
void quicksort1(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin >= end) return;

    detail::quicksort1(begin, end, key);
}
