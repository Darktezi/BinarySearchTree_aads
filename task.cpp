#include "BinarySearchTree.h"
#include "Operations.h"
#include <iostream>
#include <vector>

int main() {
    BinarySearchTree set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    BinarySearchTree set2;
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);

    BinarySearchTree unionResult = SetOperations::unionSet(set1, set2);
    std::cout << "Union: ";
    unionResult.print();

    BinarySearchTree symmetricDiffResult = SetOperations::symmetricDifference(set1, set2);
    std::cout << "Symmetric Difference: ";
    symmetricDiffResult.print();

    return 0;
}