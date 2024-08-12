#define CATCH_CONFIG_RUNNER
#include "test/graph_class_test.h"
#include "test/io_test.h"
#include <iostream>
#include <fstream>

int main() {
    testLoadMatrix();
    testGraphFunctions();
    // std::vector<std::vector<int>> matrix = loadGraph("input_graph.txt");

    // std::cout << "Below is the adjacency matrix: " << std::endl;
    // for (int i = 0; i < 4; i ++){
    //     for (int j = 0; j < 4; j ++){
    //         std::cout << matrix[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }
    
    // Testing Kruskal's using NetworkX!!

    // std::cout << "Let's test my graph out!" << std::endl;
    // Graph g;

    // // test for inserting vertex
    // g.insertVertex();
    // g.insertVertex();
    // g.insertVertex();

    // // test for inserting edge
    // g.insertEdge(0,1,3);
    // g.insertEdge(1,2,7);
    // g.insertEdge(0,2,5);

    // // test for getAdjacencyMatrix
    // std::vector<std::vector<int>> adjMatrix = g.getAdjacencyMatrix();

    // std::cout << "Below is the adjacency matrix: " << std::endl;
    // for (int i = 0; i < 3; i ++){
    //     for (int j = 0; j < 3; j ++){
    //         std::cout << adjMatrix[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    // // testing getVertices
    // std::vector<int> vertices = g.getVertices();
    // std::cout << std::endl;
    // std::cout << "Here is the vertex list: " << std::endl;
    // for (unsigned i = 0; i < vertices.size(); i ++) {
    //     std::cout << vertices[i] << " ";
    // }
    // std::cout << std::endl;

    // // testing getEdgeWeights
    // std::vector<int> edgeWeights = g.getEdgeWeights();
    // std::cout << "Here are all the edge weights (can be used for Kruskal's!)" << std::endl;
    // for (unsigned i = 0; i < edgeWeights.size(); i ++) {
    //     std::cout << edgeWeights[i] << " ";
    // }
    // std::cout << std::endl;

    // // testing copy assignment operator
    // std::cout << "Below is the new copied adjacency matrix: " << std::endl;
    // Graph f = g;
    // std::vector<std::vector<int>> adjMatrix2 = f.getAdjacencyMatrix();
    // for (int i = 0; i < 3; i ++){
    //     for (int j = 0; j < 3; j ++){
    //         std::cout << adjMatrix2[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    // // testing removeEdge
    // g.removeEdge(0, 1);
    // std::vector<std::vector<int>> newAdjMatrix = g.getAdjacencyMatrix();
    // std::cout << "Edge removed - adjacency matrix: " << std::endl;
    // for (int i = 0; i < 3; i ++){
    //     for (int j = 0; j < 3; j ++){
    //         std::cout << newAdjMatrix[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    // // testing removeVertex
    // g.insertEdge(0,1,3);
    // g.insertEdge(1,2,7);
    // g.insertEdge(0,2,5);
    // g.insertEdge(1,0,1);
    // g.insertEdge(2,1,4);
    // g.insertEdge(2,0,8);
    // std::cout << "New adjacency matrix: " << std::endl;
    // std::vector<std::vector<int>> moreAdjMatrix = g.getAdjacencyMatrix();
    // for (int i = 0; i < (int)moreAdjMatrix.size(); i ++){
    //     for (int j = 0; j < (int)moreAdjMatrix.size(); j ++){
    //         std::cout << moreAdjMatrix[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    // // testing isAdjacent
    // bool adjacentTest = g.isAdjacent(2,1);
    // if (adjacentTest) {
    //     std::cout << "Test 1 for isAdjacent passed!" << std::endl;
    // } else {
    //     std::cout << "Test 1 for isAdjacent failed." << std::endl;
    // }

    // bool adjacentTest2 = g.isAdjacent(2,2);
    // if (!adjacentTest2) {
    //     std::cout << "Test 2 for isAdjacent passed!" << std::endl;
    // } else {
    //     std::cout << "Test 2 for isAdjacent failed." << std::endl;
    // }

    // int degree = g.getDegree(0);
    // std::cout << degree << std::endl;
    // if (degree == 2) {
    //     std::cout << "Test for getDegree passed!" << std::endl;
    // } else {
    //     std::cout << "Test for getDegree failed." << std::endl;
    // }

    // g.removeVertex(2);
    // moreAdjMatrix = g.getAdjacencyMatrix();
    // std::cout << "Vertex removed - adjacency matrix: " << std::endl;
    // for (int i = 0; i < (int)moreAdjMatrix.size(); i ++){
    //     for (int j = 0; j < (int)moreAdjMatrix.size(); j ++){
    //         std::cout << moreAdjMatrix[i][j] << " | ";
    //     }
    //     std::cout << std::endl;
    // }

    // return 0;
}