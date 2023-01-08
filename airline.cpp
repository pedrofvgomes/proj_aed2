#include "airline.h"

/// Default constructor
Airline::Airline() {
    this->code = "";
    this->name = "";
    this->callsign = "";
    this->country = "";
}
/// Default constructor


/// Constructor with parameters
/// \param code
/// \param name
/// \param callsign
/// \param country
Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}
/// getter of code

string Airline::getCode() const {return code;}
/// getter of name
string Airline::getName() const {return name;}
/// getter of callsign
string Airline::getCallsign() const {return callsign;}
/// getter of country
string Airline::getCountry() const {return country;}