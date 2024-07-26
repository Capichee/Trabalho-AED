#include "Pkm.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main(){

    string nome;
    mochila * m;
    treinador * t;
    treinador * oponente;
    int escolha;

    system("clear");

    cout << "Bem vindo ao mundo dos Pokemons!" << endl;
    limpa_dialogo();
    cout << "Qual é o seu nome?" << endl;
    cin >> nome;
    m = mochila_introducao(nome);
    limpa_dialogo();
    cout << "Seja bem vindo, " << m->nome << "!" << endl;
    limpa_dialogo();
    cout << "Primeiro, eu devo te dar algumas coisas para começar sua jornada!" << endl;
    limpa_dialogo();
    cout << "Você recebeu 10 pokebolas e R$1000,00!" << endl;
    limpa_dialogo();
    cout << "Agora, eu devo te perguntar, qual pokemon você deseja escolher?" << endl;
    limpa_dialogo();


    //Aloca treinador
    t = (treinador *)malloc(sizeof(treinador));
    t->nextPkm = NULL;
    t->count = 0;

    while(escolha < 1 || escolha > 3){
        cout << "1 - Bulbasaur" << endl;
        cout << "2 - Charmander" << endl;
        cout << "3 - Squirtle" << endl;
        cin >> escolha;
        system("clear");
    }
    escolha_pokemon(escolha, t);
    cout << "Você escolheu o pokemon tipo " << t->caughtPkm.tipo1 << ", " << t->caughtPkm.nomePKM << "!" << endl;

    //cout << t->caughtPkm.atk << endl << t->caughtPkm.def << endl << t->caughtPkm.vel << endl << t->caughtPkm.hp << endl;

    free(t);

    return 0;

}
