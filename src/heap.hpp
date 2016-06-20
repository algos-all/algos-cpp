#include <iostream>
#include <vector>

template<typename T>
class Heap {
    using vt = std::vector<T>;
    using sz = typename vt::size_type;

    using iter = typename vt::iterator;
    using citer = const typename vt::iterator;

    vt xs;

    void swim(citer xit, iter zit) {
        for (auto it = xit; zit != xit; zit = it) {
            it += std::distance(xit, zit) / 2;

            if (*it <= *zit) {break;}

            std::swap(*it, *zit);
        }
    }

    void sink(citer xit, citer yit, iter zit) {
        auto lit = zit + std::distance(xit, zit) + 1;

        while (lit < yit) {
            auto rit = lit + 1;

            auto it = rit < yit && *rit < *lit ? rit : lit;

            if (*zit <= *it) {break;}

            std::swap(*it, *zit);
            zit = it;
            lit = zit + std::distance(xit, zit) + 1;
        }
    }

public:
    Heap() : xs() {}
    Heap(const vt &xs) : xs(xs) {
        auto beg = this->xs.rbegin();
        auto end = this->xs.rend();

        auto it = beg + std::distance(beg, end) / 2;

        for (; it != end; ++it) {
            sink(this->xs.begin(), this->xs.end(), it.base() - 1);
        }
    }

    sz size() {return this->xs.size();}

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

    friend std::ostream &
    operator<<(std::ostream &os, const Heap<T> &heap) {
        for (const auto x : heap.xs) {
            os << x << " ";
        } os << std::endl;

        return os;
    }
};
