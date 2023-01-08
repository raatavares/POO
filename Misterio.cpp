//
// Created by ricar on 26/12/2022.
//

#include "Misterio.h"

Misterio::Misterio(int id, int x, int y, int instante) : Animal('M', x, y, id, "surpresas", 0, 10, 7, 3, 3, instante) {

}
Misterio::Misterio(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
                   const int &mov_dist, int detet_dist, int instante) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                               detet_dist, instante) {

}
void Misterio::verificaComportamento(Alimento* alimento, int instante){
    if(alimento->getcheiro() == "corpo"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-2*(alimento->getToxicidade()));
        adiciona_Alimento(alimento);
        alimento->setComido(1);
    }
    if(getSaude() == 0)
        setMorte(true);
    if((instante-getInstanteInicial()) == 10)
        setMorte(true);
    setFome(getFome()+3);
    if(getFome() > 20){
        setSaude(getSaude()-4);
    }else if(getFome() > 10){
        setSaude(getSaude()-2);
        setMov_dist(5);
    }

    return;
}

Misterio::~Misterio(){

}