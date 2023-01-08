#ifndef PROJ_AED2_GRAPH_H
#define PROJ_AED2_GRAPH_H

#include <vector>
#include <list>
#include <string>
#include <map>
#include "flight.h"
using namespace std;

class Graph{
    struct Edge{
        //aeroporto de destino
        string target;
        //weight neste caso é distância, é automaticamente calculada de cada vez que adicionamos um adjacente
        float distance;
        //códigos das companhias que fazem este voo
        vector<string> airlines;
    };

    struct Node{
        vector<Edge> adj;
        bool visited;
        int distance;
        string previous;
    };

    //size
    int n;
    //string é o código do aeroporto, Node é o node correspondente
    map<string, Node> nodes;

public:
    Graph();
    void addEdge(const Flight& f);
    map<string,Node> getNodes();
    list<Node> bfs(const string& source, const string& target);
};

#endif