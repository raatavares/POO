//
// Created by ricar on 26/12/2022.
//

#include "Misterio.h"

Misterio::Misterio(int id, int x, int y, int instante=0) : Animal('M', x, y, id, "surpresas", 0, 10, 7, 3, 3, instante) {

}
Misterio::Misterio(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
                   const int &mov_dist, int detet_dist, int instante=0) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                               detet_dist, instante) {

}
void Misterio::verificaComportamento(int instante){
    return;
}

Misterio::~Misterio(){

}