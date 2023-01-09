#ifndef TP_ANIMAL_H
#define TP_ANIMAL_H

#include "alimento.h"

//#include "terminal.h"
#include <string.h>

#include <vector>

using namespace std;

class Animal {
    char especie;
    string nome;
    int saude,peso,fome,id,mov_dist,detet_dist;
    int x,y;
    bool morte;
    vector<string*> consumo;
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
    int getInstanteInicial() const;
    bool getMorte() const;
    int getFome() const;
    int getDetet_dist() const;
    void setX(int x);
    void setY(int y);
    void setID(int newID);
    void setSaude(int saude);
    void setMorte(bool morte);
    void setFome(int fome);
    void setMov_dist(int mov);
    void setPeso(int peso);
    int getMov_dist() const;
    string getEspecie() const;
    char getEspecieChar() const;
    string getAlimentacao() const;
    void setMov(int n);
    void alimentaUser(int pontos_nutritivos,int toxicidade) ;

    void adiciona_Alimento(Alimento* a);
    virtual Animal* procria(int instante) ;

    void movimenta();


    virtual int getPai()const ;
    virtual void interacaoAnimal(Animal *animal);

    string getAsString() const;
    string getToFile() const;

    virtual void verificaComportamento(Alimento* alimento,int instante) = 0;

    virtual ~Animal();
};


#endif //TP_ANIMAL_H
