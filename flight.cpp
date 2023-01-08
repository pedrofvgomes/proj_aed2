#include "flight.h"
#include <list>
#include "graph.h"
#include <iostream>
using namespace std;

Flight::Flight() {
    this->source = Airport();
    this->target = Airport();
    this->airline = Airline();
}

Flight::Flight(const Airport& source, const Airport& target, const Airline& airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}

Airport Flight::getSource() const {return source;}
Airport Flight::getTarget() const {return target;}
Airline Flight::getAirline() const {return airline;}

void Flight::setAirline(const Airline &a) {this->airline = a;}
void Flight::setSource(const Airport &a) {this->source = a;}
void Flight::setTarget(const Airport &a) {this->target = a;}

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

void displayTrip(const list<pair<string,string>>& trip, map<string, Airport>& airports){
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

bool validTrip(const list<pair<string,string>>& trip){
    return true;
}