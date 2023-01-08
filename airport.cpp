#include "airport.h"
#include <cmath>

/// Default constructor
Airport::Airport(){
    this->code = "";
    this->name = "";
    this->city = "";
    this->country = "";
    this->latitude = 0.0;
    this->longitude = 0.0;
}

/// Constructor with parameters
/// \param code
/// \param name
/// \param city
/// \param country
/// \param latitude
/// \param logitude
Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

/// getter of code
string Airport::getCode() const {return code;}
/// getter of name
string Airport::getName() const {return name;}
/// getter of city
string Airport::getCity() const {return city;}
/// getter of country
string Airport::getCountry() const {return country;}
/// getter of latitude
float Airport::getLatitude() const {return latitude;}
/// getter of longitude
float Airport::getLongitude() const {return longitude;}

/// Function that from the coordinates between 2 points determine distance in kilometers
/// \param latitude of first point
/// \param latitude of second point
/// \param longitude of first point
/// \param longitude of second point
/// \return distance in KM between points
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