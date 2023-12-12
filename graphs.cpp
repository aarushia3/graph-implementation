#include "graphs.h"

Graph::Graph(){}

Graph::~Graph(){
    adjacencyMatrix.clear();
}

Graph::Graph(std::vector<std::vector<int>> givenMatrix){
    adjacencyMatrix = givenMatrix;
}

Graph& Graph::operator=(Graph& copy_from){
    adjacencyMatrix = copy_from.getAdjacencyMatrix();
    return *this;
}

void Graph::insertEdge(int u, int v, int edgeWeight){
    adjacencyMatrix[u][v] = edgeWeight;
    return;
}

void Graph::removeEdge(int u, int v){
    adjacencyMatrix[u][v] = -1;
    return;
}

void Graph::insertVertex(){
    adjacencyMatrix.resize(adjacencyMatrix.size() + 1);
    for (std::vector<int> v : adjacencyMatrix) {
        v.resize(v.size() + 1);
    }
    return;
}

void Graph::removeVertex(int u){
    adjacencyMatrix.resize(adjacencyMatrix.size() - 1);
    for (std::vector<int> v : adjacencyMatrix) {
        v.resize(v.size() - 1);
    }
    return;
}

std::vector<int> Graph::getIncidentEdges(int u){
    std::vector<int> edgeWeights;
    for (unsigned i = 0; i < getAdjacencyMatrix().size(); i ++){
        if (i != (unsigned)u) {
            edgeWeights.push_back(adjacencyMatrix[i][u]);
            edgeWeights.push_back(adjacencyMatrix[u][i]);
        }
    }
    return edgeWeights;
}

bool Graph::isAdjacent(int u, int v) {
    return (adjacencyMatrix[u][v] != -1);
}