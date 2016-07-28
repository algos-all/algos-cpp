#include <iterator>
#include <functional>

template<
    class RandomIt,
    class Key=std::less_equal<
        typename std::iterator_traits<RandomIt>::value_type
    >
>
void plunge(
    const RandomIt ix, const RandomIt iy, const RandomIt iz,
    Key key = Key()
) {
    auto ii = iz;
    auto il = ix;
    std::advance(il, 2 * std::distance(ix, ii) + 1);

    while (il < iy) {
        auto ir = il + 1;

        auto it = ir < iy && key(*ir, *il) ? ir : il;

        if (key(*ii, *it)) {break;}

        std::iter_swap(ii, it);
        std::     swap(ii, it);

        il = ix;
        std::advance(il, 2 * std::distance(ix, ii) + 1);
    }
}

template<
    class RandomIt,
    class Key=std::greater_equal<
        typename std::iterator_traits<RandomIt>::value_type
    >
>
void heapsort(const RandomIt ix, const RandomIt iy, Key key = Key()) {
    auto it = ix;
    std::advance(it, std::distance(ix, iy) / 2);

    for (; it != ix - 1; --it) {
        plunge(ix, iy, it, key);
    }

    for (it = iy - 1; it != ix - 1; --it) {
        std::iter_swap(it, ix);
        plunge(ix, it, ix, key);
    }
}
