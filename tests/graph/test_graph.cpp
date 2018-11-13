#define BOOST_TEST_MODULE test_graph
#define BOOST_TEST_DYN_LINK

#include "../test.hpp"
#include "graph/graph.hpp"


BOOST_AUTO_TEST_CASE(add_edges_graph_0) {
    auto g = Graph<int>();

    g.add_edge(1, 2);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0] == 2);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0] == 1);
}

BOOST_AUTO_TEST_CASE(add_edges_graph_1) {
    auto g = Graph<int>();

    g.add_edge(1, 2);
    g.add_edge(3, 4);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0] == 2);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0] == 1);

    auto nodes3 = g.at(3);
    BOOST_TEST(nodes3.size() == 1);
    BOOST_TEST(nodes3[0] == 4);

    auto nodes4 = g.at(4);
    BOOST_TEST(nodes4.size() == 1);
    BOOST_TEST(nodes4[0] == 3);
}

BOOST_AUTO_TEST_CASE(add_edges_graph_2) {
    auto g = Graph<int>();

    g.add_edge(1, 2);
    g.add_edge(1, 3);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 2);

    std::sort(nodes1.begin(), nodes1.end());

    BOOST_TEST(nodes1[0] == 2);
    BOOST_TEST(nodes1[1] == 3);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0] == 1);

    auto nodes3 = g.at(3);
    BOOST_TEST(nodes3.size() == 1);
    BOOST_TEST(nodes3[0] == 1);
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

// Deletes an edge for which both nodes are not in the graph
BOOST_AUTO_TEST_CASE(del_nonexist_graph_0) {
    auto g = Graph<int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}

BOOST_AUTO_TEST_CASE(del_nonexist_digraph_0) {
    auto g = DiGraph<int>();

    g.del_edge(1, 2);
    BOOST_TEST(true == true);
}

// Deletes an edge for which one node is in the graph and the other is not
BOOST_AUTO_TEST_CASE(del_nonexist_graph_1) {
    auto g = Graph<int>();

    g.add_edge(1, 2);
    g.del_edge(2, 3);

    auto nodes1 = g.at(1);
    BOOST_TEST(nodes1.size() == 1);
    BOOST_TEST(nodes1[0] == 2);

    auto nodes2 = g.at(2);
    BOOST_TEST(nodes2.size() == 1);
    BOOST_TEST(nodes2[0] == 1);
}
