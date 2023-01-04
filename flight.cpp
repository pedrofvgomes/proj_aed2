#include "flight.h"
#include "setup.cpp"

Flight::Flight(string& source, string& target, string& airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}