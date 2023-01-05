#include "airport.cpp"
#include "airline.cpp"
#include "flight.cpp"
#include "setup.cpp"
#include "graph.cpp"
#include <iostream>
using namespace std;

int main() {
    auto airports = setupAirports();
    auto airlines = setupAirlines();
    auto flights = setupFlights(airports, airlines);
    Graph g;
    for(auto i:flights){
        g.addEdge(i);
    }
    cout << "rei";
}
