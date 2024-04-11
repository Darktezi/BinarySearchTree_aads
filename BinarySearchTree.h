#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(const int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:

    Node* root;
    Node* copy(const Node* node);
    void deleteTree(Node* root);
    Node* insertRecursive(Node* root, int key);
    bool containsRecursive(Node* root, int key);
    Node* eraseRecursive(Node* root, int key);
    void printRecursive(Node* root);
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);

    void print();
    bool insert(int key);
    bool contains(int key);
    bool erase(int key);
    Node* getRoot() const { return root; }
};
