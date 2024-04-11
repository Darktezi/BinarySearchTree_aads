#include "BinarySearchTree.h"
#include "Operations.h"
#include <iostream>
#include <vector>

int main() {
    BinarySearchTree set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);

    BinarySearchTree set2;
    set2.insert(2);
    set2.insert(4);
    set2.insert(6);
    set2.insert(8);

    std::vector<int> intersection_result = Operations::intersection(set1, set2);
    std::cout << "Intersection of sets: ";
    for (int elem : intersection_result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::vector<int> difference_result = Operations::difference(set1, set2);
    std::cout << "Difference of sets (set1 - set2): ";
    for (int elem : difference_result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}