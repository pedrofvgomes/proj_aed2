#include "airport.cpp"
#include "airline.cpp"
#include "flight.cpp"
#include "setup.cpp"
#include <iostream>
#include "plan_trip.cpp"
using namespace std;

int main() {
    int n;
    map<string, Airline> airlines = setupAirlines();
    map<string, Airport> airports = setupAirports();
    vector<Flight> flights = setupFlights(airports, airlines);
    while(true){
        system("cls");
        cout << "\n\n1) Planear viagem\n\n2) Pesquisa\n\n\n\n\n\n0) Sair\n\n--> ";
        cin >> n;
        if(n==1) planTripMenu(airlines, airports, flights);
        if(n==0) break;
    }
}