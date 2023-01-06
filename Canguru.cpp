//
// Created by ricar on 26/12/2022.
//

#include "Canguru.h"

Canguru::Canguru(int x,int y, int id) : Animal('G', x,y, id, "canguru",0, 20, 10, 7){
    morre = 70;
}
Canguru::Canguru(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist){

}

void Canguru::verificaComportamento(int instante){
    return;
}


Canguru::~Canguru(){

}