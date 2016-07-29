#include <random>
#include <iterator>

using generator = std::mt19937;

generator g(42);

template <
    typename RandomIt,
    typename Key = std::less<
        typename std::iterator_traits<RandomIt>::value_type
    >
>
void quicksort(RandomIt ix, RandomIt iy, Key key = Key()) {
    if (ix == iy) {return;}

    auto il = ix, ir = iy - 1;

    auto rval = std::uniform_int_distribution<>(0, std::distance(il, ir));
    auto pivot = *(ix + rval(g));

    while (il <= ir) {
        for (; key(*il, pivot); ++il);
        for (; key(pivot, *ir); --ir);

        if (il <= ir) {
            std::iter_swap(il++, ir--);
        }
    }

    quicksort(ix, ir + 1);
    quicksort(il, iy);
}
