#ifndef TP_RESERVA_H
#define TP_RESERVA_H
#include "animal.h"

class Reserva {
    vector<Animal*>animais;
    vector<Alimento*>alimentos;
    int SCoelho=20,SOvelha=30,SLobo=25,SCanguru=20;
    const int VCoelho=30,VOvelha=35,VLobo=40,VCanguru=70;

    void criaAnimal(const char &especie,int x,int y,const string &nome,int saude,int peso,int fome,const int &id,const int &mov_dist);
    void criaAlimento(const char &tipo,int x,int y,int val_nutritivo,int toxicidade,const int &tempo,const string &cheiro);

    void recebeComandoPorFicheiro(const string &frase);
    void defineConstante(const string &frase);

public:
    Reserva();
    void recebeComando(const string &frase);
    void verReserva() const;

    vector<Animal*> getAnimais() const;
    vector<Alimento*> getAlimentos() const;
    Alimento* getAlimento(int id) const;
    Animal* getAnimal(int id) const;
    void adicionaAlimento(Alimento *alimento);
    void adicionaAnimal(Animal *animal);
    void removerAlimento(int id);
    void removerAnimal(int id);
    string getAsString() const;
    bool existeAlimento(int x, int y) const;
    bool existeAnimal(int x, int y) const;

    ~Reserva();

};


#endif //TP_RESERVA_H