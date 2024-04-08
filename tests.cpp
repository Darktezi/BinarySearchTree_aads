#include <iostream>
#include <chrono>

#include "BinarySearchTree.h"

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

double fillContainer(BinarySearchTree& tree, int size) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i) {
        tree.insert(lcg());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

int main() {
    int sizes[] = { 1000, 10000, 100000 };
    int attempts = 100;

    for (int size : sizes) {
        double total_time = 0;

        for (int i = 0; i < attempts; ++i) {
            BinarySearchTree tree;
            total_time += fillContainer(tree, size);
        }

        double average_time = total_time / attempts;
        std::cout << "Average fill time for " << size << " elements: " << average_time << " seconds" << std::endl;
    }

    return 0;
}