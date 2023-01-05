#include <list>
#include <string>
#include "airport.h"
#include <map>
#include "graph.cpp"
using namespace std;

list<Airport> citySearch(const string& city, map<string,Airport> airports){
    list<Airport> a;
    for(auto i:airports)
        if(i.second.getCity()==city)
            a.push_back(i.second);
    return a;
}

list<Airport> coordinateSearch(const float& lat, const float& lon, const float& radius, map<string,Airport> airports){
    list<Airport> a;
    for(auto i:airports)
        if(d(lat, i.second.getLatitude(), lon, i.second.getLongitude()) <= radius)
            a.push_back(i.second);
    return a;
}