#include "airport.h"

Airport::Airport(){
    this->code = "";
    this->name = "";
    this->city = "";
    this->country = "";
    this->latitude = 0.0;
    this->longitude = 0.0;
}

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

string Airport::getCode() const {return code;}

string Airport::getName() const {return name;}

string Airport::getCity() const {return city;}

string Airport::getCountry() const {return country;}

float Airport::getLatitude() const {return latitude;}

float Airport::getLongitude() const {return longitude;}