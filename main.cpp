#include "airport.cpp"
#include "airline.cpp"
#include "flight.cpp"
#include "setup.cpp"
#include <iostream>
#include "plan_trip.cpp"
using namespace std;

int main() {
    int n;
    while(true){
        cout << "1) Planear viagem\n\n2) Pesquisa\n\n\n\n\n\n0)Sair";
        cin >> n;
        if(n==1){
            Flight f = Flight();
            while(true){
                //--------------- cabeçalho ---------------//
                system("cls");
                cout << "\n\n-- Planear Viagem --";


                //---- partida ----
                cout << "\n\nPartida ->";
                if(f.getSource().getCode()!="") cout << f.getSource().getCity() + " (" + f.getSource().getCountry() + ")\n";


                //---- destino ----
                cout << "\n\nDestino ->";
                if(f.getTarget().getCode()!="") cout << f.getTarget().getCity() + " (" + f.getTarget().getCountry() + ")\n";


                //---- percurso ----


                //--------------- filtros ---------------//
                //---- definir partida ----



                //---- definir destino



                //---- escolher companhia(s) de aviação ----






                //--------------- input ---------------//
                cin >> n;
                if(n==0) {n=1; break;}
            }
        }


        if(n==0) break;
    }
}
