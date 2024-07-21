#include "io_test.h"

template<typename T>
bool test(T actual, T expected, int n) {
    if (actual == expected) {
        std::cout << "Test " << n << " passed!" << std::endl;
        return true;
    } else {
        std::cout << "Test " << n << " failed." << std::endl;
        return false;
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void testLoadMatrix() {
    std::vector<std::vector<int>> actual = loadGraph("test/test_graphs/graph1.txt");
    std::vector<std::vector<int>> expected = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    bool test1 = test(actual, expected, 1);
    if (!test1) {
        std::cout << "Expected: " << std::endl;
        printMatrix(expected);
        std::cout << "Actual: " << std::endl;
        printMatrix(actual);
    }

    actual = loadGraph("test/test_graphs/graph2.txt");
    expected = {
        {0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 1, 0},
        {1, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0}
    };
    bool test2 = test(actual, expected, 2);
    if (!test2) {
        std::cout << "Expected: " << std::endl;
        printMatrix(expected);
        std::cout << "Actual: " << std::endl;
        printMatrix(actual);
    }

    actual = loadGraph("test/test_graphs/graph3.txt");
    std::vector<std::vector<int>> expectedEmpty;
    bool test3 = test(actual, expectedEmpty, 3);
    if (!test3) {
        std::cout << "Expected: " << std::endl;
        printMatrix(expectedEmpty);
        std::cout << "Actual: " << std::endl;
        printMatrix(actual);
    }

    if (test1 && test2 && test3) {
        std::cout << "Test Load Matrix Passed!" << std::endl;
    } else {
        std::cout << "Test Load Matrix Failed." << std::endl;
    }

    return;
}