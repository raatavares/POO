//
// Created by ricar on 26/12/2022.
//

#include "Canguru.h"

Canguru::Canguru(Coord* coord, int id) : Animal('G', coord, id, "canguru", 20, 10, 7){
    morre = 70;
}

void Canguru::verificaComportamento(int instante){
    return;
}


Canguru::~Canguru(){

}