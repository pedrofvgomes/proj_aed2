#ifndef PROJ_AED2_AIRPORT_H
#define PROJ_AED2_AIRPORT_H

#include <string>
using namespace std;

class Airport{
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;
public:
    Airport();
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    string getCode() const;
    string getName() const;
    string getCity() const;
    string getCountry() const;
    float getLatitude() const;
    float getLongitude() const;
};

#endif