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
//----------------------------------------------------------------------------------
//--------- vetor de companhias pode ser vector<Airline> ou vector<string> ---------
//----------------------------------------------------------------------------------

vector<Flight> airlineRestriction(vector<Flight> flights, vector<string> airlines){
    vector<Flight> newflights;
    for(auto i: flights)
        for(auto a : airlines)
            if(i.getAirline().getCode()==a) newflights.push_back(i);
    return newflights;
}