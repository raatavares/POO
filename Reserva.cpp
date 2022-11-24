//
// Created by Danie on 23/11/2022.
//
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
    if(comand=="animal" && i==2) cout<<"valido"<<endl;

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

    else if(comand=="info"&&i==2) cout<<"valido"<<endl;

    else if(comand=="n"&&i==1) cout<<"valido"<<endl;
    else if(comand=="n"&&i==2) cout<<"valido"<<endl;
    else if(comand=="n"&&i==3) cout<<"valido"<<endl;

    else if(comand=="anim"&&i==1) cout<<"valido"<<endl;

    else if(comand=="visanim"&&i==1) cout<<"valido"<<endl;

    else if(comand=="store"&&i==2) cout<<"valido"<<endl;

    else if(comand=="restore"&&i==2) cout<<"valido"<<endl;

    else if(comand=="load"&&i==2) cout<<"valido"<<endl;                // <- Fazer método para receber comandos por ficheiro

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


