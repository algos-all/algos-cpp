#define BOOST_TEST_MODULE test_binary_tree
#define BOOST_TEST_DYN_LINK

#include "test.hpp"
#include "binary_tree.hpp"


BOOST_AUTO_TEST_CASE(one_element_0) {
    auto tree = BinarySearchTree<>();

    tree[42] = 42;

    BOOST_TEST(tree[42] == 42);
}

BOOST_AUTO_TEST_CASE(one_element_1) {
    auto tree = BinarySearchTree<>();

    tree[42] = 42;

    BOOST_TEST(tree.at(42) == 42);
}

BOOST_AUTO_TEST_CASE(at_throws_on_miss) {
    auto tree = BinarySearchTree<>();

    BOOST_REQUIRE_THROW(tree.at(42), std::out_of_range);
}

BOOST_DATA_TEST_CASE(
    random_add_0, bdata::xrange(1, 256) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    auto tree = BinarySearchTree<int, int>();

    for (auto i = xs.begin(); i != xs.end(); ++i) {
        tree[*i] = *i;
        for (auto j = xs.begin(); j <= i; ++j) {
            BOOST_TEST(tree[*j] == *j);
        }
    }
}

BOOST_DATA_TEST_CASE(
    random_add_erase_0, bdata::xrange(1, 256) * bdata::xrange(10), n, s
) {
    vi xs = create_vector(n, s);

    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    std::shuffle(xs.begin(), xs.end(), std::mt19937(42));

    auto tree = BinarySearchTree<int, int>();

    for (auto i = xs.begin(); i != xs.end(); ++i) {
        tree[*i] = *i;
    }

    std::shuffle(xs.begin(), xs.end(), std::mt19937(42));

    for (auto i = xs.begin(); i != xs.end(); ++i) {
        BOOST_TEST(tree.erase(*i) == 1);
        BOOST_TEST(tree.erase(*i) == 0);

        for (auto j = i + 1; j != xs.end(); ++j) {
            BOOST_TEST(tree[*j] == *j);
        }
    }
}
