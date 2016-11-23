#include <iterator>

template<class RandomIt, class Val>
RandomIt binsearch(RandomIt fst, RandomIt lst, const Val& val) {
    if (fst == lst) return lst;

    auto lft = fst, rgt = std::prev(lst);

    while (lft <= rgt) {
        const auto mid = std::next(lft, std::distance(lft, rgt) / 2);

        if (val == *mid)
            return mid;

        if (val < *mid)
            rgt = std::prev(mid);
        else
            lft = std::next(mid);
    }

    return lst; // not found
}

template<class RandomIt, class Val>
RandomIt xlower_bound(RandomIt fst, RandomIt lst, const Val& val) {
    if (fst == lst) return lst;

    auto lft = fst, rgt = std::prev(lst);

    while (lft <= rgt) {
        const auto mid = std::next(lft, std::distance(lft, rgt) / 2);

        if (*mid < val) {
            lft = std::next(mid);
        } else {
            rgt = std::prev(mid);
        }
    }

    return lft; // lower bound (if it exists) or past-the-end
}
