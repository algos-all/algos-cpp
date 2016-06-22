#include <random>

using generator = std::mt19937;
using uniformsz = std::uniform_int_distribution<int>;

template<typename iterator>
void quicksort(iterator fst, iterator lst) {
    if (fst >= lst) {return;}

    auto i = fst;
    auto j = lst;

    generator g(42);
    uniformsz rval(0, std::distance(i, j));
    auto pivot = *(fst + rval(g));

    while (i <= j) {
        for (; *i < pivot; i++);
        for (; pivot < *j; j--);

        if (i <= j) {
            std::swap(*i++, *j--);
        }
    }
    quicksort(fst, j);
    quicksort(i, lst);
}

template<typename iterator>
void qsort(iterator begin, iterator end) {
    if (begin == end) {return;}
    quicksort(begin, end - 1);
}
