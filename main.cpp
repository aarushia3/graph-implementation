#include <iostream>
#include "graphs.h"

int main() {
    std::cout << "Let's test my graph out!" << std::endl;
    Graph g;
    g.insertVertex();
    g.insertVertex();
    g.insertVertex();

    g.insertEdge(0,1,3);
    g.insertEdge(1,2,7);
    g.insertEdge(0,2,5);

    std::vector<int> vertices = g.getVertices();
    std::vector<int> edgeWeights = g.getEdgeWeights();
    std::vector<std::vector<int>> adjMatrix = g.getAdjacencyMatrix();

    std::cout << "Below is the adjacency matrix: " << std::endl;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << adjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Here is the vertex list: " << std::endl;
    for (unsigned i = 0; i < vertices.size(); i ++) {
        std::cout << vertices[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Here are all the edge weights (can be used for Kruskal's!)" << std::endl;
    for (unsigned i = 0; i < edgeWeights.size(); i ++) {
        std::cout << edgeWeights[i] << " ";
    }
    std::cout << std::endl;

    g.removeEdge(0, 1);
    std::vector<std::vector<int>> newAdjMatrix = g.getAdjacencyMatrix();
    std::cout << "Updated adjacency matrix: " << std::endl;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << newAdjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}