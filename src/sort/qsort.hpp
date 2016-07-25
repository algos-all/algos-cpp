#include <random>
#include <iterator>

namespace sort {
    using generator = std::mt19937;

    generator g(42);

    namespace detail {
        template<typename RandomIter>
        void quicksort(RandomIter fst, RandomIter lst) {
            if (fst >= lst) {return;}

            auto i = fst, j = lst;
            auto rval = std::uniform_int_distribution<>(0, std::distance(i, j));

            auto pivot = *(fst + rval(g));

            while (i <= j) {
                for (; *i < pivot; i++);
                for (; pivot < *j; j--);

                if (i <= j) {
                    std::iter_swap(i++, j--);
                }
            }
            quicksort(fst, j);
            quicksort(i, lst);
        }
    } // namespace detail

    template<typename iterator>
    void qsort(iterator begin, iterator end) {
        if (begin == end) {return;}
        detail::quicksort(begin, end - 1);
    }
} // namespace sort
