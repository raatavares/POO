//
// Created by ricar on 27/12/2022.
//

#include "Corpo.h"

Corpo::Corpo(Coord* coord, int id, int valorNutritivo) : Alimento('p', coord, id, valorNutritivo, 0, "carne"){
    valorNutritivoInicial = valorNutritivo;
}

void Corpo::verificaComportamento(int instante){
    setValorNutritivo(getValorNutritivo()-1);
    if(2*(instante-getInstanteInicial()) < valorNutritivoInicial)
        setToxicidade(getToxicidade()+1);
}

Corpo::~Corpo(){

}