#pragma once
#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <algorithm>

class SetOperations {
public:
    static BinarySearchTree unionSet(const BinarySearchTree& set1, const BinarySearchTree& set2) {
        BinarySearchTree result;

        std::vector<int> elements;
        extractElements(set1.getRoot(), elements);
        extractElements(set2.getRoot(), elements);

        std::sort(elements.begin(), elements.end());
        elements.erase(std::unique(elements.begin(), elements.end()), elements.end());

        for (int element : elements) {
            result.insert(element);
        }

        return result;
    }

    static BinarySearchTree symmetricDifference(const BinarySearchTree& set1, const BinarySearchTree& set2) {
        BinarySearchTree result;

        std::vector<int> elements1;
        std::vector<int> elements2;
        extractElements(set1.getRoot(), elements1);
        extractElements(set2.getRoot(), elements2);

        std::sort(elements1.begin(), elements1.end());
        std::sort(elements2.begin(), elements2.end());

        std::vector<int> symmetricDiff;
        std::set_symmetric_difference(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), std::back_inserter(symmetricDiff));

        for (int element : symmetricDiff) {
            result.insert(element);
        }

        return result;
    }

private:
    static void extractElements(const Node* root, std::vector<int>& elements) {
        if (root) {
            extractElements(root->left, elements);
            elements.push_back(root->key);
            extractElements(root->right, elements);
        }
    }
};
