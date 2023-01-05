#include <list>
#include <string>
#include "airport.h"
#include <map>
using namespace std;

list<Airport> citySearch(const string& city, map<string,Airport> airports){
    list<Airport> a;
    for(auto i:airports)
        if(i.second.getCity()==city)
            a.push_back(i.second);
    return a;
}