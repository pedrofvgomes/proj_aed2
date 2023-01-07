#include "graph.h"
#include <cmath>
#include "flight.h"

Graph::Graph(){
    n = 0;
}

float d(float lat1, float lat2, float lon1, float lon2){
    float latRad1 = M_PI * lat1 / 180.0;
    float latRad2 = M_PI * lat2 / 180.0;
    float lonRad1 = M_PI * lon1 / 180.0;
    float lonRad2 = M_PI * lon2 / 180.0;

    float diffLa = latRad2 - latRad1;
    float diffLo = lonRad2 - lonRad1;

    float computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(diffLo / 2) * sin(diffLo / 2)));
    return 2 * 6372.8 * computation;
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

        e.distance = d(f.getSource().getLatitude(), f.getTarget().getLatitude(), f.getSource().getLongitude(), f.getTarget().getLongitude());

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
            e.distance = d(f.getSource().getLatitude(), f.getTarget().getLatitude(), f.getSource().getLongitude(), f.getTarget().getLongitude());
            e.airlines = a;

            nodes[a1].adj.push_back(e);
        }
    }
}
