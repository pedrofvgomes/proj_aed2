#include <string>
#include <map>
#include <set>
#include "plan_trip.cpp"

/// count number of country
/// \param airlines
/// \param flights
/// \return number of countries

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

/// count number of airlines
/// \param airports
/// \param flights
/// \return number of airlines

int nAirlines(const Airport& airport, const vector<Flight>& flights){
    set<string> airlines;
    for(auto &i : flights){
        if(i.getTarget().getCode() == airport.getCode() || i.getSource().getCode() == airport.getCode())
            if(airlines.find(i.getAirline().getCode())==airlines.end())
                airlines.insert(i.getAirline().getCode());
    }
    return airlines.size();
}

/// count number of reachable countries
/// \param airports
/// \param flights
/// \return number of reachable countries
int nReachableCountries(const Airport& airport, const vector<Flight>& flights){
    set<string> countries;
    for(auto &i: flights){
        if(i.getSource().getCode() == airport.getCode() && countries.find(i.getTarget().getCountry())==countries.end())
            countries.insert(i.getTarget().getCountry());
    }
    return countries.size();
}
/// count number of flights exit of airport
/// \param airports
/// \param flights
/// \return number of flights exit of airport
int nFlightsOut(const Airport& airport, const vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights){
        if(i.getSource().getCode()==airport.getCode()) resposta++;
    }
    return resposta;
}
/// count number of flights in of airport
/// \param airports
/// \param flights
/// \return number of flights in of airport
int nFlightsIn(const Airport& airport, const vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights){
        if(i.getTarget().getCode()==airport.getCode()) resposta++;
    }
    return resposta;
}

/// count number of airline headquartered in this country
/// \param country
/// \param airlines
/// \return number of airline headquartered in this country

int nAirlinesCountry(const string& country, unordered_map<string, Airline>& airlines){
    int resposta = 0;
    for(auto &i: airlines)
        if(i.second.getCountry()==country) resposta++;
    return resposta;
}
/// count number of airports in this country
/// \param country
/// \param airports
/// \return number of airports in this country
int nAirportsCountry(const string& country, unordered_map<string, Airport>& airports){
    int resposta = 0;
    for(auto &i: airports)
        if(i.second.getCountry()==country) resposta++;
    return resposta;
}

/// count number of flights in this country
/// \param country
/// \param flights
/// \return number of flights in this country
int nFlightsInCountry(const string& country, vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights)
        if(i.getTarget().getCountry()==country) resposta++;
    return resposta;
}
/// count number of flights for out this country
/// \param country
/// \param flights
/// \return number of flights for out this country
int nFlightsOutCountry(const string& country, vector<Flight>& flights){
    int resposta = 0;
    for(auto &i: flights)
        if(i.getSource().getCountry()==country) resposta++;
    return resposta;
}