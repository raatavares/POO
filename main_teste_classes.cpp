#include <iostream>
#include "Reserva.h"

int main() {
    string linha;
    Reserva reserva(50, 50);



    //reserva.criaAnimal('C',3, 8);
    reserva.criaAnimal('G',1, 8);




    cout << reserva.getAsString()<<endl<<endl;

    do{

        cout<<"insira comando: "<<endl;
        getline(cin, linha);
        reserva.recebeComando(linha);
    }while(1);




    return 0;
}