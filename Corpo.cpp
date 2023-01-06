//
// Created by ricar on 27/12/2022.
//

#include "Corpo.h"
Corpo::Corpo(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                                     const string &cheiro): Alimento(especie,x,y,id,val_nutritivo,toxicidade,cheiro){}
Corpo::Corpo(int id, int valorNutritivo, int x, int y) : Alimento('p', x,y, id, valorNutritivo, 0, "carne"){
    valorNutritivoInicial = valorNutritivo;
}

void Corpo::verificaComportamento(int instante){
    setValorNutritivo(getValorNutritivo()-1);
    if(2*(instante-getInstanteInicial()) < valorNutritivoInicial)
        setToxicidade(getToxicidade()+1);
}

Corpo::~Corpo(){

}