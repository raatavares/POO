//
// Created by ricar on 26/12/2022.
//

#include "Lobo.h"

Lobo::Lobo(int id, int x, int y) : Animal('L', x,y, id, "bolt", 0, 25, 15, 5,5){

}
Lobo::Lobo(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist,detet_dist){

}

void Lobo::verificaAlimentacao(Alimento* alimento){
    if(alimento->getcheiro() == "carne"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-alimento->getToxicidade());
        alimento->setComido(1);
    }
    return;
}

Lobo::~Lobo(){

}