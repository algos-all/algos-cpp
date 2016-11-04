#include <functional>

#include "../test.hpp"

using sort_fun_inc = std::function<
    void(vi::iterator, vi::iterator, std::less<>)
>;

using sort_fun_dec = std::function<
    void(vi::iterator, vi::iterator, std::greater<>)
>;

using sort_fun_rnd_inc = std::function<
    void(vi::iterator, vi::iterator, std::less<int>, int)
>;

using sort_fun_rnd_dec = std::function<
    void(vi::iterator, vi::iterator, std::greater<int>, int)
>;

std::ostream& operator<<(std::ostream& os, const sort_fun_inc& sort) {
    return os << typeid(sort).name();
}

std::ostream& operator<<(std::ostream& os, const sort_fun_dec& sort) {
    return os << typeid(sort).name();
}

std::ostream& operator<<(std::ostream& os, const sort_fun_rnd_inc& sort) {
    return os << typeid(sort).name();
}

std::ostream& operator<<(std::ostream& os, const sort_fun_rnd_dec& sort) {
    return os << typeid(sort).name();
}

namespace boost { namespace test_tools { namespace tt_detail {
    template<> struct print_log_value<sort_fun_inc> {
        void operator()(std::ostream& os, const sort_fun_inc& sort) {
            ::operator<<(os, sort);
        }
    };

    template<> struct print_log_value<sort_fun_dec> {
        void operator()(std::ostream& os, const sort_fun_dec& sort) {
            ::operator<<(os, sort);
        }
    };

    template<> struct print_log_value<sort_fun_rnd_inc> {
        void operator()(std::ostream& os, const sort_fun_rnd_inc& sort) {
            ::operator<<(os, sort);
        }
    };

    template<> struct print_log_value<sort_fun_rnd_dec> {
        void operator()(std::ostream& os, const sort_fun_rnd_dec& sort) {
            ::operator<<(os, sort);
        }
    };
}}}
