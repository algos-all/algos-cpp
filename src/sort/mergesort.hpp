#include <iterator>
#include <algorithm>
#include <functional>

template<
    typename InputIt,
    typename Key=std::less<
        typename std::iterator_traits<InputIt>::value_type
    >
>
void mergesort(InputIt ix, InputIt iy, Key key=Key()) {
    if (ix == iy || ix + 1 == iy) {
        return;
    }

    auto iz = std::next(ix, std::distance(ix, iy) / 2);

    mergesort(ix, iz, key);
    mergesort(iz, iy, key);

    std::inplace_merge(ix, iz, iy, key);
}
