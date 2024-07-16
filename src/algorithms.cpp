#include <queue>
#include <unordered_map>
#include <vector>

#include "algorithms.h"

/* BFS Algorithm : returns a labelling of graph edges by making a new adjacency matrix
   which has the letters D for discovery edge, C for cross edge, U for unexplored. */

std::vector<std::vector<char>> BFS(Graph givenGraph) {
    int numVertices = (int)givenGraph.getAdjacencyMatrix().size();
    // map between vertex and <dist, pred>
    std::unordered_map<int, std::pair<int, int>> distsAndPreds;
    for (int i = 0; i < numVertices*numVertices; i ++) {
        // -1 signifies no predecessor
        distsAndPreds[i] = std::make_pair(-1, -1);
    }
    std::vector<char> row(numVertices, 'U');
    std::vector<std::vector<char>> edgeLabelling(numVertices, row);

    for (int i = 0; i < numVertices*numVertices; i ++) {
        if (distsAndPreds[i].first == -1) {
            BFShelper(givenGraph, edgeLabelling, distsAndPreds, i);
        }
    }

    return edgeLabelling;
}

void BFShelper(Graph givenGraph, std::vector<std::vector<char>>& edgeLabelling, 
               std::unordered_map<int, std::pair<int, int>>& distsAndPreds, int vertex) {
    std::queue<int> bfsQueue;
    distsAndPreds[vertex].first = 0;
    bfsQueue.push(vertex);

    while (!bfsQueue.empty()) {
        vertex = bfsQueue.front();
        bfsQueue.pop();

        for (int v : givenGraph.getAdjacentVertices(vertex)) {
            if (distsAndPreds[vertex].first == -1) {
                edgeLabelling[v][vertex] = 'D';
                distsAndPreds[v].second = vertex;
                distsAndPreds[v].first = distsAndPreds[vertex].first + 1;
                bfsQueue.push(v);
            } else {
                edgeLabelling[v][vertex] = 'C';
            }
        }
    }

    return;
}

Graph kruskalMST(Graph givenGraph) {
    std::vector<int> edgeWeights = givenGraph.getEdgeWeights();
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minheap;
    for (unsigned i = 0; i < edgeWeights.size(); i ++) {
        minheap.push(std::make_pair(i, edgeWeights[i]));
    }

    int numberOfVertices = (int)givenGraph.getVertices().size();

    DisjointSets vertices;
    vertices.addElements(numberOfVertices);

    Graph MST;

    while (MST.getVertices().size() < (numberOfVertices - 1)) {
        std::pair<int, int> uv = minheap.top();
        minheap.pop();
        int u = (uv.first) / (givenGraph.getAdjacencyMatrix().size());    // row number
        int v = (uv.first) % (givenGraph.getAdjacencyMatrix().size());    // column number
        if (vertices.find(u) != vertices.find(v)) {
            MST.insertEdge(u, v, uv.second);
            vertices.setUnion(vertices.find(u), vertices.find(u));
        }
    }

    return MST;

}