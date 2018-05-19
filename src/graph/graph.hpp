#include "agraph.hpp"


template<typename Node>
class Graph : public AbstractGraph<Node> {

public:
    using graph = AbstractGraph<Node>;
    using nodes = typename graph::nodes;
    using edges = typename graph::edges;

    Graph() : graph() {}
    Graph(edges es) : graph(es) {}

    virtual void add_edge(Node n1, Node n2) override {
        this->es.insert({n1, nodes()});
        this->es.insert({n2, nodes()});

        this->es[n1].push_back(n2);
        this->es[n2].push_back(n1);
    }

    virtual void del_edge(Node n1, Node n2) override {
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
    using graph = AbstractGraph<Node>;
    using nodes = typename graph::nodes;
    using edges = typename graph::edges;


    DiGraph() : graph() {}
    DiGraph(edges es) : graph(es) {}

    virtual void add_edge(Node n1, Node n2) override {
        this->es.insert({n1, nodes()});
        this->es.insert({n2, nodes()});

        this->es[n1].push_back(n2);
    }

    virtual void del_edge(Node n1, Node n2) override {
        auto i1 = this->es.find(n1);

        if (i1 == this->es.end()) {return;}

        auto &v1 = i1->second;

        v1.erase(std::remove(v1.begin(), v1.end(), n2), v1.end());
    }
};
