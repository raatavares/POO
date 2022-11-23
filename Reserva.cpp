//
// Created by Danie on 23/11/2022.
//

#include <iostream>
#include "Reserva.h"


void Reserva::recebeComando(const string &frase) {
    istringstream iss(frase);
    int i=1;
    string comand,n;
    iss>>comand;
    while (iss >> n)
        ++i;
    cout<<"->"<<i<<endl;

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

    else if(comand=="load"&&i==2) cout<<"valido"<<endl;

    else if(comand=="slide"&&i==3) cout<<"valido"<<endl;

    else if(comand=="exit"&&i==1) exit(EXIT_SUCCESS);

    else cout<<"invalido"<<endl;
}
