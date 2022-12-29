//
// Created by ricar on 26/12/2022.
//

#include "Lobo.h"

Lobo::Lobo(Coord* coord, int id) : Animal('L', coord, id, "lobo", 25, 15, 5){
    fome = 2;
}

void Lobo::verificaComportamento(int instante){
    return;
}

Lobo::~Lobo(){

}