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
    int saude,peso,fome,id,mov_dist,detet_dist;
    int x,y;
    vector<Alimento*> consumo;
public:
    Animal(const char &especie,int x,int y,const int &id,const string &nome,int fome,int saude,int peso,const int &mov_dist,int detet_dist);

    const string &getNome() const;
    int getSaude() const;
    int getPeso() const;
    int getID() const;
    int getX() const;
    int getY() const;
    int getDetet_dist() const;
    void setX(int x);
    void setY(int y);
    int getMov_dist() const;
    string getEspecie() const;
    string getAlimentacao() const;
    void alimentaUser(int pontos_nutritivos,int toxicidade) ;

    void adiciona_Alimento(Alimento* a);

    void movimenta();


    string getAsString() const;
    string getToFile() const;

    virtual void verificaComportamento(int instante) = 0;

    virtual ~Animal();
};


#endif //TP_ANIMAL_H
