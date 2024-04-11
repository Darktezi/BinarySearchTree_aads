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
    std::chrono::duration<double, std::milli> duration = end - start;

    return duration.count();
}

double containsInContainer(BinarySearchTree& tree, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();
        tree.contains(key);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

double insertAndEraseInContainer(BinarySearchTree& tree, int size) {
    double total_time = 0;

    for (int i = 0; i < size; ++i) {
        size_t key = lcg();

        auto start = std::chrono::high_resolution_clock::now();

        tree.insert(key);
        tree.erase(key);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        total_time += duration.count();
    }

    return total_time / size;
}

int main() {
    int sizes[] = { 1000, 10000, 100000 };
    int attempts = 100;

    for (int size : sizes) {
        double total_fill_time = 0;
        double total_search_time = 0;
        double total_insert_erase_time = 0;

        for (int i = 0; i < attempts; ++i) {
            BinarySearchTree tree;
            total_fill_time += fillContainer(tree, size);
            total_search_time += containsInContainer(tree, size);
            total_insert_erase_time += insertAndEraseInContainer(tree, size);
        }

        double average_time = total_fill_time / attempts;
        double average_search_time = total_search_time / attempts;
        double average_insert_erase_time = total_insert_erase_time / attempts;
        std::cout << "BST average search time for " << size << " elements: " << average_search_time << " milliseconds" << std::endl;
        std::cout << "BST average fill time for " << size << " elements: " << average_time << " milliseconds" << std::endl;
        std::cout << "BST average insert and erase time for " << size << " elements: " << average_insert_erase_time << " milliseconds" << std::endl;
    }

    return 0;
}