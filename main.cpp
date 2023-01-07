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
        system("cls");
        cout << "1) Planear viagem\n\n2) Pesquisa\n\n\n\n\n\n0)Sair";
        cin >> n;
        if(n==1){
            Flight f = Flight();
            planTripMenu(f);
        }
        if(n==0) break;
    }
}
