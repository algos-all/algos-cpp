#include <random>
#include <iterator>

namespace detail {
using gen = std::mt19937;
using uid = std::uniform_int_distribution<>;

gen g(42);

template<typename RandomIt, typename Key=std::less<>>
void quicksort(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst >= lst) {
        return;
    }

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

    quicksort(fst, rgt, key);
    quicksort(lft, lst, key);
}
}

template<typename RandomIt, typename Key=std::less<>>
void quicksort(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin == end) {
        return;
    }

    detail::quicksort(begin, std::prev(end), key);
}
