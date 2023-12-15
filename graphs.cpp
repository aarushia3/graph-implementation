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
    if ((u >= adjacencyMatrix.size()) || (v >= adjacencyMatrix.size()) || (u < 0) || (v < 0)) {
        std::cout << "Out of bounds, can't insert edge." << std::endl;
        return;
    }
    adjacencyMatrix[u][v] = edgeWeight;
    return;
}

void Graph::removeEdge(int u, int v){
    if ((u >= adjacencyMatrix.size()) || (v >= adjacencyMatrix.size()) || (u < 0) || (v < 0)) {
        std::cout << "Out of bounds, can't remove edge." << std::endl;
        return;
    }
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

void Graph::removeVertex(int u){
    if ((u >= adjacencyMatrix.size()) || (u < 0) ) {
        std::cout << "Out of bounds, can't remove vertex." << std::endl;
        return;
    }
    for (std::vector<int>& v : adjacencyMatrix) {
        v.erase(std::next(v.begin(), u));
    }
    adjacencyMatrix.erase(std::next(adjacencyMatrix.begin(), u));
    return;
}

std::vector<int> Graph::getIncidentEdges(int u){
    if ((u >= adjacencyMatrix.size()) || (u < 0) ) {
        std::cout << "Out of bounds, can't get incident edges." << std::endl;
        return std::vector<int>();
    }

    std::vector<int> edgeWeights;
    for (unsigned i = 0; i < getAdjacencyMatrix().size(); i ++){
        if (i != (unsigned)u) {
            // currently, incident edges is implied to mean edges coming out of the node
            if (adjacencyMatrix[i][u] != -1)
                edgeWeights.push_back(adjacencyMatrix[i][u]);
        }
    }
    return edgeWeights;
}

bool Graph::isAdjacent(int u, int v) {
    if ((u >= adjacencyMatrix.size()) || (v >= adjacencyMatrix.size()) || (u < 0) || (v < 0)) {
        std::cout << "Out of bounds! Returns false by default." << std::endl;
        return false;
    } else if (adjacencyMatrix[u][v] == -1) {
        return false;
    } else if (adjacencyMatrix[v][u] == -1) {
        return false;
    } else {
        return true;
    }
}

std::vector<std::vector<int>>& Graph::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

int Graph::getDegree(int u){
    if ((u >= adjacencyMatrix.size()) || (u < 0) ) {
        std::cout << "Out of bounds, can't get degree." << std::endl;
        return -1;
    }
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

std::unordered_map<int, int> Graph::getEdgesWithVertices() {
    std::vector<int> edgeWeights = getEdgeWeights();
    std::unordered_map<int, int> edgesAndVertices;
    for (unsigned i = 0; i < (getAdjacencyMatrix().size() * getAdjacencyMatrix().size()); i++) {
        edgesAndVertices[i] = edgeWeights[i];
    }
    return edgesAndVertices;
}