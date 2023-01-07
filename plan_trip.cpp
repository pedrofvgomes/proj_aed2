#include <list>
#include <string>
#include "airport.h"
#include <map>
#include "graph.cpp"
using namespace std;

//lista de aeroportos numa cidade

list<Airport> citySearch(const string& city, map<string,Airport> airports){
    list<Airport> a;
    for(auto i:airports)
        if(i.second.getCity()==city)
            a.push_back(i.second);
    return a;
}

//lista de aeroportos dentro de um raio x, a partir de uma coordenada fixa

list<Airport> coordinateSearch(const float& lat, const float& lon, const float& radius, map<string,Airport> airports){
    list<Airport> a;
    for(auto i:airports)
        if(d(lat, i.second.getLatitude(), lon, i.second.getLongitude()) <= radius)
            a.push_back(i.second);
    return a;
}

//criar um grafo com restricao de companhias

vector<Flight> airlineRestriction(vector<Flight> flights, vector<string> airlines){
    vector<Flight> newflights;
    for(auto i: flights)
        for(auto a : airlines)
            if(i.getAirline().getCode()==a) newflights.push_back(i);
    return newflights;
}


//menu de planeamento de viagem

void planTripMenu(Flight& f){
    int n;
    while(true){
        //--------------- cabeçalho ---------------//
        system("cls");
        cout << "\n\n---- Planear Viagem ----";


        //---- partida ----
        cout << "\n\nPartida:  ";
        if (f.getSource().getCode() != "") cout << f.getSource().getCity() + " (" + f.getSource().getCountry() + ")\n";


        //---- destino ----
        cout << "\n\nDestino: ";
        if (f.getTarget().getCode() != "") cout << f.getTarget().getCity() + " (" + f.getTarget().getCountry() + ")\n";


        //---- percurso ----
        if (f.getTarget().getCode() != "") cout << "\n\nPercurso: ";

        //--------------- filtros ---------------//
        cout << "\n\n\n\n---- Filtros ----";
        //---- definir partida ----
        cout << "\n\n1) Definir partida";


        //---- definir destino
        cout << "\n\n2) Definir destino";


        //---- escolher companhia(s) de aviação ----
        cout << "\n\n3) Escolher companhias de aviacao";


        cout << "\n\n\n\n\n\n0) Sair";
        //--------------- input ---------------//
        cout << "\n\n-->";
        cin >> n;
        if (n == 0) break;
    }
}