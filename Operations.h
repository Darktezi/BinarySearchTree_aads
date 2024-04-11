#pragma once
#include "BinarySearchTree.h"
#include <vector>

class Operations {
public:
    static std::vector<int> intersection(const BinarySearchTree& set1, const BinarySearchTree& set2);
    static std::vector<int> difference(BinarySearchTree& set1, BinarySearchTree& set2);
};

std::vector<int> Operations::intersection(const BinarySearchTree& set1, const BinarySearchTree& set2) {
    std::vector<int> result;
    auto root1 = set1.getRoot();
    auto root2 = set2.getRoot();

    while (root1 && root2) {
        if (root1->key == root2->key) {
            result.push_back(root1->key);
            root1 = root1->right;
            root2 = root2->right;
        }
        else if (root1->key < root2->key) {
            root1 = root1->right;
        }
        else {
            root2 = root2->right;
        }
    }

    return result;
}

std::vector<int> Operations::difference(BinarySearchTree& set1, BinarySearchTree& set2) {
    std::vector<int> result;
    auto root1 = set1.getRoot();
    auto root2 = set2.getRoot();

    while (root1) {
        if (!set2.contains(root1->key)) {
            result.push_back(root1->key);
        }
        root1 = root1->right;
    }

    return result;
}