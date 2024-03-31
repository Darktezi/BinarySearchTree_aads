#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) {
    root = nullptr;
    // �������� ������ ����������
    if (other.root)
        root = new Node(other.root->key);
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other) {
    if (this == &other) // �������� �� ����������������
        return *this;

    // ������� ������� ������
    deleteTree(root);
    root = nullptr;

    // �������� ������ ����������
    if (other.root)
        root = new Node(other.root->key);

    return *this;
}

void BinarySearchTree::deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}