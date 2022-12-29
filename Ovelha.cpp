//
// Created by ricar on 26/12/2022.
//

#include "Ovelha.h"

Ovelha::Ovelha(Coord* coord, int id) : Animal('O', coord, id, "ovelha", 30, (4+rand()%8), 3){
    fome = 1;
    morre = 35;
}

void Ovelha::verificaComportamento(int instante){
    return;
}

Ovelha::~Ovelha(){

}