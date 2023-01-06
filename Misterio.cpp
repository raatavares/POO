//
// Created by ricar on 26/12/2022.
//

#include "Misterio.h"

Misterio::Misterio(int id, int x, int y) : Animal('M', x,y, id, "surpresas", 0, 10, 7, 3){

}
Misterio::Misterio(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist): Animal(especie, x,y, id, nome, fome, saude, peso, mov_dist){

}
void Misterio::verificaComportamento(int instante){
    return;
}

Misterio::~Misterio(){

}