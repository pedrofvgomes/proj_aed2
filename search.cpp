#include <string>
#include <map>
#include <set>
#include "plan_trip.cpp"

int nCountries(const Airline& airline, const vector<Flight>& flights){
    set<string> countries;
    for(auto &i : flights){
        if(i.getAirline().getCode()==airline.getCode()){
            if(countries.find(i.getSource().getCountry())==countries.end())
                countries.insert(i.getSource().getCountry());
            if(countries.find(i.getTarget().getCountry())==countries.end())
                countries.insert(i.getTarget().getCountry());
        }
    }
    return countries.size();
}

void airlineMenu(map<string, Airline>& airlines, vector<Flight>& flights){
    int n = 1;
    while(true){
        system("cls");
        cout << "\n\n---- Pesquisar companhia ----";
        string code;
        cout << "\n\nCodigo: ";
        cin >> code;
        if(airlines.find(code)==airlines.end()) {
            cout << "\n\nNao existe nenhuma companhia com esse codigo\n\n\n\n\n\n0) Sair\n\n--> ";
            while(n!=0){cin>>n; if(n==0) break;}
        }
        else {
            auto a = airlines[code];
            list<Airline> temp;
            temp.push_back(a);
            cout << "\n- " + a.getName() + " (" + a.getCountry() + ")";
            cout << "\n\n\n\nPais de origem: " + a.getCountry();
            cout << "\n\nNumero de paises abrangidos: " << nCountries(a, flights);
            cout << "\n\nNumero de voos totais: " << createFlights(flights,temp).size();
            cout << "\n\n\n\n\n\n0) Voltar\n\n--> ";
            cin>>n;
            while(n!=0){cin>>n; if(n==0) break;}
        }
        break;
    }
}

void airportMenu(map<string, Airport>& a, vector<Flight>& flights){
    int n = 1;
    string cidade, cidade1;
    list<Airport> newairports;
    float lat, lon, r;
    while(true){
        system("cls");
        cout<< "\n\n---- Pesquisar aeroporto ----";
        //----- pesquisar por cidade -----
        cout << "\n\n1) Pesquisar por cidade";

        //----- pesquisar por pais -----
        cout << "\n\n2) Pesquisar por pais";

        //----- introduzir localizacao
        cout << "\n\n3) Introduzir localizacao e raio maximo";

        cout << "\n\n\n\n\n\n0) Sair\n\n--> ";

        cin >> n;
        if(n==0) break;

        if(n==1){
            system("cls");
            cout << "\n\nCidade: ";

            cin >> cidade;
            getline(cin,cidade1,'\n');
            cidade += cidade1;

            newairports = citySearch(cidade, a);
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
                // display começa aqui
                cout << it->getCity() + " (" + it->getCountry() + ") - " + it->getName();
            }
            break;
        }

        if(n==2){
            system("cls");
            cout << "\n\nPais: ";

            cin >> cidade;
            getline(cin,cidade1,'\n');
            cidade += cidade1;

            newairports = countrySearch(cidade, a);
            int count = 1;
            if(!newairports.empty()) for(auto &i: newairports){
                    cout << "\n\n" + to_string(count) + ") " + i.getName() + " (" + i.getCode() + ") - " + i.getCountry();
                    count++;
                }
            else cout << "\n\nNao ha aeroportos nesse pais";
            cout << "\n\n\n\n\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                // display começa aqui
                cout << it->getCity() + " (" + it->getCountry() + ") - " + it->getName();
            }
            break;
        }

        if(n==3){
            system("cls");
            cout << "\n\nLatitude: ";
            cin >> lat;
            cout << "\n\nLongitude: ";
            cin >> lon;
            cout << "\n\nRaio maximo: ";
            cin >> r;
            newairports = coordinateSearch(lat,lon,r,a);
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
                // display começa aqui
                cout << it->getCity() + " (" + it->getCountry() + ") - " + it->getName();
            }
            break;
        }
    }
}

void searchMenu(map<string,Airline>& airlines, map<string, Airport>& airports, vector<Flight>& flights){
    Graph g;
    int n;
    for(auto &i : flights) g.addEdge(i);
    while(true){
        //--------------- cabeçalho ---------------//
        system("cls");
        cout << "\n\n---- Informacoes ----";

        //--------------- companhias ---------------//
        cout << "\n\n1) Companhias de aviacao";

        //--------------- aeroportos ---------------//
        cout << "\n\n2) Aeroportos";

        //--------------- paises ---------------//
        cout << "\n\n3) Paises";

        //--------------- rede global ---------------//
        cout << "\n\n4) Rede Global";

        cout << "\n\n\n\n\n\n0) Sair";
        //--------------- input ---------------//
        cout << "\n\n--> ";
        cin >> n;
        if (n == 0) break;

        //companhias
        if(n==1) airlineMenu(airlines, flights);

        //aeroportos
        if(n==2) airportMenu(airports, flights);

        //paises
        //if(n==3) countryMenu(airlines, airports, flights);

        //rede global
        //if(n==4) globalGraphMenu(airlines, airports, flights, g);
    }
}
