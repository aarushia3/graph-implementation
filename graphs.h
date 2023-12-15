#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
    
    private:
        // adjacency matrix to store the graph
        std::vector<std::vector<int>> adjacencyMatrix;

    public:
        // constructors, destructor, copy assignment
        Graph();
        ~Graph();
        Graph(std::vector<std::vector<int>> givenMatrix);
        Graph& operator=(Graph& copy_from);

        // basic graph functions
        void insertEdge(int u, int v, int edgeWeight);
        void removeEdge(int u, int v);
        void insertVertex();
        void removeVertex(int u);
        std::vector<int> getIncidentEdges(int u);
        bool isAdjacent(int u, int v);

        // some more graph functions
        std::vector<std::vector<int>>& getAdjacencyMatrix();
        int getDegree(int u);
        std::vector<int> getEdgeWeights();
        std::vector<int> getVertices();
        std::unordered_map<int, int> getEdgesWithVertices();

};