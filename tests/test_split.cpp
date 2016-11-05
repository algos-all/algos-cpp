#define BOOST_TEST_MODULE test_split
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "split.hpp"

BOOST_AUTO_TEST_CASE(empty) {
    const std::string str = "";

    auto result = split(str);

    BOOST_TEST(result.size() == 1);
    BOOST_TEST(result[0].empty());
}

BOOST_AUTO_TEST_CASE(only_sep) {
    const std::string str = " ";

    auto result = split(str, " ");

    BOOST_TEST(result.size() == 2);
    BOOST_TEST(result[0].empty());
    BOOST_TEST(result[1].empty());
}

BOOST_AUTO_TEST_CASE(no_sep) {
    const std::string str = "a";

    auto result = split(str, " ");

    BOOST_TEST(result.size() == 1);
    BOOST_TEST(result[0] == str);
}

BOOST_AUTO_TEST_CASE(double_sep) {
    const std::string str = "  ";

    auto result = split(str, " ");

    BOOST_TEST(result.size() == 3);
    for (auto r: result)
        BOOST_TEST(r.empty());
}

BOOST_AUTO_TEST_CASE(one_lft) {
    const std::string str = "a ";

    auto result = split(str, " ");

    BOOST_TEST(result.size() == 2);
    BOOST_TEST(result[0] == "a");
    BOOST_TEST(result[1].empty());
}

BOOST_AUTO_TEST_CASE(one_rgt) {
    const std::string str = " a";

    auto result = split(str, " ");

    BOOST_TEST(result.size() == 2);
    BOOST_TEST(result[0].empty());
    BOOST_TEST(result[1] == "a");
}
