#include <list>
#include <string>
#include "airport.h"
#include <map>
#include <iostream>
#include "graph.cpp"
using namespace std;

//lista de aeroportos numa cidade

list<Airport> citySearch(const string& city, map<string,Airport>& airports){
    list<Airport> a;
    for(auto &i:airports)
        if(i.second.getCity()==city)
            a.push_back(i.second);
    return a;
}

//lista de aeroportos dentro de um raio x, a partir de uma coordenada fixa

list<Airport> coordinateSearch(const float& lat, const float& lon, const float& radius, map<string,Airport>& airports){
    list<Airport> a;
    for(auto &i:airports)
        if(d(lat, i.second.getLatitude(), lon, i.second.getLongitude()) <= radius)
            a.push_back(i.second);
    return a;
}

//criar um vetor de voos com restricao de companhias

vector<Flight> createFlights(vector<Flight>& flights, vector<string>& airlines){
    vector<Flight> newflights;
    for(auto &i: flights)
        for(auto a : airlines)
            if(i.getAirline().getCode()==a) newflights.push_back(i);
    return newflights;
}

void setAirport(int escolha, Flight& f, map<string, Airport>& airports){
    int n, temp;
    string city, city1;
    float lat,lon,r;
    list<Airport> newairports;
    while(true){
        system("cls");

        //----- pesquisar por cidade -----
        cout << "\n\n1) Pesquisar por cidade";

        //----- introduzir localizacao
        cout << "\n\n2) Introduzir localizacao e raio maximo";

        cout << "\n\n\n\n\n\n0) Sair\n\n--> ";

        cin >> n;
        if(n==0) break;

        if(n==1){
            system("cls");
            cout << "\n\nCidade: ";

            cin >> city;
            getline(cin,city1,'\n');
            city += city1;

            newairports = citySearch(city, airports);
            int count = 1;
            if(!newairports.empty()) for(auto &i: newairports){
                cout << "\n\n" + to_string(count) + ") " + i.getName() + " (" + i.getCode() + ") - " + i.getCountry();
                count++;
            }
            else cout << "\n\nNao ha aeroportos nessa cidade";
            cout << "\n\n\n\n\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                if(escolha==0) {
                    if(it->getCode()==f.getTarget().getCode()){
                        cout << "\n\nO aeroporto de partida nao pode ser igual ao de destino, prima qualquer tecla para voltar\n-->";
                        cin >> temp;
                    }
                    else f.setSource(*it);
                }
                else {
                    if(it->getCode()==f.getSource().getCode()){
                        cout << "\n\nO aeroporto de destino nao pode ser igual ao de destino, prima qualquer tecla para voltar\n-->";
                        cin >> temp;
                    }
                    else f.setTarget(*it);
                }
            }
            break;
        }

        if(n==2){
            system("cls");
            cout << "\n\nLatitude: ";
            cin >> lat;
            cout << "\n\nLongitude: ";
            cin >> lon;
            cout << "\n\nRaio maximo: ";
            cin >> r;
            newairports = coordinateSearch(lat,lon,r,airports);
            int count = 1;
            if(!newairports.empty()) for(auto &i: newairports){
                cout << "\n\n" + to_string(count) + ") " + i.getName() + " (" + i.getCode() + ") - " + i.getCountry();
                count++;
            }
            else cout << "\n\nNao ha aeroportos no raio indicado";
            cout << "\n\n\n\n\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                if(escolha==0) f.setSource(*it);
                else f.setTarget(*it);
            }
            break;
        }
    }
}

void addAirline(list<Airline>& newairlines, map<string, Airline>& airlines){
    // Airline a = searchAirline(airlines);
    // newairlines.push_back(a);
}

void removeAirline(list<Airline>& newairlines){
    int x=1, n;
    list<Airline> temp;
    for(auto &i : newairlines){
        cout<< "\n\n" << x << ") " + i.getName() + " (" + i.getCountry() + ")";
        x++;
    }
    cout << "\n\n\n\n\n\n0) Sair\n\n-> ";
    cin >> n;
    if(n>0){
        auto it = newairlines.begin();
        for(int i = 1; i<n; i++){temp.push_back(*it); it++;}
        it++;
        while(it!=newairlines.end()) {temp.push_back(*it);it++;}
        newairlines = temp;
    }
}

//menu de planeamento de viagem

void planTripMenu(map<string, Airline>& airlines, map<string, Airport>& airports, vector<Flight>& flights){
    Flight f = Flight();
    list<Airline> newairlines;
    int n, ready = 0;
    while(true){
        //--------------- cabeçalho ---------------//
        system("cls");
        cout << "\n\n---- Planear Viagem ----";


        //---- partida ----
        cout << "\n\nPartida: ";
        if (f.getSource().getCode() != "") cout << f.getSource().getCity() + " (" + f.getSource().getCountry() + ") - " + f.getSource().getName();


        //---- destino ----
        cout << "\n\nDestino: ";
        if (f.getTarget().getCode() != "") cout << f.getTarget().getCity() + " (" + f.getTarget().getCountry() + ") - " + f.getTarget().getName();


        //---- percurso ----
        cout << "\n\nPercurso: ";

        //--------------- filtros ---------------//
        cout << "\n\n---- Filtros ----";
        //---- definir partida ----
        cout << "\n\n1) Definir partida";


        //---- definir destino ----
        cout << "\n\n2) Definir destino";


        //---- escolher companhia(s) de aviação ----
        cout << "\n\n3) Adicionar companhia de aviacao\n\n4) Remover companhia de aviacao";


        cout << "\n\n\n\n\n\n0) Sair";
        //--------------- input ---------------//
        cout << "\n\n--> ";
        cin >> n;
        if (n == 0) break;

        //definir partida
        if(n==1) setAirport(0,f,airports);

        //definir destino
        if(n==2) setAirport(1,f,airports);

        //adicionar companhia
        if(n==3) addAirline(newairlines, airlines);

        //remover companhia
        if(n==4) removeAirline(newairlines);
    }
}

