#include <iostream>
#include <utility>
#include <memory>


template<class Key=int, class Val=int>
struct BinarySearchNode {
    using NodePtr = std::shared_ptr<BinarySearchNode<Key, Val>>;

    Key key;
    Val val;

    NodePtr lft;
    NodePtr rgt;

    BinarySearchNode(Key key, Val val)
        : key{key}, val{val}, lft{}, rgt{} {}
};

template<class Key=int, class Val=int>
struct BinarySearchTree {
    using Node = BinarySearchNode<Key, Val>;
    using NodePtr = std::shared_ptr<Node>;

    NodePtr root;

    BinarySearchTree() : root{} {}

    std::pair<NodePtr, NodePtr> get_node_with_parent(const Key& key) {
        NodePtr node = root, parent = nullptr;

        while (node != nullptr) {
            if (key == node->key) {
                return {node, parent};
            }

            if (key < node->key) {
                parent = node; node = node->lft;
            } else {
                parent = node; node = node->rgt;
            }
        }

        return {nullptr, parent};
    }

    Val& at(const Key& key) {
        NodePtr node;

        std::tie(node, std::ignore) = get_node_with_parent(key);

        if (node == nullptr)
            throw std::out_of_range("");

        return node->val;
    }

    Val& operator[](const Key& key) {
        NodePtr node, parent;

        std::tie(node, parent) = get_node_with_parent(key);

        if (node == nullptr && parent == nullptr) {
            root = std::make_shared<Node>(Node(key, Val{}));

            return root->val;
        } else if (node == nullptr) {
            node = std::make_shared<Node>(Node(key, Val{}));

            if (key < parent->key) {
                parent->lft = node;
            } else {
                parent->rgt = node;
            }
        }

        return node->val;
    }

    std::size_t erase(const Key& key) {
        NodePtr heir, node, parent;

        std::tie(node, parent) = get_node_with_parent(key);

        if (node == nullptr) return 0;

        if (node->lft != nullptr && node->rgt != nullptr) {
            heir = node->lft; parent = node;

            while (heir->rgt != nullptr) {
                parent = heir; heir = heir->rgt;
            }

            if (parent == node) {
                parent->lft = heir->lft;
            } else {
                parent->rgt = heir->lft;
            }

            node->key = heir->key; node->val = heir->val;
        } else if (node->lft != nullptr) {
            heir = node->lft;
            node->key = heir->key; node->val = heir->val;
            node->lft = heir->lft; node->rgt = heir->rgt;
        } else if (node->rgt != nullptr) {
            heir = node->rgt;
            node->key = heir->key; node->val = heir->val;
            node->lft = heir->lft; node->rgt = heir->rgt;
        } else {
            if (node == root) {
                root = nullptr;
            } else {
                if (node == parent->lft) {
                    parent->lft = nullptr;
                } else {
                    parent->rgt = nullptr;
                }
            }

            heir = node;
        }

        heir->lft = nullptr; heir->rgt = nullptr;

        return 1;
    }
};
