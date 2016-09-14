#include <iterator>
#include <algorithm>
#include <functional>

template<typename RandomIt, typename Key=std::less<>>
void mergesort(RandomIt ix, RandomIt iy, Key key=Key{}) {
    if (ix == iy || std::next(ix) == iy) {
        return;
    }

    auto it = std::next(ix, std::distance(ix, iy) / 2);

    mergesort(ix, it, key);
    mergesort(it, iy, key);

    std::inplace_merge(ix, it, iy, key);
}
