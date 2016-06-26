#include<algorithm>

#include "agraph.hpp"


template<typename Node, typename Weight>
class WeightedGraph : public AbstractWeightedGraph<Node, Weight> {
public:
    using Nodes = typename AbstractWeightedGraph<Node, Weight>::Nodes;
    using Edges = typename AbstractWeightedGraph<Node, Weight>::Edges;

    WeightedGraph() : AbstractWeightedGraph<Node, Weight>() {}
    WeightedGraph(Edges edges)
        : AbstractWeightedGraph<Node, Weight>(edges)
    {}

    virtual void add_edge(Node n1, Node n2, Weight w) override {
        this->edges.insert({n1, Nodes()});
        this->edges.insert({n2, Nodes()});

        this->edges[n1].push_back({n2, w});
        this->edges[n2].push_back({n1, w});
    }

    virtual void del_edge(Node n1, Node n2) override {
        auto i1 = this->edges.find(n1);
        auto i2 = this->edges.find(n2);

        const auto end = this->edges.end();
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
    using Nodes = typename AbstractWeightedGraph<Node, Weight>::Nodes;
    using Edges = typename AbstractWeightedGraph<Node, Weight>::Edges;

    WeightedDiGraph() : AbstractWeightedGraph<Node, Weight>() {}
    WeightedDiGraph(Edges edges)
        : AbstractWeightedGraph<Node, Weight>(edges)
    {}

    virtual void add_edge(Node n1, Node n2, Weight w) override {
        this->edges.insert({n1, Nodes()});
        this->edges.insert({n2, Nodes()});

        this->edges[n1].push_back({n2, w});
    }

    virtual void del_edge(Node n1, Node n2) override {
        auto i1 = this->edges.find(n1);
        auto i2 = this->edges.find(n2);

        const auto end = this->edges.end();
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
