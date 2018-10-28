#ifndef SRC_GRAPH_GRAPH_HPP_
#define SRC_GRAPH_GRAPH_HPP_

#include "agraph.hpp"


template<typename Node>
class Graph : public AbstractGraph<Node> {
 public:
    using super = AbstractGraph<Node>;
    using nodes = typename super::nodes;
    using edges = typename super::edges;

    Graph() : super() {}
    explicit Graph(edges es) : super(es) {}

    void add_edge(Node n1, Node n2) override {
        this->es.insert({n1, nodes{}});
        this->es.insert({n2, nodes{}});

        this->es[n1].push_back(n2);
        this->es[n2].push_back(n1);
    }

    void del_edge(Node n1, Node n2) override {
        auto i1 = this->es.find(n1);
        auto i2 = this->es.find(n2);

        const auto end = this->es.end();
        if (i1 == end && i2 == end) {return;}

        auto &v1 = i1->second;
        auto &v2 = i2->second;

        v1.erase(std::remove(v1.begin(), v1.end(), n2), v1.end());
        v2.erase(std::remove(v2.begin(), v2.end(), n1), v2.end());
    }
};

template<typename Node>
class DiGraph : public AbstractGraph<Node> {
 public:
    using super = AbstractGraph<Node>;
    using nodes = typename super::nodes;
    using edges = typename super::edges;


    DiGraph() : super() {}
    explicit DiGraph(edges es) : super(es) {}

    void add_edge(Node n1, Node n2) override {
        this->es.insert({n1, nodes{}});
        this->es.insert({n2, nodes{}});

        this->es[n1].push_back(n2);
    }

    void del_edge(Node n1, Node n2) override {
        auto i1 = this->es.find(n1);

        if (i1 == this->es.end()) {return;}

        auto &v1 = i1->second;

        v1.erase(std::remove(v1.begin(), v1.end(), n2), v1.end());
    }
};

#endif  // SRC_GRAPH_GRAPH_HPP_
