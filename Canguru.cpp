//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Canguru.h"

Canguru::Canguru(int id, int x, int y, int instante=0) : Animal('G', x, y, id, "canguru", 0, 20, 10, 7, 7, instante), morre(70){

    cout<<"nfen"<<id;
}
Canguru::Canguru(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
                 const int &mov_dist, int detet_dist, int instante=0) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                             detet_dist, instante) {

}

void Canguru::verificaComportamento(int instante){
    return;
}


Canguru::~Canguru(){

}

Animal * Canguru::procria(int instante)  {

    if ((getTempo()+instante)%30==0){
        int x= getX()+rand()%(3-(-3)+1) +(-3);
        if(x<0) x=0;
        int y= getY()+rand()%(3-(-3)+1) +(-3);
        if(y<0) y=0;
        return new Canguru(-getID(), x, y, 0);//id -1 e como se nao tivesse id
    }else return nullptr;
}
