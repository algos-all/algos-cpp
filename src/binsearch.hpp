#include <iterator>

template<class RandomIt, class Val>
RandomIt binsearch(RandomIt fst, RandomIt lst, const Val& val) {
    if (fst == lst) {
        return lst;
    }

    auto lft = fst, rgt = std::prev(lst);

    while (lft <= rgt) {
        const auto mid = std::next(lft, std::distance(lft, rgt) / 2);

        if (val == *mid) {
            return mid;
        }

        if (val < *mid) {
            rgt = std::prev(mid);
        } else {
            lft = std::next(mid);
        }
    }

    return lst; // not found
}

template<class RandomIt, class Val>
RandomIt xlower_bound(RandomIt fst, RandomIt lst, const Val& val) {
    if (fst == lst) {
        return lst;
    }

    while (fst < lst) {
        const auto mid = std::next(fst, std::distance(fst, lst) / 2);

        if (val <= *mid) {
            lst = mid;
        } else {
            fst = mid + 1;
        }
    }

    // First element that is equal or larger than val in the
    // original range. If no such element, than past-the-end.
    return fst;
}

template<class RandomIt, class Val>
RandomIt xupper_bound(RandomIt fst, RandomIt lst, const Val& val) {
    if (fst == lst) {
        return lst;
    }

    while (fst < lst) {
        const auto mid = std::next(fst, std::distance(fst, lst) / 2);

        if (*mid <= val) {
            fst = mid + 1;
        } else {
            lst = mid;
        }
    }

    // First element that is strictly larger than val in the
    // original range. If no such element, than past-the-end.
    return fst;
}
