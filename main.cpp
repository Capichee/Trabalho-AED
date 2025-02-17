#include "Pkm.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    string nome;
    mochila* m;
    treinador* t;
    treinador* oponente;
    int escolha = 0, escolha_dentro = 0;
    char escolha_menu;

    oponente = (treinador*)malloc(sizeof(treinador));
    oponente->nextPkm = nullptr;
    oponente->count = 0;

    t = (treinador*)malloc(sizeof(treinador));
    t->nextPkm = nullptr;
    t->count = 0;

    banco_pokemon(oponente);

    system("clear");

    cout << "Bem-vindo ao mundo dos Pokémons!" << endl;
    limpa_dialogo();
    cout << "Qual é o seu nome?" << endl;
    cin >> nome;
    m = mochila_introducao(nome);
    limpa_dialogo();
    cout << "Seja bem-vindo, " << m->nome << "!" << endl;
    limpa_dialogo();
    cout << "Primeiro, eu devo te dar algumas coisas para começar sua jornada!" << endl;
    limpa_dialogo();
    cout << "Você recebeu 10 pokébolas e R$1000,00!" << endl;
    limpa_dialogo();
    cout << "Agora, eu devo te perguntar, qual Pokémon você deseja escolher?" << endl;
    limpa_dialogo();

    while (escolha < 1 || escolha > 3) {
        cout << "1 - Bulbasaur" << endl;
        cout << "2 - Charmander" << endl;
        cout << "3 - Squirtle" << endl;
        cin >> escolha;
        system("clear");
    }

     switch (escolha) {
        case 1:
            inicializa_pokemon(t, "Bulbasaur", "grama", "venenoso", 5, 0, 49, 49, 45, 45, 45);
            registra_move(&t->caughtPkm.ATKs, "Investida", 40, 100, 35, "normal");
            registra_move(&t->caughtPkm.ATKs, "Rosnado", 0, 100, 40, "normal");
            registra_move(&t->caughtPkm.ATKs, "Chicote de cipó", 30, 100, 25, "grama");
            registra_move(&t->caughtPkm.ATKs, "Folha Navalha", 35, 75, 35, "grama");
            break;
        case 2:
            inicializa_pokemon(t, "Charmander", "fogo", "fogo", 5, 0, 52, 43, 65, 39, 39);
            registra_move(&t->caughtPkm.ATKs, "Arranhar", 40, 100, 35, "normal");
            registra_move(&t->caughtPkm.ATKs, "Rosnado", 0, 100, 40, "normal");
            registra_move(&t->caughtPkm.ATKs, "Brasa", 40, 100, 25, "fogo");
            registra_move(&t->caughtPkm.ATKs, "Sopro do Dragão", 60, 75, 20, "fogo");
            break;
        case 3:
            inicializa_pokemon(t, "Squirtle", "agua", "agua", 5, 0, 48, 65, 43, 44, 44);
            registra_move(&t->caughtPkm.ATKs, "Cabeçada", 40, 100, 35, "normal");
            registra_move(&t->caughtPkm.ATKs, "Chicote de Cauda", 0, 100, 40, "normal");
            registra_move(&t->caughtPkm.ATKs, "Bala de Agua", 35, 100, 25, "agua");
            registra_move(&t->caughtPkm.ATKs, "Pulso de Agua", 45, 75, 20, "agua");
            break;
    }

    cout << "Você escolheu o Pokémon tipo " << t->caughtPkm.tipo1 << ", " << t->caughtPkm.nomePKM << "!" << endl;
    cin.get();
    limpa_dialogo();

    cout << "Agora, você está pronto para começar sua jornada! Boa sorte!" << endl;
    limpa_dialogo();

    cout << "Aperte z para acessar o menu de opções." << endl;
    cin >> escolha_menu;
    limpa_dialogo();

while(escolha_menu == 'z' || 'Z') {
    if(escolha_menu == 'z' || 'Z') {
        cout << "1 - Trocar Pokémon" << endl;
        cout << "2 - Comprar na loja." << endl;
        cout << "3 - Usar poções." << endl;
        cout << "4 - Entrar em batalha." << endl;
        cin >> escolha;
        system("clear");
        switch(escolha){
            case 1:{
                cout << "Trocar o primeiro pokemon com qual outro de sua equipe?" << endl;
                display_equipe(t, 0);
                cin >> escolha_dentro;
                troca_equipe(t, escolha_dentro);
                system("clear");
                cout << t->caughtPkm.nomePKM << " agora é o líder da equipe!" << endl;
                escolha_menu == 'l';
                break;
            }
            case 2:{
                loja(m);
                escolha_menu == 'l';
                break;
            }
            case 3:{
                cout << "Você tem " << m->pocao << " poções. Deseja usar uma?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> escolha;
                if(escolha == 1){
                    if(t->caughtPkm.hp < t->caughtPkm.hpmax){
                        t->caughtPkm.hp += 20;
                        m->pocao--;
                        cout << "Você usou uma poção e recuperou 20 de HP!" << endl;
                    } else {
                        cout << "Seu Pokémon já está com HP máximo!" << endl;
                    }
                } else {
                    cout << "Você não usou a poção." << endl;
                }
                escolha_menu == 'l';
                break;
            }
            case 4:{
                inicia_batalha(t, oponente, m);
                escolha_menu == 'l';
                break;
            }
        }
        cout << "Aperte z para acessar o menu de opções. E qualquer outra tecla pra sair." << endl;
        cin >> escolha_menu;
    }
}

 while (oponente != nullptr) {
        delete_pokemon(oponente->caughtPkm);
        treinador* temp = oponente;
        oponente = oponente->nextPkm;
        free(temp);
    }

    while (t != nullptr) {
        delete_pokemon(t->caughtPkm);
        treinador* temp = t;
        t = t->nextPkm;
        free(temp);
    }

    free(m);

    return 0;
}
