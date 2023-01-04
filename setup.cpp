#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string& s){
    vector<string> result;
    stringstream s_stream(s);
    while(s_stream.good()){
        string sub;
        getline(s_stream, sub, ',');
        result.push_back(sub);
    }
    return result;
}

map<string, Airport> setupAirports(){
    map<string,Airport> airports;
    string line;
    string code, name, city, country;
    float lat, lon;
    ifstream file;
    file.open("airports.csv");
    getline(file, line);
    getline(file, line);
    while(line.size()>0){
        vector<string> s = split(line);
        code = s[0];
        name = s[1];
        city = s[2];
        country = s[3];
        lat = stof(s[4]);
        lon = stof(s[5]);
        airports[code] = Airport(code, name, city, country, lat, lon);
        getline(file, line);
    }
    file.close();
    return airports;
}

map<string, Airline> setupAirlines(){
    map<string,Airline> airlines;
    string line;
    string code, name, callsign, country;
    ifstream file;
    file.open("airlines.csv");
    getline(file, line);
    getline(file, line);
    while(line.size()>0){
        vector<string> s = split(line);
        code = s[0];
        name = s[1];
        callsign = s[2];
        country = s[3];
        airlines[code] = Airline(code, name, callsign, country);
        getline(file, line);
    }
    file.close();
    return airlines;
}
