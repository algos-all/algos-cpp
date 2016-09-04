#include <iterator>
#include <functional>

template<class RandomIt, class Key=std::less<>>
void plunge(RandomIt ix, RandomIt iy, RandomIt iz, Key key=Key{}) {
    auto il = std::next(ix, 2 * std::distance(ix, iz) + 1);

    while (il < iy) {
        auto ir = il + 1;

        auto it = ir < iy && key(*ir, *il) ? ir : il;

        if (key(*iz, *it)) {break;}

        std::iter_swap(iz, it);
        std::     swap(iz, it);

        il = std::next(ix, 2 * std::distance(ix, iz) + 1);
    }
}

template<class RandomIt, class Key=std::greater<>>
void heapsort(RandomIt ix, RandomIt iy, Key key=Key{}) {
    auto it = std::next(ix, std::distance(ix, iy) / 2);

    for (; it != ix - 1; --it) {
        plunge(ix, iy, it, key);
    }

    for (it = iy - 1; it != ix - 1; --it) {
        std::iter_swap(it, ix);
        plunge(ix, it, ix, key);
    }
}
