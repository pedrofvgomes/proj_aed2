#include "airline.h"

Airline::Airline() {
    this->code = "";
    this->name = "";
    this->callsign = "";
    this->country = "";
}

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

string Airline::getCode() const {return code;}

string Airline::getName() const {return name;}

string Airline::getCallsign() const {return callsign;}

string Airline::getCountry() const {return country;}