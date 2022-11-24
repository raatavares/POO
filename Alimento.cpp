#include "Alimento.h"
#include <iostream>

string Alimento::getTipo() const {
    if (tipo=='r') return "Relva";
    else if (tipo=='t') return "Cenoura";
    else if (tipo=='p') return "Corpo";
    else if (tipo=='b') return "Bife";
    else return "???";
}

Alimento::Alimento(const char &tipo, const Coord &coord, int val_nutritivo, int toxicidade, const int &tempo,const string &cheiro):tipo(tipo),
                                                                                                              coordnada(coord),
                                                                                                              val_nutritivo(val_nutritivo),
                                                                                                              toxicidade(toxicidade),
                                                                                                              tempo(tempo),
                                                                                                              cheiro(cheiro){}

int Alimento::getNutricao() const {
    return val_nutritivo;
}

int Alimento::getToxicidade() const {
    return toxicidade;
}

int Alimento::getTempo() const {
    return tempo;
}

int Alimento::getId() const
{
  return id;
};

Coord Alimento::getCoord() const {
    return coordnada;
}

string Alimento::getcheiro() const {
    return cheiro;
}

char Alimento::getTipoChar() const {
    return tipo;
}

string Alimento::getAsString() const {
    ostringstream oss;
    oss<<"Alimento) tipo:"<<getTipo()<<" | valor nutritivo:"<<val_nutritivo<<" | toxicidade:"<<toxicidade<<" | desparece no instante:"<<tempo<<" | coordenada:"<<coordnada.getAsString()<<" | cheiro:"<<cheiro<<endl;
    return oss.str();
}

Alimento::~Alimento() {
    cout << "Alimento do tipo " << getTipo() << " ingerido" << endl;
}