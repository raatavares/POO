#ifndef TP_ANIMAL_H
#define TP_ANIMAL_H

#include "alimento.h"
//#include "terminal.h"
#include "coord.h"
#include <vector>

using namespace std;

class Animal {
    char especie;
    string nome;
    int saude,peso,fome,id,mov_dist;
    Coord *coordenada;
    vector<Alimento*> consumo;
public:
    Animal(const char &especie,Coord* coord,const string &nome,int saude,int peso,int fome,const int &id,const int &mov_dist);

    const string &getNome() const;
    int getSaude() const;
    int getPeso() const;
    int getFome() const;
    int getID() const;
    Coord* getCoord() const;
    int getMov_dist() const;
    string getEspecie() const;
    string getAlimentacao() const;

    void adicionaAlimento(Alimento* a);

    string getAsString() const;

    ~Animal();
};


#endif //TP_ANIMAL_H
