#include "graph.h"
#include <cmath>
#include "flight.h"

Graph::Graph(){
    n = 0;
}

void Graph::addEdge(const Flight& f) {
    string a1 = f.getSource().getCode();
    string a2 = f.getTarget().getCode();
    string air = f.getAirline().getCode();
    //se nao existir
    if(nodes.find(a1)==nodes.end()){
        n++;
        Edge e;

        e.target = a2;

        e.distance = d(f);

        vector<string> v;
        v.push_back(air);
        e.airlines = v;

        Node node;
        vector<Edge> a;
        a.push_back(e);

        node.adj = a;
        node.visited = false;

        nodes[a1] = node;
    }

    //existe
    else{
        Node node = nodes[a1];
        int exists = 0;

        //target tambem existe
        for(auto &i:node.adj) if(i.target == a2) {
            i.airlines.push_back(air);
            exists = 1;
        }

        //target ainda nao existe
        if(exists==0){
            n++;
            Edge e;
            vector<string> a;
            a.push_back(air);

            e.target = a2;
            e.distance = d(f);
            e.airlines = a;

            nodes[a1].adj.push_back(e);
        }
    }
}

float Graph::d(const Flight& f){
    float lat1 = f.getSource().getLatitude();
    float lat2 = f.getTarget().getLatitude();
    float lon1 = f.getSource().getLongitude();
    float lon2 = f.getTarget().getLongitude();


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