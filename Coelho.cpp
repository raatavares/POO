//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Coelho.h"

Coelho::Coelho(int id, int x, int y, int instante=0) : Animal('C', x, y, id, "pantufas", 0, 20, (1 + rand() % 4), 1, 4, instante) {
    cout<<"procria["<<id<<"]";
    morre = 30;
}
Coelho::Coelho(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist, int detet_dist, int instante=0) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                           detet_dist, instante) {

}


void Coelho::verificaComportamento(int instante){
    return;
}

Coelho::~Coelho(){

}

Animal * Coelho::procria(int instante)  {
    int prob = rand() % 101;
    if ((getTempo()+instante)%8==0 && prob>50){
        int x= getX()+rand()%(10-(-10)+1) +(-10);
        if(x<0) x=0;
        int y= getY()+rand()%(10-(-10)+1) +(-10);
        if(y<0) y=0;
        return new Coelho(-getID(), x, y, 0);//id -1 e como se nao tivesse id

    }else return nullptr;
}




