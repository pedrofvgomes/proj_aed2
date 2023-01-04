#include <iostream>
#include <map>
#include "airport.cpp"
#include "airline.cpp"
#include "flight.cpp"
#include "setup.cpp"
using namespace std;

int main() {
    map<string, Airline> airlines = setupAirlines();
    for(auto i:airlines){
        cout<<i.first;
        cout<< " ";
        cout<<i.second.getCode();
        cout<<i.second.getName();
        cout<<i.second.getCallsign();
        cout<<i.second.getCountry()<<endl;
    }
    return 0;
}
