#include "agraph.hpp"


template<typename Node>
class Graph : public AbstractGraph<Node> {
public:
    using Nodes = typename AbstractGraph<Node>::Nodes;
    using Edges = typename AbstractGraph<Node>::Edges;

    Graph() : AbstractGraph<Node>() {}
    Graph(Edges edges) : AbstractGraph<Node>(edges) {}

    virtual void add_edge(Node n1, Node n2) override {
        this->edges.insert({n1, Nodes()});
        this->edges.insert({n2, Nodes()});

        this->edges[n1].push_back(n2);
        this->edges[n2].push_back(n1);
    }

    virtual void del_edge(Node n1, Node n2) override {
        auto i1 = this->edges.find(n1);
        auto i2 = this->edges.find(n2);

        const auto end = this->edges.end();
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
    using Nodes = typename AbstractGraph<Node>::Nodes;
    using Edges = typename AbstractGraph<Node>::Edges;

    DiGraph() : AbstractGraph<Node>() {}
    DiGraph(Edges edges) : AbstractGraph<Node>(edges) {}

    virtual void add_edge(Node n1, Node n2) override {
        this->edges.insert({n1, Nodes()});
        this->edges.insert({n2, Nodes()});

        this->edges[n1].push_back(n2);
    }

    virtual void del_edge(Node n1, Node n2) override {
        auto i1 = this->edges.find(n1);

        if (i1 == this->edges.end()) {return;}

        auto &v1 = i1->second;

        v1.erase(std::remove(v1.begin(), v1.end(), n2), v1.end());
    }
};
