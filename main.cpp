#include <iostream>
#include "graphs.h"

void main() {
    std::cout << "Let's test my graph out!" << std::endl;
    Graph g;
    g.insertVertex();
    g.insertVertex();
    g.insertVertex();
    g.insertEdge(0,1,5);
    g.insertEdge(1,2,5);
    g.insertEdge(0,2,5);
    std::vector<int> vertices = g.getVertices();
    std::vector<int> edgeWeights = g.getEdgeWeights();
    std::vector<std::vector<int>> adjMatrix = g.getAdjacencyMatrix();

    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << adjMatrix[i][j];
        }
        std::cout << std::endl;
    }
    
    return;
}