#include <string>
#include <map>
#include <set>
#include "plan_trip.cpp"

int nCountries(const Airline& airline, const vector<Flight>& flights){
    set<string> countries;
    for(auto &i : flights){
        if(i.getAirline().getCode()==airline.getCode()){
            if(countries.find(i.getSource().getCountry())==countries.end())
                countries.insert(i.getSource().getCountry());
            if(countries.find(i.getTarget().getCountry())==countries.end())
                countries.insert(i.getTarget().getCountry());
        }
    }
    return countries.size();
}

int nAirlines(const Airport& airport, const vector<Flight>& flights){
    set<string> airlines;
    for(auto &i : flights){
        if(i.getTarget().getCode() == airport.getCode() || i.getSource().getCode() == airport.getCode())
            if(airlines.find(i.getAirline().getCode())==airlines.end())
                airlines.insert(i.getAirline().getCode());
    }
    return airlines.size();
}

int nReachableCountries(const Airport& airport, const vector<Flight>& flights){
    set<string> countries;
    for(auto &i: flights){
        if(i.getSource().getCode() == airport.getCode() && countries.find(i.getTarget().getCountry())==countries.end())
            countries.insert(i.getTarget().getCountry());
    }
    return countries.size();
}

int nFlightsOut(const Airport& airport, const vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights){
        if(i.getSource().getCode()==airport.getCode()) resposta++;
    }
    return resposta;
}

int nFlightsIn(const Airport& airport, const vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights){
        if(i.getTarget().getCode()==airport.getCode()) resposta++;
    }
    return resposta;
}

int nAirlinesCountry(const string& country, map<string, Airline>& airlines){
    int resposta = 0;
    for(auto &i: airlines)
        if(i.second.getCountry()==country) resposta++;
    return resposta;
}

int nAirportsCountry(const string& country, map<string, Airport>& airports){
    int resposta = 0;
    for(auto &i: airports)
        if(i.second.getCountry()==country) resposta++;
    return resposta;
}

int nFlightsInCountry(const string& country, vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights)
        if(i.getTarget().getCountry()==country) resposta++;
    return resposta;
}

int nFlightsOutCountry(const string& country, vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights)
        if(i.getSource().getCountry()==country) resposta++;
    return resposta;
}