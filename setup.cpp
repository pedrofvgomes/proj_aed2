#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
/// split
/// \param s
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
/// setup airports

unordered_map<string, Airport> setupAirports(){
    unordered_map<string,Airport> airports;
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
/// setup airlines
unordered_map<string, Airline> setupAirlines(){
    unordered_map<string,Airline> airlines;
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
/// setup fligths
/// \param airports
/// \param airlines
vector<Flight> setupFlights(unordered_map<string,Airport>& airports,
                            unordered_map<string,Airline>& airlines){
    vector<Flight> flights;
    ifstream file;
    string line;

    file.open("flights.csv");
    getline(file, line);
    getline(file, line);
    while(line.size()>0){
        vector<string> s = split(line);
        flights.push_back(Flight(airports[s[0]], airports[s[1]], airlines[s[2]]));
        getline(file, line);
    }

    return flights;
}