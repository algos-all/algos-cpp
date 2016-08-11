#include <functional>
#include <iostream>
#include <vector>

template<typename T, typename Key=std::less_equal<T>>
class Heap {
    using vt = std::vector<T>;
    using iterator = typename vt::iterator;

    vt xs;
    Key key;

    void swim(const iterator ix, iterator iy) {
        while (ix != iy) {
            auto it = ix + std::distance(ix, iy) / 2;

            if (key(*it, *iy)) {break;}

            std::iter_swap(it, iy);
            iy = it;
        }
    }

    void sink(const iterator ix, const iterator iy, iterator zit) {
        auto lit = zit + std::distance(ix, zit) + 1;

        while (lit < iy) {
            auto rit = lit + 1;

            auto it = rit < iy && key(*rit, *lit) ? rit : lit;

            if (key(*zit, *it)) {break;}

            std::swap(*it, *zit);
            zit = it;
            lit = zit + std::distance(ix, zit) + 1;
        }
    }

public:
    Heap() : Heap(vt()) {}
    Heap(Key key) : Heap(vt(), key) {}
    Heap(const vt &xs) : Heap(xs, Key()) {}

    Heap(const vt &xs, Key key) : xs(xs), key(key) {
        auto ix = this->xs.rbegin();
        auto iy = this->xs.rend();

        auto it = ix + std::distance(ix, iy) / 2;

        for (; it != iy; ++it) {
            sink(this->xs.begin(), this->xs.end(), it.base() - 1);
        }
    }

    typename vt::size_type size() {
        return this->xs.size();
    }

    void push(const T &val) {
        xs.push_back(val);
        swim(xs.begin(), xs.end() - 1);
    }

    void pop() {
        if (xs.size() == 0) {return;}

        std::swap(*xs.begin(), *xs.rbegin());

        xs.pop_back();

        this->sink(xs.begin(), xs.end(), xs.begin());
    }

    T top() {
        return *xs.begin();
    }

    vt sort() {
        vt ys(xs.begin(), xs.end());

        for (auto it = ys.rbegin(); it != ys.rend(); ++it) {
            std::swap(*it, *ys.begin());
            this->sink(ys.begin(), it.base() - 1, ys.begin());
        }

        return ys;
    }

    iterator begin() {return xs.begin();}
    iterator end() {return xs.end();}

    friend std::ostream &
    operator<<(std::ostream &os, const Heap<T, Key> &heap) {
        for (const auto x : heap.xs) {
            os << x << " ";
        } os << std::endl;

        return os;
    }
};
