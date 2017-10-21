#include<array>

template<typename T>
T gcf(T a, T b) {
    while (b != 0) {
        const auto r = a % b;
        a = b;
        b = r;
    }

    return a;
}

template<typename T>
std::array<T, 3> xgcf(T a, T b) {
    T s1 = 1, s2 = 0;
    T t1 = 0, t2 = 1;

    while (b != 0) {
        const auto divmod = div(a, b);
        a = b;
        b = divmod.rem;

        const auto x = s1;
        s1 = s2;
        s2 = x - divmod.quot * s2;

        const auto y = t1;
        t1 = t2;
        t2 = y - divmod.quot * t2;
    }

    return {a, s1, t1};
}
