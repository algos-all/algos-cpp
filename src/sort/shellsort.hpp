#ifndef SRC_SORT_SHELLSORT_HPP_
#define SRC_SORT_SHELLSORT_HPP_

#include <iterator>
#include <functional>

namespace detail {
template<class RandomIt, class Key = std::less<>>
void shellsort(RandomIt fst, RandomIt lst, Key key = Key{}) {
    using dtype = typename std::iterator_traits<
        RandomIt
    >::difference_type;

    dtype n = std::distance(fst, lst), m = 1;

    while (m < n / 3) {
        m = 3 * m + 1;
    }

    while (m != 0) {
        for (auto i = m; i < n; ++i) {
            for (auto j = i; j > m - 1; j -= m) {
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
}  // namespace detail

template<class RandomIt, class Key = std::less<>>
void shellsort(RandomIt fst, RandomIt lst, Key key = Key{}) {
    if (fst == lst) {
        return;
    }

    detail::shellsort(fst, lst, key);
}

#endif  // SRC_SORT_SHELLSORT_HPP_
