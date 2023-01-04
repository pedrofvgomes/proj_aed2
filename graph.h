#ifndef PROJ_AED2_GRAPH_H
#define PROJ_AED2_GRAPH_H

#include <vector>
#include <list>
#include <string>
#include <map>
using namespace std;

class Graph{
    struct Edge{
        string target;
        float distance;
    };

    struct Node{
        list<Edge> adj;
        bool visited;
    };

    int n;
    bool hasDir;
    map<string, Node> nodes;

public:
    Graph(int nodes, bool dir = false);
    void addEdge(int src, int dest, int weight = 1);
};

#endif
