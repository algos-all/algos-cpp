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
        iz = it;

        il = std::next(ix, 2 * std::distance(ix, iz) + 1);
    }
}

template<class RandomIt, class Key=std::less<>>
void makeheap(RandomIt ix, RandomIt iy, Key key=Key{}) {
    if (ix >= iy) return;

    using namespace std;

    for (auto iz = next(ix, distance(ix, iy) / 2); iz >= ix; --iz) {
        plunge(ix, iy, iz, key);
    }
}

template<class RandomIt, class Key=std::less<>>
void pushheap(RandomIt ix, RandomIt iy, Key key=Key{}) {
    if (ix >= iy) return;

    iy = std::prev(iy);

    while (ix != iy) {
        auto iz = std::next(ix, (std::distance(ix, iy) - 1) / 2);

        if (key(*iz, *iy)) return;

        std::iter_swap(iz, iy);
        iy = iz;
    }
}

template<class RandomIt, class Key=std::less<>>
void popheap(RandomIt ix, RandomIt iy, Key key=Key{}) {
    if (ix >= iy) return;

    iy = std::prev(iy);

    std::iter_swap(ix, iy);
    plunge(ix, iy, ix, key);
}

template<class RandomIt, class Key=std::greater<>>
void heapsort(RandomIt ix, RandomIt iy, Key key=Key{}) {
    makeheap(ix, iy, key);

    for (auto it = iy; it != ix; --it) {
        popheap(ix, it, key);
    }
}
