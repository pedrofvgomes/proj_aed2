#include "count.cpp"

void airlineMenu(unordered_map<string, Airline>& airlines, vector<Flight>& flights){
    int n = 1;
    while(true){
        system("cls");
        cout << "\n\n---- Pesquisar companhia ----";
        string code;
        cout << "\n\nCodigo: ";
        cin >> code;
        if(airlines.find(code)==airlines.end()) {
            cout << "\n\nNao existe nenhuma companhia com esse codigo\n\n-------------------\n\n0) Sair\n\n--> ";
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
            cout << "\n\n-------------------\n\n0) Sair\n\n--> ";
            cin>>n;
            while(n!=0){cin>>n; if(n==0) break;}
        }
        break;
    }
}

void airportMenu(unordered_map<string, Airport>& a, vector<Flight>& flights){
    int n;
    string cidade, cidade1;
    list<Airport> newairports;
    Airport airport;
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

        cout << "\n\n-------------------\n\n0) Sair\n\n--> ";

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
            cout << "\n\n-------------------\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                airport = *it;
            }
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
            cout << "\n\n-------------------\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                airport = *it;
            }
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
            cout << "\n\n-------------------\n\n0) Sair\n\n--> ";
            cin >> n;
            if(n>0){
                auto it = newairports.begin();
                for(int i = 1; i<n; i++){it++;}
                airport = *it;
            }
        }
        if(!airport.getCode().empty()){
            system("cls");
            cout << "\n\n--> " + airport.getCity() + " (" + airport.getCountry() + ") - " + airport.getName() + " <--";

            //pais
            cout << "\n\nPais: " + airport.getCountry();

            //numero de companhias
            cout << "\n\nNumero de companhias que passam por este aeroporto: " << nAirlines(airport,flights);

            //numero de paises atingiveis
            cout << "\n\nNumero de paises atingiveis a partir de este aeroporto: " << nReachableCountries(airport,flights);

            //numero de voos que de la saem
            cout << "\n\nNumero de voos que saem deste aeroporto: " << nFlightsOut(airport,flights);

            //numero de voos que la chegam
            cout << "\n\nNumero de voos que aterram neste aeroporto: " << nFlightsIn(airport,flights);


            cout << "\n\n\n0) Voltar\n\n--> ";
            cin>>n;
            while(n!=0){cin>>n; if(n==0) break;}
        }
    }
}

void countryMenu(unordered_map<string, Airline>& airlines, unordered_map<string, Airport>& airports, vector<Flight>& flights){
    int n = 1, nin, nout;
    while(true){
        system("cls");
        cout << "\n\n---- Pesquisar pais ----";
        string country, country1;
        cout << "\n\nNome do pais: ";
        cin >> country;
        getline(cin,country1,'\n');
        country += country1;

        //companhias
        cout << "\n\nNumero de companhias sediadas neste pais: " << nAirlinesCountry(country, airlines);

        //aeroportos
        cout << "\n\nNumero de aeroportos sediados neste pais: " << nAirportsCountry(country, airports);

        //voosIn
        cout << "\n\nNumero de voos que saem deste pais: " << nFlightsOutCountry(country, flights);

        //voosOut
        cout << "\n\nNumero de voos que aterram neste pais: " << nFlightsInCountry(country, flights);

        cout << "\n\n\n0) Voltar\n\n--> ";
        cin>>n;
        if(n==0) break;
    }
}

void searchMenu(unordered_map<string,Airline>& airlines, unordered_map<string, Airport>& airports, vector<Flight>& flights){
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

        cout << "\n\n-------------------\n\n0) Sair\n\n--> ";
        //--------------- input ---------------//
        cin >> n;
        //companhias
        if(n==1) airlineMenu(airlines, flights);

        //aeroportos
        if(n==2) airportMenu(airports, flights);

        //paises
        if(n==3) countryMenu(airlines, airports, flights);

        if(n<1 || n>3) break;
    }
}
