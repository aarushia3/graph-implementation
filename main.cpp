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

    // Testing insert edge and remove edge
    std::cout << "Below is the adjacency matrix: " << std::endl;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << adjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    // testing getVertices
    std::cout << std::endl;
    std::cout << "Here is the vertex list: " << std::endl;
    for (unsigned i = 0; i < vertices.size(); i ++) {
        std::cout << vertices[i] << " ";
    }
    std::cout << std::endl;

    // testing getEdgeWeights
    std::cout << "Here are all the edge weights (can be used for Kruskal's!)" << std::endl;
    for (unsigned i = 0; i < edgeWeights.size(); i ++) {
        std::cout << edgeWeights[i] << " ";
    }
    std::cout << std::endl;

    // testing copy assignment operator
    std::cout << "Below is the new copied adjacency matrix: " << std::endl;
    Graph f = g;
    std::vector<std::vector<int>> adjMatrix2 = f.getAdjacencyMatrix();
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << adjMatrix2[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    // testing removeEdge
    g.removeEdge(0, 1);
    std::vector<std::vector<int>> newAdjMatrix = g.getAdjacencyMatrix();
    std::cout << "Edge removed - adjacency matrix: " << std::endl;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            std::cout << newAdjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    // testing removeVertex
    g.insertEdge(0,1,3);
    g.insertEdge(1,2,7);
    g.insertEdge(0,2,5);
    g.insertEdge(1,0,1);
    g.insertEdge(2,1,4);
    g.insertEdge(2,0,8);
    std::cout << "New adjacency matrix: " << std::endl;
    std::vector<std::vector<int>> moreAdjMatrix = g.getAdjacencyMatrix();
    for (int i = 0; i < (int)moreAdjMatrix.size(); i ++){
        for (int j = 0; j < (int)moreAdjMatrix.size(); j ++){
            std::cout << moreAdjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    g.removeVertex(2);
    moreAdjMatrix = g.getAdjacencyMatrix();
    std::cout << "Vertex removed - adjacency matrix: " << std::endl;
    for (int i = 0; i < (int)moreAdjMatrix.size(); i ++){
        for (int j = 0; j < (int)moreAdjMatrix.size(); j ++){
            std::cout << moreAdjMatrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    return 0;
}