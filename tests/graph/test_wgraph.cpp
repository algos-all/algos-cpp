#define BOOST_TEST_MODULE test_heap
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "graph/wgraph.hpp"

BOOST_AUTO_TEST_CASE(add_one_edge_graph) {
    auto g = WeightedGraph<int, int>();

    g.add_edge(1, 2, 42);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0].first == 2);
    BOOST_TEST(nodes1[0].second == 42);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0].first == 1);
    BOOST_TEST(nodes2[0].second == 42);
}

BOOST_AUTO_TEST_CASE(add_one_edge_digraph) {
    auto g = WeightedDiGraph<int, int>();

    g.add_edge(1, 2, 42);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0].first == 2);
    BOOST_TEST(nodes1[0].second == 42);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_graph_0) {
    auto g = WeightedGraph<int, int>();

    g.add_edge(1, 2, 42);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_digraph_0) {
    auto g = WeightedDiGraph<int, int>();

    g.add_edge(1, 2, 42);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_graph_1) {
    auto g = WeightedGraph<int, int>();

    g.add_edge(1, 2, 42);
    g.add_edge(1, 2, 43);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_digraph_1) {
    auto g = WeightedDiGraph<int, int>();

    g.add_edge(1, 2, 42);
    g.add_edge(1, 2, 43);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_nonexist_graph) {
    auto g = WeightedGraph<int, int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}

BOOST_AUTO_TEST_CASE(del_nonexist_digraph) {
    auto g = WeightedDiGraph<int, int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}
