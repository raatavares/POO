//
// Created by ricar on 26/12/2022.
//

#include "Coelho.h"

Coelho::Coelho(Coord* coord, int id) : Animal('C', coord, id, "coelho", 20, (1+rand()%4), 4){
    fome = 1;
    morre = 30;
}

void Coelho::verificaComportamento(int instante){
    return;
}

Coelho::~Coelho(){

}