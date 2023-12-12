#include "graphs.h"

Graph::Graph(){}

Graph::~Graph(){
    adjacencyMatrix.clear();
}

Graph::Graph(std::vector<std::vector<int>> givenMatrix){
    adjacencyMatrix = givenMatrix;
}

// not tested yet
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
    adjacencyMatrix.back().resize(adjacencyMatrix[0].size(), -1);

    for (std::vector<int>& v : adjacencyMatrix) {
        v.push_back(-1);
    }
}

// fix this!
void Graph::removeVertex(int u){
    adjacencyMatrix.resize(adjacencyMatrix.size() - 1);
    for (std::vector<int>& v : adjacencyMatrix) {
        v.resize(v.size() - 1);
    }
    return;
}

// not tested yet
std::vector<int> Graph::getIncidentEdges(int u){
    std::vector<int> edgeWeights;
    for (unsigned i = 0; i < getAdjacencyMatrix().size(); i ++){
        if (i != (unsigned)u) {
            if (adjacencyMatrix[i][u] != -1)
                edgeWeights.push_back(adjacencyMatrix[i][u]);
            if (adjacencyMatrix[u][i] != -1)
                edgeWeights.push_back(adjacencyMatrix[u][i]);
        }
    }
    return edgeWeights;
}

// not tested yet
bool Graph::isAdjacent(int u, int v) {
    return (adjacencyMatrix[u][v] != -1);
}

std::vector<std::vector<int>>& Graph::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

// not tested yet
int Graph::getDegree(int u){
    return (int)getIncidentEdges(u).size();
}

std::vector<int> Graph::getEdgeWeights(){
    std::vector<int> edgeWeights;
    for (unsigned i = 0; i < getAdjacencyMatrix().size(); i ++){
        for (unsigned j = 0; j < getAdjacencyMatrix().size(); j ++){
            if (adjacencyMatrix[i][j] != -1){
                edgeWeights.push_back(adjacencyMatrix[i][j]);
            }
        }
    }
    return edgeWeights;
}

std::vector<int> Graph::getVertices(){
    std::vector<int> vertices;
    for (int i = 0; i < (int)adjacencyMatrix.size(); i ++){
        vertices.push_back(i);
    }
    return vertices;
}