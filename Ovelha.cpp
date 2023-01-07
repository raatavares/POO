//
// Created by ricar on 26/12/2022.
//

#include "Ovelha.h"

Ovelha::Ovelha(int id, int x, int y) : Animal('O', x,y, id, "ovelhaXoné", 0, 30, (4 + rand() % 8), 3,3){

    morre = 35;
}
Ovelha::Ovelha(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist,detet_dist){

}

void Ovelha::verificaAlimentacao(Alimento* alimento){
    if(alimento->getcheiro() == "erva"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-alimento->getToxicidade());
        alimento->setComido(1);
    }
    return;
}

Ovelha::~Ovelha(){

}