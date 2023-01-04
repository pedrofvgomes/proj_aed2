#ifndef PROJ_AED2_FLIGHT_H
#define PROJ_AED2_FLIGHT_H

#include "airport.h"
#include "airline.h"

class Flight{
    string source;
    string target;
    string airline;
public:
    Flight();
    Flight(string& source, string& target, string& airline);
    Airport getSource() const;
    Airport getTarget() const;
    Airline getAirline() const;
};

#endif