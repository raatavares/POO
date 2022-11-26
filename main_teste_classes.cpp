#include <iostream>
#include "Reserva.h"

int main() {
    string linha;
    Reserva reserva(50, 50);
    cout << endl;
    cout << reserva.getAsString();

    reserva.criaAlimento('b',0,0,5,1,20,"carne");
    reserva.criaAlimento('b',0,1,5,1,20,"carne");
    reserva.criaAnimal('C',1, 1,"nome",100,3,100,3);
    reserva.verReserva();
    cout << endl;
    cout << reserva.getAsString();
    cout<<endl;
    do{
        getline(cin, linha);
        reserva.recebeComando(linha);
    }while(linha != "exit");




    return 0;
}