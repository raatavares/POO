#include "fstream"
#include "Reserva.h"

Reserva::Reserva(int linhas, int colunas):L_inicial(0), C_inicial(0), total(0) {
    if (linhas >= MIN && linhas <= MAX)
        this->nLinhas = linhas;
    else
        this->nLinhas = MIN+ (rand() % MAX);

    if( colunas >= MIN && colunas <= MAX)
        this->nColunas = colunas;
    else
        this->nColunas = MIN+ (rand() % MAX);

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
    instante = 0;
}

void Reserva::recebeComando(const string &frase) {
    istringstream iss(frase);
    vector<string>arg;

    int i=0, id, linha, coluna;
    string comand,n, nome;
    while (iss>>n){
        ++i;
        arg.push_back(n);
    }
    comand=*arg.begin();

    if(comand=="animal" && i==4) {
        linha = stoi(*(arg.begin()+2));
        coluna = stoi(*(arg.begin()+3));
        criaAnimal(*(*(arg.begin()+1)).c_str(),linha,coluna);
    }

    else if(comand=="animal" && i==2) {
        criaAnimal(*(*(arg.begin()+1)).c_str());
    }

    else if(comand=="kill" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAnimal(linha, coluna) == true){
            removerAnimal(linha, coluna);
        }
    }

    else if(comand=="killid" && i==2) {
        id = stoi(*(arg.begin()+1));
        removerAnimal(id);
    }

    else if(comand=="file" && i==1){
      cout<<"Nome do ficheiro:";
      cin>>nome;
      recebeComandoPorFicheiro(nome);
    }

    else if(comand=="food" && i==4) {
        linha = stoi(*(arg.begin()+2));
        coluna = stoi(*(arg.begin()+3));
        criaAlimento(*(*(arg.begin()+1)).c_str(),linha,coluna);
    }

    else if(comand=="food" && i==2) {
        criaAlimento(*(*(arg.begin()+1)).c_str());
    }

    else if(comand=="feed" && i==5) { cout << "valido" << endl; }
    else if(comand=="feedid" && i==4) cout<<"valido"<<endl;

    else if(comand=="nofood" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAlimento(linha, coluna) == true){
            removerAlimento(linha, coluna);
        }
    }

    else if(comand=="nofood" && i==2) {
        id = stoi(*(arg.begin()+1));
        removerAlimento(id);
    }

    else if(comand=="empty" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAlimento(linha, coluna) == true){
            removerAlimento(linha, coluna);
        }
        if(existeAnimal(linha, coluna) == true){
            removerAnimal(linha, coluna);
        }
    }

    else if(comand=="see" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        cout << getAsStringPos(linha, coluna) << endl;
    }

    else if(comand=="info" && i==2) {
        id = stoi(*(arg.begin()+1));
        if( getAnimal(id) != NULL){
            cout << getAnimal(id)->getAsString() << endl;
        }else if(getAlimento(id) != NULL)
            cout << getAlimento(id)->getAsString() << endl;
        else
            cout << "Nao existe" << endl;
    }

    else if(comand=="n" && i==1) {
        instante++;
        passaInstante(instante);
    }

    else if(comand=="n" && i==2) {
        for(int j = 0; j < stoi(*(arg.begin()+1)); j++){
            instante++;
            passaInstante(instante);
        }
    }

    else if(comand=="n" && i==3) {
        for(int j = 0; j < stoi(*(arg.begin()+1)); j++){
            instante++;
            passaInstante(instante);
            sleep(stoi(*(arg.begin()+2)));
        }

    }

    else if(comand=="anim" && i==1){
        for(int i = 0; i < animais.size(); i++){
            cout << animais[i]->getAsString();
        }
    }

    else if(comand=="visanim" && i==1){
        for(int i = 0; i < animais.size(); i++){
            if(animais[i]->getCoord()->getCoordX() >= L_inicial && animais[i]->getCoord()->getCoordY() > C_inicial && animais[i]->getCoord()->getCoordX() <= L_inicial+mostra && animais[i]->getCoord()->getCoordY() < C_inicial+mostra)
            cout << animais[i]->getAsString();
        }
    }

    else if(comand=="store" && i==2) cout<<"valido"<<endl;

    else if(comand=="restore" && i==2) cout<<"valido"<<endl;

    else if(comand=="slide" && i==3) {
        if(*(arg.begin()+1) == "up"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(L_inicial != 0)
                    L_inicial--;
                else{
                    L_inicial = nLinhas;
                }
            }
        }
        else if(*(arg.begin()+1) == "down"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(L_inicial != nLinhas)
                    L_inicial++;
                else{
                    L_inicial = 0;
                }
            }
        }
        else if(*(arg.begin()+1) == "right"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(C_inicial != nColunas)
                    C_inicial++;
                else{
                    C_inicial = 0;
                }
            }
        }
        else if(*(arg.begin()+1) == "left"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(C_inicial != 0)
                    C_inicial--;
                else{
                    C_inicial = nColunas;
                }
            }
        }
    }

    else if(comand=="exit" && i==1) {cout<<"[saindo...]"<<endl;exit(EXIT_SUCCESS);}


    else if(comand=="ver_reserva" && i==1) verReserva();
            // <- Fazer método para receber comandos por ficheiro

    else cout<<"invalido"<<endl;

    cout << getAsString();
}

