#include "Pkm.hpp"
#include <iostream>
#include <cstring>

using namespace std;

int main(){

    string nome;
    mochila * m;
    treinador * t;

    cout << "Bem vindo ao mundo dos Pokemons!" << endl;
    limpa_dialogo();
    cout << "Qual é o seu nome?" << endl;
    cin >> nome;
    m = mochila_introducao(nome);
    limpa_dialogo();
    cout << "Seja bem vindo, " << m->nome << "!" << endl;
    //limpa_dialogo();
    cout << "Primeiro, eu devo te dar algumas coisas para começar sua jornada!" << endl;
    //limpa_dialogo();
    cout << "Você recebeu 10 pokebolas e R$1000,00!" << endl;
    //limpa_dialogo();
    cout << "Agora, eu devo te perguntar, qual pokemon você deseja escolher?" << endl;

    system("pause");

    return 0;

}