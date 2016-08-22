#include <iterator>
#include <algorithm>
#include <functional>

template<typename RandomIt, typename Key=std::less<>>
void mergesort(RandomIt fst, RandomIt lst, Key key=Key{}) {
    if (fst == lst || std::next(fst) == lst) {
        return;
    }

    auto it = std::next(fst, std::distance(fst, lst) / 2);

    mergesort(fst, it, key);
    mergesort(it, lst, key);

    std::inplace_merge(fst, it, lst, key);
}
