#ifndef SRC_DSU_HPP_
#define SRC_DSU_HPP_

#include <initializer_list>
#include <unordered_map>
#include <iostream>
#include <utility>

template <class T>
struct DisjointSetUnion {
    using S = std::size_t;

    S count;
    std::unordered_map<T, T> xs;
    std::unordered_map<T, S> ws;

    DisjointSetUnion() = default;

    template <class RandomIt>
    DisjointSetUnion(RandomIt ix, RandomIt iy) {
        count = std::distance(iy, ix);

        for (auto it = ix; it != iy; ++it) {
            xs[*it] = *it;
            ws[*it] = 1;
        }
    }

    DisjointSetUnion(std::initializer_list<T> keys) {
        count = keys.size();

        for (auto key : keys) {
            xs[key] = key;
            ws[key] = 1;
        }
    }

    void push_back(const T& key) {
        ++count;
        xs[key] = key;
        ws[key] = 1;
    }


    T find(const T& key, const S w = 0) {
        if (xs[key] == key) {
            ws[key] += w;

            return key;
        }

        ws[xs[key]] -= ws[key];
        return xs[key] = find(xs[key], ws[key]);
    }

    void unite(const T& key1, const T& key2) {
        auto val1 = find(key1);
        auto val2 = find(key2);

        if (val1 == val2) return;

        --count;

        if (ws[val1] < ws[val2]) {
            std::swap(val1, val2);
        }

        xs[val2] = val1;
        ws[val2] += ws[val1];
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const DisjointSetUnion<T>& dsu) {
    for (auto x : dsu.xs) {
        os << "(" << x.first << ", " << x.second << ") ";
    } os << std::endl;

    for (auto w : dsu.ws) {
        os << "(" << w.first << ", " << w.second << ") ";
    } os << std::endl;

    std::cerr << "===========" << std::endl;

    return os;
}

#endif  // SRC_DSU_HPP_
