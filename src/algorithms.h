#include "graphs.h"
#include "dsets.h"

std::vector<std::vector<char>> BFS(Graph givenGraph);

void BFShelper(Graph givenGraph, std::vector<std::vector<char>>& edgeLabelling, 
               std::unordered_map<int, std::pair<int, int>>& distsAndPreds, int vertex);

Graph kruskalMST(Graph givenGraph);