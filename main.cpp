#include "airport.cpp"
#include "airline.cpp"
#include "flight.cpp"
#include "setup.cpp"
#include <iostream>
#include "search.cpp"
using namespace std;

int main() {
    int n;
    unordered_map<string, Airline> airlines = setupAirlines();
    unordered_map<string, Airport> airports = setupAirports();
    vector<Flight> flights = setupFlights(airports, airlines);
    while(true){
        system("cls");
        cout << "\n-------------------\n\n1) Planear viagem\n\n2) Informacoes\n\n-------------------\n\n0) Sair\n\n--> ";
        cin >> n;
        if(n==1) planTripMenu(airlines, airports, flights);
        if(n==2) searchMenu(airlines,airports,flights);
        if(n==0) break;
    }
}