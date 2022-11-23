//
// Created by Danie on 23/11/2022.
//
#include <iostream>
#include "animal.h"

int main() {
    Alimento r('r',Coord(0,0)/*Cria e destroi e depois é que volta a criar*/,5,1,20,"carne");
    Alimento b('b',Coord(0,0),5,1,20,"carne");
    Animal a('C',Coord(1,1),"nome",100,3,100,1,3);
    cout<<endl<<r.getAsString();
    a.adicionaAlimento(b);
    a.adicionaAlimento(r);
    cout<<r.getToxicidade();
    cout<<endl<<a.getAlimentacao()<<endl;
    cout<<a.getAsString();
    return 0;
}