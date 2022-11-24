#include "fstream"
#include <iostream>
#include "Reserva.h"

Reserva::Reserva() {
    ifstream file;
    string frase;
    file.open("constantes.txt");
    if (!file.is_open())
        cout<<"Erro ao abrir ficheiro de constante, usando constantes default"<<endl;
    else{
        while (getline(file,frase)){
            defineConstante(frase);
        }
        file.close();
    }
}

void Reserva::recebeComando(const string &frase) {
    istringstream iss(frase);
    vector<string>arg;

    int i=0;
    string comand,n;
    while (iss>>n){
        ++i;
        arg.push_back(n);
    }
    comand=*arg.begin();


    if(comand=="animal" && i==4) cout<<"valido"<<endl;
    else if(comand=="animal" && i==2) cout<<"valido"<<endl;

    else if(comand=="animal_teste" && i==10) criaAnimal(*(arg.begin()+1)->c_str(),stoi(*(arg.begin()+2)),stoi(*(arg.begin()+3)),*(arg.begin()+4),stoi(*(arg.begin()+5)),stoi(*(arg.begin()+6)),stoi(*(arg.begin()+7)),stoi(*(arg.begin()+8)),stoi(*(arg.begin()+9)));
    else if(comand=="food_teste" && i==8) criaAlimento(*(arg.begin()+1)->c_str(),stoi(*(arg.begin()+2)),stoi(*(arg.begin()+3)),stoi(*(arg.begin()+4)),stoi(*(arg.begin()+5)),stoi(*(arg.begin()+5)),*(arg.begin()+6));


    else if(comand=="kill"&&i==3) cout<<"valido"<<endl;
    else if(comand=="killid"&&i==2) cout<<"valido"<<endl;

    else if(comand=="food"&&i==4) cout<<"valido"<<endl;
    else if(comand=="food"&&i==2) cout<<"valido"<<endl;

    else if(comand=="feed"&&i==5) cout<<"valido"<<endl;
    else if(comand=="feedid"&&i==4) cout<<"valido"<<endl;

    else if(comand=="nofood"&&i==3) cout<<"valido"<<endl;
    else if(comand=="nofood"&&i==2) cout<<"valido"<<endl;

    else if(comand=="empty"&&i==3) cout<<"valido"<<endl;

    else if(comand=="see"&&i==3) cout<<"valido"<<endl;

    else if(comand=="ver_reserva"&&i==1) verReserva();

    else if(comand=="info"&&i==2) cout<<"valido"<<endl;

    else if(comand=="n"&&i==1) cout<<"valido"<<endl;
    else if(comand=="n"&&i==2) cout<<"valido"<<endl;
    else if(comand=="n"&&i==3) cout<<"valido"<<endl;

    else if(comand=="anim"&&i==1) cout<<"valido"<<endl;

    else if(comand=="visanim"&&i==1) cout<<"valido"<<endl;

    else if(comand=="store"&&i==2) cout<<"valido"<<endl;

    else if(comand=="restore"&&i==2) cout<<"valido"<<endl;

    else if(comand=="load"&&i==2) recebeComandoPorFicheiro(*(arg.begin()+1));              // <- Fazer método para receber comandos por ficheiro

    else if(comand=="slide"&&i==3) cout<<"valido"<<endl;

    else if(comand=="exit"&&i==1) exit(EXIT_SUCCESS);

    else cout<<"invalido"<<endl;
}

void Reserva::defineConstante(const string &frase) {

    string const_name[4]={"SCoelho","SOvelha","SLobo","SCanguru"};
    int* c[4]={&SCoelho,&SOvelha,&SLobo,&SCanguru};
    istringstream iss(frase);
    int i=1;
    string constante,n;
    iss>>constante;
    while (iss >> n){
        ++i;
    }
    for (int j = 0; j < 4; ++j) {
        if(constante==const_name[j]){
            *c[j]= stoi(n);

        }
    }

}

void Reserva::recebeComandoPorFicheiro(const string &ficheiro) {
    ifstream file;
    string linha;
    file.open(ficheiro);
    if (!file.is_open())
        cout<<"Erro ao abrir ficheiro de comandos"<<endl;
    else{
        while (getline(file,linha)){
            recebeComando(linha);
        }
        file.close();
    }
}

void Reserva::criaAnimal(const char &especie,int x,int y,const string &nome,int saude,int peso,int fome,const int &id,const int &mov_dist) {
    Animal a(especie,Coord(x,y),nome,saude,peso,fome,id,mov_dist);
    animais.push_back(&a);
}

void Reserva::criaAlimento(const char &tipo, int x, int y, int val_nutritivo, int toxicidade, const int &tempo,
                           const string &cheiro) {
    Alimento a(tipo,Coord(x,y),val_nutritivo,toxicidade,tempo,cheiro);
    alimentos.push_back(&a);
}

void Reserva::verReserva() const {
    cout<<"----------- Animais -----------"<<endl<<endl;
    for(auto it:animais){
        cout<<it->getAsString()<<endl;
    }
    cout<<endl<<"---------- Alimentos ----------"<<endl<<endl;
    for(auto it:alimentos){
        cout<<it->getAsString()<<endl;
    }
}


vector<Animal*> Reserva::getAnimais() const
{
    return animais;
};

vector<Alimento*> Reserva::getAlimentos() const
{
    return alimentos;
};

Alimento* Reserva::getAlimento(int id) const
{
    for(int i=0 ; i < alimentos.size(); i++){
        if(alimentos[i]->getId() == id)
            return alimentos[i];
    }
    return NULL;
};

Animal* Reserva::getAnimal(int id) const
{
    for(int i=0 ; i < animais.size(); i++){
        if(animais[i]->getID() == id)
            return animais[i];
    }
    return NULL;
};

void Reserva::adicionaAlimento(Alimento *alimento)
{
    alimentos.push_back(alimento);
};

void Reserva::adicionaAnimal(Animal *animal)
{
    animais.push_back(animal);
};

void Reserva::removerAlimento(int id)
{
    for (auto ptr = alimentos.begin(); ptr != alimentos.end(); ) {
        if ((*(ptr))->getId() == id)
            ptr = alimentos.erase(ptr);
        else
            ptr++;
    }
};

void Reserva::removerAnimal(int id)
{
    for (auto ptr = animais.begin(); ptr != animais.end(); ) {
        if ((*(ptr))->getID() == id)
            ptr = animais.erase(ptr);
        else
            ptr++;
    }
};

string Reserva::getAsString() const
{
    return "test";
};

bool Reserva::existeAlimento(int x, int y) const
{
    for(int i = 0; i < alimentos.size(); i++){
        if(alimentos[i]->getCoord().getCoordX() == x && alimentos[i]->getCoord().getCoordY() == y)
            return true;
    }
    return false;
};

bool Reserva::existeAnimal(int x, int y) const
{
    for(int i = 0; i < animais.size(); i++){
        if(animais[i]->getCoord().getCoordX() == x && animais[i]->getCoord().getCoordY() == y)
            return true;
    }
    return false;
};



Reserva::~Reserva()
{
    animais.clear();
    alimentos.clear();
}


