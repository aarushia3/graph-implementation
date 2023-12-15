#include <queue>
#include <unordered_map>

#include "algorithms.h"

Graph kruskalMST(Graph givenGraph) {
    std::vector<int> edgeWeights = givenGraph.getEdgeWeights();
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
    for (unsigned i = 0; i < edgeWeights.size(); i ++) {
        minheap.push(edgeWeights[i]);
    }

    int numberOfVertices = (int)givenGraph.getVertices().size();

    DisjointSets vertices;
    vertices.addElements(numberOfVertices);

    std::unordered_map<int, int> visited;
    Graph MST;

    while (MST.getVertices().size() < (numberOfVertices - 1)) {
        
    }

}