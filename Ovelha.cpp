//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Ovelha.h"

Ovelha::Ovelha(int id, int x, int y, int instante=0) : Animal('O', x, y, id, "ovelhaXoné", 0, 30, (4 + rand() % 8), 3, 3, instante) {

    morre = 35;
}
Ovelha::Ovelha(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist, int detet_dist, int instante=0) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                           detet_dist, instante), morre(35){
    cout<<"nasceu:-"<<getID()<<endl;
}

void Ovelha::verificaComportamento(int instante){
    return;
}

Ovelha::~Ovelha(){

}

Animal *Ovelha::procria(int instante) {

    if ((instante+getTempo())%15==0 ){
        int x= getX()+rand()%(12-(-12)+1) +(-12);
        if(x<0) x=0;
        int y= getY()+rand()%(12-(-12)+1) +(-12);
        if(y<0) y=0;
        //return new Ovelha(-getID(),x,y);//id -1 e como se nao tivesse id
        return new Ovelha(-getID(), x, y, 'O', "efnm", 0, 30, (4 + rand() % 8), 3, 3, 0);
    }else return nullptr;
}
