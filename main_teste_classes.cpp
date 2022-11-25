#include <iostream>
#include "Reserva.h"

int main() {
    Reserva reserva;

    Alimento r('r',Coord(0,0)/*Cria e destroi e depois é que volta a criar*/,5,1,20,"carne");
    Alimento b('b',Coord(0,0),5,1,20,"carne");
    Animal a('C',Coord(1,1),"nome",100,3,100,1,3);
    reserva.adicionaAlimento(&r);
    reserva.adicionaAlimento(&b);
    reserva.adicionaAnimal(&a);

    reserva.verReserva();

    reserva.getAnimal(1)->adicionaAlimento(&b);
    reserva.getAnimal(1)->adicionaAlimento(&r);
    cout<<reserva.getAnimal(1)->getAlimentacao()<<endl;

    reserva.verReserva();

    return 0;
}