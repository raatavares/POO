//
// Created by ricar on 27/12/2022.
//

#include "Bife.h"

Bife::Bife(Coord* coord, int id) : Alimento('b', coord, id, 10, 2, "carne,ketchup"){
    duracao = 30;
}

void Bife::verificaComportamento(int instante){
    if(getValorNutritivo() > 0)
        setValorNutritivo(getValorNutritivo()-1);
}

Bife::~Bife(){

}