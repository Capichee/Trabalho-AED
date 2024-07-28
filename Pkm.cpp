#include <cstring>
#include "Pkm.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

mochila* mochila_introducao(const std::string& Nome) {
    mochila* m = (mochila*)malloc(sizeof(mochila));
    m->nome = Nome;
    m->pokebolas = 10;
    m->dinheiro = 1000.0;
    return m;
}

void limpa_dialogo() {
    do {
        std::cout << '\n' << "Aperte ENTER para continuar.";
    } while (std::cin.get() != '\n');
    system("clear");
}

void registra_pokemon(treinador* t) {
    while (t->nextPkm != NULL) {
        t = t->nextPkm;
    }
    t->nextPkm = (treinador*)malloc(sizeof(treinador));
    t->nextPkm->nextPkm = NULL;
    t->nextPkm->count = t->count + 1;
}

void registra_move(moves* m, const std::string& move, int power, int acc, int pp, const std::string& type) {
    while (m->nextMove != NULL) {
        m = m->nextMove;
    }
    m->nextMove = (moves*)malloc(sizeof(moves));
    m->nextMove->nextMove = NULL;
    m->move = move;
    m->power = power;
    m->acc = acc;
    m->pp = pp;
    m->type = type;
    m->moveIndex = m->moveIndex + 1;
}

void banco_pokemon(treinador* t) {
    registra_pokemon(t);
    t->caughtPkm.lvl = 5;
    t->caughtPkm.exp = 0;
    t->caughtPkm.atk = 65;
    t->caughtPkm.def = 49;
    t->caughtPkm.vel = 45;
    t->caughtPkm.isdualtype = true;
    t->caughtPkm.nomePKM = "Bulbasaur";
    t->caughtPkm.tipo1 = "grama";
    t->caughtPkm.tipo2 = "venenoso";
    t->caughtPkm.hp = 45;
    t->caughtPkm.hpmax = 45;
    registra_move(&t->caughtPkm.ATKs, "Investida", 40, 100, 35, "normal");
    registra_move(&t->caughtPkm.ATKs, "Rosnado", 0, 100, 40, "normal");
    registra_move(&t->caughtPkm.ATKs, "Chicote de cipó", 30, 100, 25, "grama");
    registra_move(&t->caughtPkm.ATKs, "Folha Navalha", 35, 75, 35, "grama");

    t->nextPkm = (treinador*)malloc(sizeof(treinador));
    t = t->nextPkm;
    t->nextPkm = NULL;
    registra_pokemon(t);

    t->caughtPkm.atk = 52;
    t->caughtPkm.def = 43;
    t->caughtPkm.vel = 65;
    t->caughtPkm.isdualtype = false;
    t->caughtPkm.nomePKM = "Charmander";
    t->caughtPkm.tipo1 = "fogo";
    t->caughtPkm.tipo2 = "fogo";
    t->caughtPkm.hp = 39;
    t->caughtPkm.hpmax = 39;
    registra_move(&t->caughtPkm.ATKs, "Arranhar", 40, 100, 35, "normal");
    registra_move(&t->caughtPkm.ATKs, "Rosnado", 0, 100, 40, "normal");
    registra_move(&t->caughtPkm.ATKs, "Brasa", 40, 100, 25, "fogo");
    registra_move(&t->caughtPkm.ATKs, "Sopro do Dragão", 60, 75, 20, "fogo");

    t->nextPkm = (treinador*)malloc(sizeof(treinador));
    t = t->nextPkm;
    t->nextPkm = NULL;
    registra_pokemon(t);

    t->caughtPkm.atk = 48;
    t->caughtPkm.def = 65;
    t->caughtPkm.vel = 43;
    t->caughtPkm.isdualtype = false;
    t->caughtPkm.nomePKM = "Squirtle";
    t->caughtPkm.tipo1 = "agua";
    t->caughtPkm.tipo2 = "agua";
    t->caughtPkm.hp = 44;
    t->caughtPkm.hpmax = 44;
    registra_move(&t->caughtPkm.ATKs, "Cabeçada", 40, 100, 35, "normal");
    registra_move(&t->caughtPkm.ATKs, "Chicote de Cauda", 0, 100, 40, "normal");
    registra_move(&t->caughtPkm.ATKs, "Bala de Agua", 35, 100, 25, "agua");
    registra_move(&t->caughtPkm.ATKs, "Pulso de Agua", 45, 75, 20, "agua");
}


