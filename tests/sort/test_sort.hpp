#include <functional>

#include "../test.hpp"

using sort_fun_inc = std::function<
    void(vi::iterator, vi::iterator, std::less<>)
>;

using sort_fun_dec = std::function<
    void(vi::iterator, vi::iterator, std::greater<>)
>;

std::ostream& operator<<(std::ostream& os, const sort_fun_inc& sort) {
    return os << typeid(sort).name();
}

std::ostream& operator<<(std::ostream& os, const sort_fun_dec& sort) {
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
}}}
