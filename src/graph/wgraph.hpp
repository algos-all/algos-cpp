#ifndef SRC_GRAPH_WGRAPH_HPP_
#define SRC_GRAPH_WGRAPH_HPP_

#include<algorithm>

#include "agraph.hpp"


template<typename Node, typename Weight>
class WeightedGraph : public AbstractWeightedGraph<Node, Weight> {
 public:
    using graph = AbstractWeightedGraph<Node, Weight>;

    using nodes = typename graph::nodes;
    using edges = typename graph::edges;

    WeightedGraph() : graph() {}
    explicit WeightedGraph(edges es) : graph(es) {}

    void add_edge(Node n1, Node n2, Weight w) override {
        this->es.insert({n1, nodes()});
        this->es.insert({n2, nodes()});

        this->es[n1].push_back({n2, w});
        this->es[n2].push_back({n1, w});
    }

    void del_edge(Node n1, Node n2) override {
        auto i1 = this->es.find(n1);
        auto i2 = this->es.find(n2);

        const auto end = this->es.end();
        if (i1 == end && i2 == end) {return;}

        auto &v1 = i1->second;
        auto v1i = v1.begin();
        auto v1j = v1.end();

        auto &v2 = i2->second;
        auto v2i = v2.begin();
        auto v2j = v2.end();

        v1.erase(
            std::remove_if(v1i, v1j, [&n2] (auto p) {return p.first == n2;}),
            v1.end()
        );
        v2.erase(
            std::remove_if(v2i, v2j, [&n1] (auto p) {return p.first == n1;}),
            v2.end()
        );
    }
};


template<typename Node, typename Weight>
class WeightedDiGraph : public AbstractWeightedGraph<Node, Weight> {
 public:
    using graph = AbstractWeightedGraph<Node, Weight>;

    using nodes = typename graph::nodes;
    using edges = typename graph::edges;

    WeightedDiGraph() : graph() {}
    explicit WeightedDiGraph(edges es) : graph(es) {}

    void add_edge(Node n1, Node n2, Weight w) override {
        this->es.insert({n1, nodes()});
        this->es.insert({n2, nodes()});

        this->es[n1].push_back({n2, w});
    }

    void del_edge(Node n1, Node n2) override {
        auto i1 = this->es.find(n1);
        auto i2 = this->es.find(n2);

        const auto end = this->es.end();
        if (i1 == end && i2 == end) {return;}

        auto &v1 = i1->second;
        auto v1i = v1.begin();
        auto v1j = v1.end();

        v1.erase(
            std::remove_if(v1i, v1j, [&n2] (auto p) {return p.first == n2;}),
            v1.end()
        );
    }
};

#endif  // SRC_GRAPH_WGRAPH_HPP_
