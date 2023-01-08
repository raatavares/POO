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
    int criado_t;



public:
    Animal()=default;
    Animal(const char &especie, int x, int y, const int &id, const string &nome, int fome, int saude, int peso,
           const int &mov_dist, int detet_dist, int criado_t);

    const string &getNome() const;
    int getSaude() const;
    int getPeso() const;
    int getTempo() const;
    int getID() const;
    int getX() const;
    int getY() const;
    int getDetet_dist() const;
    int getFome() const;
    void setX(int x);
    void setY(int y);
    void setID(int newID);
    void setMov(int n);
    int getMov_dist() const;
    string getEspecie() const;
    char getEspecieChar() const;
    string getAlimentacao() const;
    void alimentaUser(int pontos_nutritivos,int toxicidade) ;

    void adiciona_Alimento(Alimento* a);
    virtual Animal* procria(int instante) ;

    void movimenta();



    virtual void interacaoAnimal(Animal *animal);

    string getAsString() const;
    string getToFile() const;

    virtual void verificaComportamento(int instante) = 0;

    virtual ~Animal();
};


#endif //TP_ANIMAL_H
