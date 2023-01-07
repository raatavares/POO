//
// Created by ricar on 26/12/2022.
//

#include <cstring>
#include <string.h>
#include "Coelho.h"

Coelho::Coelho(int id, int x, int y) : Animal('C', x,y, id, "pantufas", 0, 20, (1 + rand() % 4), 1,4){

    morre = 30;
}
Coelho::Coelho(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist,detet_dist){

}

void Coelho::verificaAlimentacao(Alimento* alimento){
    if(alimento->getcheiro() == "verdura"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-alimento->getToxicidade());
        alimento->setComido(1);
    }
    return;
}

Coelho::~Coelho(){

}


