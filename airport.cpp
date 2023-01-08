#include "airport.h"
#include <cmath>

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


float d(float lat1, float lat2, float lon1, float lon2){
    float dLat = (lat2 - lat1) *
                 M_PI / 180.0;
    float dLon = (lon2 - lon1) *
                 M_PI / 180.0;


    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    float a = pow(sin(dLat / 2), 2) +
              pow(sin(dLon / 2), 2) *
              cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}