void Reserva::passaInstante(int instante){
    for(int i = 0; i < animais.size(); i++){
        animais[i]->verificaComportamento(instante);
    }
    for(int i = 0; i < alimentos.size(); i++){
        alimentos[i]->verificaComportamento(instante);
    }
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
        cin.ignore();
    }

}

void Reserva::criaAnimal(const char &especie, int x, int y) {
    if (x == -1 && y == -1){
        x = rand() % nLinhas;
        y = rand() % nColunas;
    }
    if (toupper(especie) == 'C')
        adicionaAnimal(new Coelho(new Coord(x,y),total));
    else if (toupper(especie) == 'O')
        adicionaAnimal(new Ovelha(new Coord(x,y),total));
    else if (toupper(especie) == 'L')
        adicionaAnimal(new Lobo(new Coord(x,y),total));
    else if (toupper(especie) == 'G')
        adicionaAnimal(new Canguru(new Coord(x,y),total));
    else if (toupper(especie) == 'M')
        adicionaAnimal(new Misterio(new Coord(x,y),total));
    total++;
}

void Reserva::criaAlimento(const char &tipo, int x, int y) {
    if (x == -1 && y == -1){
        x = rand() % nLinhas;
        y = rand() % nColunas;
    }
    if (toupper(tipo) == 'R')
        adicionaAlimento(new Relva(new Coord(x,y),total));
    else if (toupper(tipo) == 'T')
        adicionaAlimento(new Cenoura(new Coord(x,y),total));
    else if (toupper(tipo) == 'B')
        adicionaAlimento(new Bife(new Coord(x,y),total));
    else if (toupper(tipo) == 'A')
        adicionaAlimento(new Alimento_misterio(new Coord(x,y),total));
    total++;
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

int Reserva::getnLinhas() const
{
    return nLinhas;
};

int Reserva::getnColunas() const
{
    return nColunas;
};

int Reserva::getL_inicial() const
{
    return L_inicial;
};

int Reserva::getC_inicial() const
{
    return C_inicial;
};

void Reserva::setL_inicial(int l)
{
    L_inicial = l;
};

void Reserva::setC_inicial(int c)
{
    C_inicial = c;
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

void Reserva::removerAlimento(int linha, int coluna)
{
    for (auto ptr = alimentos.begin(); ptr != alimentos.end(); ) {
        if ((*(ptr))->getCoord()->getCoordX() == linha && (*(ptr))->getCoord()->getCoordY() == coluna)
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

void Reserva::removerAnimal(int linha, int coluna)
{
    for (auto ptr = animais.begin(); ptr != animais.end(); ) {
        if ((*(ptr))->getCoord()->getCoordX() == linha && (*(ptr))->getCoord()->getCoordY() == coluna)
            ptr = animais.erase(ptr);
        else
            ptr++;
    }
};

string Reserva::getAsString() const
{
    ostringstream oss;
    int auxL=L_inicial, auxC=C_inicial;
    for(int i = 1; i <= mostra; i++){
        auxC = C_inicial;
        for(int j = 1; j <= mostra; j++){
            if(existeAlimento(auxL, auxC) == false && existeAnimal(auxL, auxC) == false){
                oss << '_';
            }else{
                for(int a = 0; a<alimentos.size(); a++){
                    if(alimentos[a]->getCoord()->getCoordX() == auxL && alimentos[a]->getCoord()->getCoordY() == auxC)
                        oss << alimentos[a]->getId();
                }
                for(int a = 0; a<animais.size(); a++){
                    if(animais[a]->getCoord()->getCoordX() == auxL && animais[a]->getCoord()->getCoordY() == auxC)
                        oss << animais[a]->getID();
                }
            }
            if (auxC == nColunas)
                auxC = 0;
            else
                auxC++;
        }
        if (auxL == nLinhas)
            auxL = 0;
        else
            auxL++;
        oss << endl;
    }
    return oss.str();
};

string Reserva::getAsStringPos(int linha,int coluna) const{
    ostringstream oss;
    oss << "Linha: " << linha << "Coluna: " << coluna << endl;
    if(existeAlimento(linha, coluna) == false)
        oss << "Nao existe alimentos nesta posicao" << endl;
    else{
        for(int i = 0; i < alimentos.size(); i++) {
            if(alimentos[i]->getCoord()->getCoordX() == linha && alimentos[i]->getCoord()->getCoordY() == coluna)
                oss << alimentos[i]->getAsString() << endl;
        }
    }
    if(existeAnimal(linha, coluna) == false)
        oss << "Nao existe animais nesta posicao" << endl;
    else{
        for(int i = 0; i < animais.size(); i++) {
            if(animais[i]->getCoord()->getCoordX() == linha && animais[i]->getCoord()->getCoordY() == coluna)
                oss << animais[i]->getAsString() << endl;
        }
    }
    return oss.str();
};


bool Reserva::existeAlimento(int x, int y) const
{
    for(int i = 0; i < alimentos.size(); i++){
        if(alimentos[i]->getCoord()->getCoordX() == x && alimentos[i]->getCoord()->getCoordY() == y)
            return true;
    }
    return false;
};

bool Reserva::existeAnimal(int x, int y) const
{
    for(int i = 0; i < animais.size(); i++){
        if(animais[i]->getCoord()->getCoordX() == x && animais[i]->getCoord()->getCoordY() == y)
            return true;
    }
    return false;
};



Reserva::~Reserva()
{
    animais.clear();
    alimentos.clear();
}




