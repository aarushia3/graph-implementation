#include "graph_class_test.h"

void testBasicAddRemove(Graph& testGraph) {
    std::vector<std::vector<int>> expected = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    bool test4 = test(testGraph.getAdjacencyMatrix(), expected, 4);
    if (!test4) {
        std::cout << "Expected: " << std::endl;
        printMatrix(expected);
        std::cout << "Actual: " << std::endl;
        printMatrix(testGraph.getAdjacencyMatrix());
    }

    testGraph.removeEdge(0, 2);
    testGraph.removeEdge(1,3);
    testGraph.insertVertex();
    testGraph.insertEdge(1,4,2);
    testGraph.removeVertex(2);
    expected = {
        {0, 1, 1, 0},
        {1, 0, 0, 2},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };
    bool test5 = test(testGraph.getAdjacencyMatrix(), expected, 5);
    if (!test5) {
        std::cout << "Expected: " << std::endl;
        printMatrix(expected);
        std::cout << "Actual: " << std::endl;
        printMatrix(testGraph.getAdjacencyMatrix());
    }
}

void testAdvancedFunctions(Graph testGraph) {
    std::vector<int> incidentEdges = testGraph.getIncidentEdges(1);
    std::vector<int> expected1 = {0, 3};
    // bool test6 = test(incidentEdges, expected1, 6);
    // if (!test6) {
        std::cout << "Expected: " << std::endl;
        printVector(expected1);
        std::cout << "Actual: " << std::endl;
        printVector(incidentEdges);
    // }
}

void testGraphFunctions() {
    // constructor
    std::vector<std::vector<int>> inputGraph = loadGraph("test/test_graphs/graph1.txt");
    Graph testGraph = Graph(inputGraph);
    testBasicAddRemove(testGraph);
    testAdvancedFunctions(testGraph);
}