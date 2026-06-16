#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <cstddef>

enum class Color { RED, BLACK };

class RedBlackTree {
public:
    struct Node {
        int key;
        Color color;
        Node *left, *right, *parent;
        bool isNil;

        Node(int value, Color nodeColor, bool sentinel);
    };

    RedBlackTree();
    ~RedBlackTree();

    void insert(int key);
    bool contains(int key) const;
    bool lowerBound(int key, int& result) const;
    bool upperBound(int key, int& result) const;
    
    const Node* root() const;
    const Node* nil() const;
    bool empty() const;
    std::size_t size() const;
    void clear();

private:
    Node* rootNode;
    Node* nilNode;
    std::size_t nodeCount;

    void rotateLeft(Node* node);
    void rotateRight(Node* node);
    void fixInsert(Node* node);
    void destroy(Node* node);
};

#endif