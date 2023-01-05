#include "flight.h"
#include "setup.cpp"

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