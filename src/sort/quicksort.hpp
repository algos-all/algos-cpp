#include <random>
#include <iterator>
#include <algorithm>
#include <functional>

namespace detail {
template<class RandomIt, class Key=std::less<>, class Gen=std::mt19937>
void quicksort0(
    RandomIt fst, RandomIt lst,
    Key key=Key{}, Gen& gen=Gen{}
) {
    if (fst >= lst) return;

    auto lft = fst, rgt = lst;

    using uid = std::uniform_int_distribution<>;
    auto mid = *std::next(fst, uid(0, std::distance(fst, lst))(gen));

    while (lft <= rgt) {
        for (; key(*lft,  mid); ++lft);
        for (; key( mid, *rgt); --rgt);

        if (lft <= rgt)
            std::iter_swap(lft++, rgt--);
    }

    quicksort0(fst, rgt, key, gen);
    quicksort0(lft, lst, key, gen);
}

template<class RandomIt, class Key=std::less<>, class Gen=std::mt19937>
void quicksort1(
    RandomIt fst, RandomIt lst,
    Key key=Key{}, Gen& gen=Gen{}
) {
    using namespace std;
    if (fst == lst || next(fst) == lst) return;

    using uid = uniform_int_distribution<>;

    auto mid = *next(fst, uid(0, distance(fst, lst) - 1)(gen));

    auto lft = partition(
        fst, lst, [mid, key](const auto& x) {return key(x, mid);}
    );

    auto rgt = partition(
        lft, lst, [mid, key](const auto& x) {return x == mid;}
    );

    quicksort1(fst, lft, key, gen);
    quicksort1(rgt, lst, key, gen);
}
} // namespace detail


template<class RandomIt, class Key=std::less<>, class Sseq=std::size_t>
void quicksort0(RandomIt fst, RandomIt lst, Key key=Key{}, Sseq seq=42) {
    if (fst == lst) return;

    auto gen = std::mt19937(seq);

    detail::quicksort0(fst, std::prev(lst), key, gen);
}


template<class RandomIt, class Key=std::less<>, class Sseq=std::size_t>
void quicksort1(RandomIt fst, RandomIt lst, Key key=Key{}, Sseq seq=42) {
    if (fst == lst) return;

    auto gen = std::mt19937(seq);

    detail::quicksort1(fst, lst, key, gen);
}
