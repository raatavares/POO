#include <iostream>
#include "Reserva.h"

int main() {
    string linha;
    int num=1;
    Reserva reserva(50, 50);
    cout << endl;
    cout << reserva.getAsString();

    Coord coord1(0,0);
    Coord coord2(1,1);

    Alimento r('r',&coord1 /*Cria e destroi e depois é que volta a criar*/,5,1,20,"carne", num);
    num++;
    Alimento b('b',&coord1 ,5,1,20,"carne", num);
    num++;
    Animal a('C',&coord2 ,"nome",100,3,100,num,3);
    num++;
    reserva.adicionaAlimento(&r);
    reserva.adicionaAlimento(&b);
    reserva.adicionaAnimal(&a);

    reserva.verReserva();
    cout << endl;
    cout << reserva.getAsString();

    do{
        getline(cin, linha);
        reserva.recebeComando(linha);
    }while(linha != "exit");

    reserva.getAnimal(1)->adicionaAlimento(&b);
    reserva.getAnimal(1)->adicionaAlimento(&r);
    cout<<reserva.getAnimal(1)->getAlimentacao()<<endl;

    reserva.verReserva();

    return 0;
}