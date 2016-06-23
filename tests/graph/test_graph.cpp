#define BOOST_TEST_MODULE test_heap
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "graph/graph.hpp"

BOOST_AUTO_TEST_CASE(add_one_edge_graph) {
    auto g = Graph<int>();

    g.add_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0] == 2);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0] == 1);
}

BOOST_AUTO_TEST_CASE(add_one_edge_digraph) {
    auto g = DiGraph<int>();

    g.add_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0] == 2);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_graph_0) {
    auto g = Graph<int>();

    g.add_edge(1, 2);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_digraph_0) {
    auto g = DiGraph<int>();

    g.add_edge(1, 2);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_graph_1) {
    auto g = Graph<int>();

    g.add_edge(1, 2);
    g.add_edge(1, 2);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_one_edge_digraph_1) {
    auto g = DiGraph<int>();

    g.add_edge(1, 2);
    g.add_edge(1, 2);
    g.del_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 0);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 0);
}

BOOST_AUTO_TEST_CASE(del_nonexist_graph) {
    auto g = Graph<int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}

BOOST_AUTO_TEST_CASE(del_nonexist_digraph) {
    auto g = DiGraph<int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}
