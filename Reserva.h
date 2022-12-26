#ifndef TP_RESERVA_H
#define TP_RESERVA_H
#include "animal.h"
#include <string.h>

class Reserva {
    vector<Animal*>animais;
    vector<Alimento*>alimentos;
    int SCoelho=20,SOvelha=30,SLobo=25,SCanguru=20;
    const int VCoelho=30,VOvelha=35,VLobo=40,VCanguru=70;
    int nLinhas, nColunas, L_inicial, C_inicial, mostra=20;

    int total;

    void recebeComandoPorFicheiro(const string &frase);
    void defineConstante(const string &frase);

public:
    Reserva(int linhas, int colunas);

    void recebeComando(const string &frase);
    void verReserva() const;

    void criaAnimal(const char &especie,int x = -1,int y = -1);
    void criaAlimento(const char &tipo,int x = -1,int y = -1);

    vector<Animal*> getAnimais() const;
    vector<Alimento*> getAlimentos() const;
    Alimento* getAlimento(int id) const;
    Animal* getAnimal(int id) const;
    int getS()const{return SLobo;}
    int getnLinhas() const;
    int getnColunas() const;
    int getL_inicial() const;
    int getC_inicial() const;
    void setL_inicial(int l);
    void setC_inicial(int c);
    void adicionaAlimento(Alimento *alimento);
    void adicionaAnimal(Animal *animal);
    void removerAlimento(int id);
    void removerAlimento(int linha, int coluna);
    void removerAnimal(int id);
    void removerAnimal(int linha, int coluna);
    string getAsString() const;
    string getAsStringPos(int linha,int coluna) const;
    bool existeAlimento(int x, int y) const;
    bool existeAnimal(int x, int y) const;

    ~Reserva();

};


#endif //TP_RESERVA_H
