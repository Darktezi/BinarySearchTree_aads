#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) {
    root = nullptr;
    // Копируем дерево рекурсивно
    if (other.root)
        root = new Node(other.root->key);
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other) {
    if (this == &other) // Проверка на самоприсваивание
        return *this;

    // Очищаем текущее дерево
    deleteTree(root);
    root = nullptr;

    // Копируем дерево рекурсивно
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