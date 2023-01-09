//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Lobo.h"
                                                                                                                                //aceder a variavel pai(Vlobo) ???
Lobo::Lobo(int id, int x, int y, int instante) : Animal('L', x, y, id, "bolt", 0, 25, 15, 1, 5, instante), momentonascer(rand() % (40 - (5) + 1) + (5)){

    temCria=0;
}
Lobo::Lobo(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist,int detet_dist, int instante): Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                           detet_dist, instante) {
    temCria=0;
}

void Lobo::verificaComportamento(Alimento* alimento, int instante){
    if(alimento->getcheiro() == "carne"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-alimento->getToxicidade());
        adiciona_Alimento(alimento);
        alimento->setComido(1);
    }
    if(getSaude() == 0)
        setMorte(true);
    setFome(getFome()+2);
    if(getFome() > 25){
        setSaude(getSaude()-2);
    }else if(getFome() > 15){
        setSaude(getSaude()-2);
        setMov_dist(2);
    }
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

        return new Lobo(-getID(),x,y,instante);//id -1 e como se nao tivesse id
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

