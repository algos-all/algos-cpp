#include <iterator>

template<typename Iterator, typename T>
Iterator binsearch(Iterator begin, Iterator end, const T &v) {
    if (begin == end) {return end;}

    Iterator save = end;

    while (begin != end) {
        Iterator mid = begin + std::distance(begin, end) / 2;

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
