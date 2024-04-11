#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <algorithm>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) {
    root = nullptr;
    if (other.root)
        root = new Node(other.root->key);
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

Node* BinarySearchTree::copy(const Node* node) {
    if (!node)
        return nullptr;
    Node* newNode = new Node(node->key);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other) {
    if (this != &other) {
        deleteTree(root);
        root = copy(other.root);
    }
    return *this;
}

void BinarySearchTree::deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void BinarySearchTree::print() {
    printRecursive(root);
    std::cout << std::endl;
}

bool BinarySearchTree::insert(int key) {
    if (contains(key))
        return false;
    root = insertRecursive(root, key);
    return true;
}

bool BinarySearchTree::contains(int key){
    return containsRecursive(root, key);
}

bool BinarySearchTree::erase(int key) {
    if (!contains(key))
        return false;
    root = eraseRecursive(root, key);
    return true;
}

Node* BinarySearchTree::insertRecursive(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insertRecursive(root->left, key);
    else if (key > root->key)
        root->right = insertRecursive(root->right, key);

    return root;
}

bool BinarySearchTree::containsRecursive(Node* root, int key){
    if (!root)
        return false;

    if (key == root->key)
        return true;

    if (key < root->key)
        return containsRecursive(root->left, key);
    else
        return containsRecursive(root->right, key);
}

Node* BinarySearchTree::eraseRecursive(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = eraseRecursive(root->left, key);
    else if (key > root->key)
        root->right = eraseRecursive(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left)
            temp = temp->left;

        root->key = temp->key;
        root->right = eraseRecursive(root->right, temp->key);
    }
    return root;
}

void BinarySearchTree::printRecursive(Node* root) {
    if (root) {
        printRecursive(root->left);
        std::cout << root->key << " ";
        printRecursive(root->right);
    }
}