bool verifica_super(treinador* t, treinador* oponente) {
    if (t->caughtPkm.tipo1 == "fogo" && oponente->caughtPkm.tipo1 == "grama") {
        std::cout << "Super efetivo!" << std::endl;
        return true;
    }
    if (t->caughtPkm.tipo1 == "agua" && oponente->caughtPkm.tipo1 == "fogo") {
        std::cout << "Super efetivo!" << std::endl;
        return true;
    }
    if (t->caughtPkm.tipo1 == "grama" && oponente->caughtPkm.tipo1 == "agua") {
        std::cout << "Super efetivo!" << std::endl;
        return true;
    }
    return false;
}

bool pokemon_move(int ataque, treinador* t) {
    moves* m = &t->caughtPkm.ATKs;
    while (m->moveIndex != ataque - 1 && m->nextMove != NULL) {
        m = m->nextMove;
    }
    return m->power;
}

void copy_pokemon(Pokemon& dest, const Pokemon& src) {
    dest.nomePKM = src.nomePKM;
    dest.tipo1 = src.tipo1;
    dest.tipo2 = src.tipo2;
    dest.lvl = src.lvl;
    dest.exp = src.exp;
    dest.atk = src.atk;
    dest.def = src.def;
    dest.vel = src.vel;
    dest.hp = src.hp;
    dest.hpmax = src.hpmax;
    dest.isdualtype = src.isdualtype;

    dest.ATKs.move = src.ATKs.move;
    dest.ATKs.power = src.ATKs.power;
    dest.ATKs.acc = src.ATKs.acc;
    dest.ATKs.pp = src.ATKs.pp;
    dest.ATKs.type = src.ATKs.type;
    dest.ATKs.moveIndex = src.ATKs.moveIndex;
    dest.ATKs.nextMove = nullptr;

    moves* srcMove = src.ATKs.nextMove;
    moves* destMove = &dest.ATKs;

    while (srcMove != nullptr) {
        destMove->nextMove = new moves();
        destMove = destMove->nextMove;
        destMove->move = srcMove->move;
        destMove->power = srcMove->power;
        destMove->acc = srcMove->acc;
        destMove->pp = srcMove->pp;
        destMove->type = srcMove->type;
        destMove->moveIndex = srcMove->moveIndex;
        destMove->nextMove = nullptr;
        srcMove = srcMove->nextMove;
    }
}


bool captura_pokemon(treinador* t, const Pokemon& wildPkm) {
    while (t->nextPkm != NULL) {
        t = t->nextPkm;
    }
    if (t->count == 5) {
        std::cout << "Você não pode ter mais de 6 pokemons!" << std::endl;
        return false;
    }

    t->nextPkm = (treinador*)malloc(sizeof(treinador));
    t->nextPkm->nextPkm = NULL;
    t->nextPkm->count = t->count + 1;
    copy_pokemon(t->nextPkm->caughtPkm, wildPkm);

    std::cout << "Você capturou um " << wildPkm.nomePKM << "!" << std::endl;
    return true;
}

void delete_pokemon(Pokemon& pkm) {
    moves* m = pkm.ATKs.nextMove;
    while (m != nullptr) {
        moves* temp = m;
        m = m->nextMove;
        delete temp;
    }
}

bool pokemon_acc(int ataque, treinador* t) {
    moves* m = &t->caughtPkm.ATKs;
    while (m->moveIndex != ataque - 1 && m->nextMove != NULL) {
        m = m->nextMove;
    }
    if (m->acc > rand() % 100) {
        return true;
    }
    return false;
}

