#include "graph.h"
#include <cmath>
#include "flight.h"

Graph::Graph(int nodes, bool dir){
    hasDir = dir;
    n = nodes;
}

void Graph::addEdge(const Flight& f) {
    Airport a1 = f.getSource();
    Airport a2 = f.getTarget();
    //check if the source node already exists in the graph
    for(auto i: nodes) if
}

float distance(float lat1, float lon1, float lat2, float lon2){
    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    float a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}