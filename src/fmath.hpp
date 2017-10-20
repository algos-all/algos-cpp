template<typename T>
T gcf(T a, T b) {
    while (b != 0) {
        const auto r = a % b;
        a = b;
        b = r;
    }

    return a;
}
