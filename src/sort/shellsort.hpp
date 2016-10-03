#include <iterator>
#include <functional>

namespace detail {
template<class RandomIt, class Key=std::less<>>
void shellsort(RandomIt fst, RandomIt lst, Key key=Key{}) {
    using dtype = typename std::iterator_traits<RandomIt>::difference_type;

    dtype m = 1, n = std::distance(fst, lst);

    while (m < n / 3) {
        m = 3 * m + 1;
    }

    while (m != 0) {
        for (dtype i = m; i < n; ++i) {
            for (dtype j = i; j > m - 1; j -= m) {
                auto x = std::next(fst, j - m), y = std::next(fst, j);

                if (key(*x, *y)) {
                    break;
                }

                std::iter_swap(x, y);
            }
        }

        m /= 3;
    }
}
}

template<class RandomIt, class Key=std::less<>>
void shellsort(RandomIt begin, RandomIt end, Key key=Key{}) {
    if (begin >= end) return;

    detail::shellsort(begin, end, key);
}
