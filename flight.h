#ifndef PROJ_AED2_FLIGHT_H
#define PROJ_AED2_FLIGHT_H

#include "airport.h"
#include "airline.h"

class Flight{
    Airport source;
    Airport target;
    Airline airline;
public:
    Flight();
    Flight(const Airport& source, const Airport& target, const Airline& airline);
    Airport getSource() const;
    Airport getTarget() const;
    Airline getAirline() const;
    void setSource(const Airport& a);
    void setTarget(const Airport& a);
    void setAirline(const Airline& a);
};

#endif