void inicializa_pokemon(treinador* t, const std::string& nome, const std::string& tipo1, const std::string& tipo2, int lvl, int exp, int atk, int def, int vel, int hp, int hpmax) {
    t->caughtPkm.lvl = lvl;
    t->caughtPkm.exp = exp;
    t->caughtPkm.atk = atk;
    t->caughtPkm.def = def;
    t->caughtPkm.vel = vel;
    t->caughtPkm.isdualtype = (tipo1 != tipo2);
    t->caughtPkm.nomePKM = nome;
    t->caughtPkm.tipo1 = tipo1;
    t->caughtPkm.tipo2 = tipo2;
    t->caughtPkm.hp = hp;
    t->caughtPkm.hpmax = hpmax;
    t->caughtPkm.ATKs.moveIndex = 0;
    t->caughtPkm.ATKs.nextMove = NULL;
}

void inicia_batalha(treinador * t, treinador * oponente, mochila * m){
    cout << "Você encontrou um(a) " << oponente->caughtPkm.nomePKM << " selvagem!" << endl;
    limpa_dialogo();
    int escolha = 10;
    while(escolha != 3){
        cout << "O que você deseja fazer?" << endl;
        cout << "1 - Lutar" << "     " << "2 - Capturar" << "     " << "3 - Fugir " << endl;
        int se_super = 1;
        int dano;
        cin >> escolha;
        limpa_dialogo();
        switch(escolha){
            case 1: {
                cout << "Ataques: " << "1 - " << t->caughtPkm.ATKs.move;
                if (t->caughtPkm.ATKs.nextMove != NULL) {
                    cout << " 2 - " << t->caughtPkm.ATKs.nextMove->move;
                    if (t->caughtPkm.ATKs.nextMove->nextMove != NULL) {
                        cout << " 3 - " << t->caughtPkm.ATKs.nextMove->nextMove->move;
                        if (t->caughtPkm.ATKs.nextMove->nextMove->nextMove != NULL) {
                            cout << " 4 - " << t->caughtPkm.ATKs.nextMove->nextMove->nextMove->move;
                        }
                    }
                }
                cout << endl;
                int ataque;
                cin >> ataque;
                limpa_dialogo();
                
                if(verifica_super(t, oponente)){
                    se_super = 2;
                }

                if(pokemon_acc(ataque, t)){
                    cout << "Ataque acertou!" << endl;
                    limpa_dialogo();
                } else {
                    cout << "Ataque errou!" << endl;
                    limpa_dialogo();
                    break;
                }

                dano = (((((2*t->caughtPkm.lvl)/5) * (pokemon_move(ataque, t))/(oponente->caughtPkm.def))+2)/50) * se_super;
                
                oponente->caughtPkm.hp -= dano;
                cout << "Você causou " << dano << " de dano!" << endl;
                if(oponente->caughtPkm.hp <= 0){
                    cout << "Você venceu!" << endl;
                    return;
                }
            }
            case 2: {
                cout << "Você escolheu capturar!" << endl;
                limpa_dialogo();
                m->pokebolas -= 1;
                if(m->pokebolas == 0){
                    cout << "Você não tem mais pokebolas!" << endl;
                    limpa_dialogo();
                    escolha = 10;
                    break;
                }
                if(rand()%100 < 50){
                    cout << "Você capturou o pokemon!" << endl;
                    captura_pokemon(t, oponente->caughtPkm);
                    return;
                } else {
                    cout << "O pokemon selvagem escapou da pokebola!" << endl;
                    limpa_dialogo();
                    escolha = 10;
                }
                break;
            }
            case 3: {
                cout << "Você escolheu fugir!" << endl;
                limpa_dialogo();
                if(rand()%100 < 50){
                    cout << "Você fugiu!" << endl;
                    limpa_dialogo();
                    return;
                } else {
                    cout << "Você não conseguiu fugir!" << endl;
                    escolha = 10;
                    limpa_dialogo();
                }
                break;
            }
            default: {
                cout << "Escolha inválida!" << endl;
                limpa_dialogo();
                break;
            }
        }
    }
}
