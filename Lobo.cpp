//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Lobo.h"
                                                                                                                                //aceder a variavel pai(Vlobo) ???
Lobo::Lobo(int id, int x, int y) : Animal('L', x, y, id, "bolt", 0, 25, 15, 1, 5, 0), momentonascer(rand() % (40 - (5) + 1) + (5)){
    cout<<"procria["<<id<<"]";
    temCria=0;
}
Lobo::Lobo(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist): Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                           detet_dist, 0) {
    temCria=0;
}

void Lobo::verificaComportamento(int instante){
    return;
}

Lobo::~Lobo(){

}

Animal * Lobo::procria(int instante) {
    if ((getTempo()+instante)%momentonascer==0 && temCria==0){

        int x= getX()+rand()%(15-(-15)+1) +(-15);
        if(x<0) x=0;
        int y= getY()+rand()%(15-(-15)+1) +(-15);
        if(y<0) y=0;
        temCria++;
        if (temCria ) cout<<"ndknd";
        return new Lobo(-getID(),x,y);//id -1 e como se nao tivesse id
    }else return nullptr;
}

void Lobo::interacaoAnimal(Animal *animal) {
    if(animal->getEspecieChar()!='L'){
        if(getFome()<=15)this->setMov(2);
        else this->setMov(3);
        if(animal->getY()> this->getY())this->setY(getY()+1);
        else if(animal->getY()< this->getY())this->setY(getY()-1);

        if(animal->getX()> this->getX())this->setX(getX()+1);
        else if(animal->getX()< this->getX())this->setX(getX()-1);
    }else{
        setMov(1);
        return;
    }
}

