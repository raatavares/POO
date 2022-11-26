#include <iostream>
#include "Reserva.h"

int main() {
    string linha;
    Reserva reserva(50, 50);


    reserva.criaAlimento('b',0,0,5,1,20,"carne");
    reserva.criaAlimento('b',0,1,5,1,20,"carne");
    reserva.criaAnimal('C',1, 1,"nome",100,3,100,3);


    cout << reserva.getAsString()<<endl<<endl;

    do{

        cout<<"insira comando: "<<endl;
        getline(cin, linha);
        reserva.recebeComando(linha);
    }while(1);




    return 0;
}