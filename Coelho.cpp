//
// Created by ricar on 26/12/2022.
//

#include "Coelho.h"

Coelho::Coelho(int id, int x, int y) : Animal('C', x,y, id, "pantufas", 0, 20, (1 + rand() % 4), 1,4){

    morre = 30;
}
Coelho::Coelho(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist,detet_dist){

}

void Coelho::verificaComportamento(int instante){
    return;
}

Coelho::~Coelho(){

}


