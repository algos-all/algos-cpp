#include <vector>
#include <unordered_map>


template<typename Node>
class AbstractGraph {

public:

    using nodes = std::vector<Node>;
    using edges = std::unordered_map<Node, nodes>;

protected:
    edges es;

public:
    AbstractGraph () : es() {}
    AbstractGraph (edges es) : es(es) {}

    virtual void add_edge(Node n1, Node n2) = 0;
    virtual void del_edge(Node n1, Node n2) = 0;

    nodes &at(const Node &node) {
        return this->es.at(node);
    }

    typename edges::iterator begin() {
        return es.begin();
    }

    typename edges::iterator end() {
        return es.end();
    }
};


template<typename Node, typename Weight>
class AbstractWeightedGraph {

public:
    using wnode = std::pair<Node, Weight>;

    using nodes = std::vector<wnode>;
    using edges = std::unordered_map<Node, nodes>;

protected:
    edges es;

public:
    AbstractWeightedGraph() : es() {};
    AbstractWeightedGraph(edges es) : es(es) {};

    virtual void add_edge(Node n1, Node n2, Weight w) = 0;
    virtual void del_edge(Node n1, Node n2) = 0;

    nodes &at(const Node &node) {
        return this->es.at(node);
    }

    typename edges::iterator begin() {
        return es.begin();
    }

    typename edges::iterator end() {
        return es.end();
    }
};
