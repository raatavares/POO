#include "Alimento.h"
#include <iostream>

string Alimento::getTipo() const {
    if (tipo=='r') return "Relva";
    else if (tipo=='t') return "Cenoura";
    else if (tipo=='p') return "Corpo";
    else if (tipo=='b') return "Bife";
    else return "???";
}

Alimento::Alimento(const char &tipo, int x, int y, const int id, int val_nutritivo, int toxicidade, const string &cheiro): tipo(tipo),
                                                                                                                  x(x), y(y),
                                                                                                                  val_nutritivo(val_nutritivo),
                                                                                                                  toxicidade(toxicidade),
                                                                                                                  cheiro(cheiro), id(id){
    instanteInicial = 0;
    morte = false;
    comido = 0;
}



int Alimento::getNutricao() const {
    return val_nutritivo;
}

int Alimento::getToxicidade() const {
    return toxicidade;
}

int Alimento::getInstanteInicial() const{
    return instanteInicial;
}

int Alimento::getValorNutritivo() const{
    return val_nutritivo;
}

bool Alimento::getMorte() const {
    return morte;
}

int Alimento::getId() const
{
  return id;
};

int Alimento::getX() const {
    return x;
}
int Alimento::getY() const {
    return y;
}

string Alimento::getcheiro() const {
    return cheiro;
}

int Alimento::getComido() const {
    return comido;
}

char Alimento::getTipoChar() const {
    return tipo;
}

void Alimento::setMorte(bool v) {
    this->morte = v;
}

void Alimento::setToxicidade(int toxicidade){
    this->toxicidade = toxicidade;
}

void Alimento::setValorNutritivo(int valorNutritivo){
    this->val_nutritivo = valorNutritivo;
}

void Alimento::setComido(int comido){
    this->comido = comido;
}

string Alimento::getAsString() const {
    ostringstream oss;
    oss<<"Alimento) tipo: "<<getTipo()<<" | valor nutritivo: "<<val_nutritivo<<" | toxicidade: "<<toxicidade<<" | coordenada: ("<<x<<","<<y<<") | cheiro: "<<cheiro<<endl;
    return oss.str();
}



Alimento::~Alimento() {
    //cout << "Alimento do tipo " << getTipo() << " ingerido" << endl;
}

string Alimento::getToFile() const {
    ostringstream oss;
    oss<<"Alimento "<<tipo<<" "<<val_nutritivo<<" "<<id<<" "<<instanteInicial<<" "<<toxicidade<<" "<<x<<" "<<y<<" "<<cheiro<<endl;
    return oss.str();
}






