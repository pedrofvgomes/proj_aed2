#include "graph.h"
#include "flight.h"
#include <queue>
using namespace std;

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

list<Flight> getTrip(Graph& g, const Airport& a1, const Airport& a2){

}

map<string, Graph::Node> Graph::getNodes() {return nodes;}

list<Graph::Node> Graph::bfs(const string& source, const string& target){
    //meter todos unvisited

    for(auto &i : nodes)
        { i.second.visited = false; i.second.distance = INT_MAX; i.second.previous = "";}
    //queue de aeroportos unvisited
    queue<string> q;

    //adicionar a partida à queue e metê-la visited
    q.push(source);
    nodes[source].visited = true;
    nodes[source].distance = 0;

    //enquanto a queue nao estiver vazia
    while(!q.empty()){
        //pegar no atual e remove-lo da queue
        string current = q.front();
        q.pop();
        //percorrer todos os vizinhos do current, adicionar os unvisited à queue e mete-los visited
        for(auto &i : nodes[current].adj){
            if(!nodes[i.target].visited){
                q.push(i.target);
                nodes[i.target].visited = true;
                nodes[i.target].distance = nodes[current].distance+1;
            }
        }
    }
}