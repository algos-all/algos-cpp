#include <iterator>

template<typename Iterator, typename T>
Iterator binsearch(Iterator ix, Iterator iy, const T &v) {
    const auto iz = iy;

    while (ix < iy) {
        const auto mid = std::next(ix, std::distance(ix, iy) / 2);

        if (*mid == v) {
            return mid;
        }

        if (v < *mid) {
            iy = mid;
        } else {
            ix = mid + 1;
        }
    }

    return iz;
}
