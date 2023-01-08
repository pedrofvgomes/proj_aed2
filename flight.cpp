#include "flight.h"
#include <list>
#include "graph.h"
#include <iostream>
#include <unordered_map>

using namespace std;
/// Default constructor
Flight::Flight() {
    this->source = Airport();
    this->target = Airport();
    this->airline = Airline();
}
/// Constructor with parameters
/// \param source airport
/// \param target airport
/// \param airline of travel
Flight::Flight(const Airport& source, const Airport& target, const Airline& airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}
/// getter of source airport
Airport Flight::getSource() const {return source;}
/// getter of target airport
Airport Flight::getTarget() const {return target;}
/// getter of airline of travel
Airline Flight::getAirline() const {return airline;}
/// setter of airline
void Flight::setAirline(const Airline &a) {this->airline = a;}
/// setter of source airport
void Flight::setSource(const Airport &a) {this->source = a;}
/// setter of target airport
void Flight::setTarget(const Airport &a) {this->target = a;}

/// shortest fligth
/// \param source
/// \param target
/// \param graph
/// \return list of shor flight possible

list<pair<string,string>> shortestFlight(const string& source, const string& target, Graph& g){
    //inicializar a lista
    list<pair<string,string>> resposta;
    //ir ao node do destino
    string current;
    auto nodes = g.getNodes();
    auto currentnode = nodes[target];
    current = target;
    while(current!=source){
        resposta.push_back({current,currentnode.airline});
        current = currentnode.previous;
        currentnode = nodes[current];
        if(current==source) resposta.push_back({current,currentnode.airline});
        if(current=="") break;
    }
    list<pair<string,string>> temp;
    auto it = resposta.end();
    it--;
    while(it!=resposta.begin()){
        temp.push_back(*it);
        it--;
    }
    temp.push_back(*it);
    list<pair<string,string>> empty;
    return temp.size()==1? empty : temp;
}
/// shortest display trip
/// \param trip
/// \param airports

void displayTrip(const list<pair<string,string>>& trip, unordered_map<string, Airport>& airports){
    auto it = trip.begin();
    if(trip.size()>=2){
        cout << (*it).first + " (" + airports[(*it).first].getCity() + ")";
        it++;
        while(it!=trip.end()){
            cout << " --|" + (*it).second + "|--> "+ (*it).first + " (" + airports[(*it).first].getCity() + ")";
            it++;
        }
    }
}
/// shortest valid trip
/// \param trip
bool validTrip(const list<pair<string,string>>& trip){
    return true;
}