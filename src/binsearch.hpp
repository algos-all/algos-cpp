#include <iterator>

template<typename iterator, typename T>
iterator binsearch(iterator begin, iterator end, const T &v) {
    if (begin == end) {return end;}

    const auto save = end;

    while (begin != end) {
        const auto mid = begin + std::distance(begin, end) / 2;

        if (*mid == v) {
            return mid;
        }

        if (v < *mid) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }

    return save;
}
