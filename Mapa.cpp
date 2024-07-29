#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    bool hasBattle;
    Node* next;
    Node* prev;

    Node(bool battle) : hasBattle(battle), next(nullptr), prev(nullptr) {} // IA
};

struct Map {
    Node* head;
    Node* tail;
    Node* player;

    Map() : head(nullptr), tail(nullptr), player(nullptr) {} //IA

    void addNode(bool battle) {
        Node* newNode = new Node(battle);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void placePlayerAtStart() {
        player = head;
    }

    void movePlayerForward() {
        if (player && player->next) {
            player = player->next;
            checkCurrentPosition();
        }
    }

    void movePlayerBackward() {
        if (player && player->prev) {
            player = player->prev;
            checkCurrentPosition();
        }
    }

    void checkCurrentPosition() {
        if (player->hasBattle) {
            startBattle();
        }
    }

    void startBattle() {
        cout << "Voce encontrou um pokemon! Batalhar?\n";
    }

    void displayMap() {
        Node* temp = head;
        while (temp) {
            if (temp == player) {
                cout << "[P]";
            } else {
                cout << "[ ]";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    cout << "COMANDOS\n";
    cout << "d: direita, e: esquerda, s: sair:\n";
    srand(time(0));

    Map gameMap;

    for (int i = 0; i < 10; ++i) {
        bool battle = rand() % 2;
        gameMap.addNode(battle);
    }

    gameMap.placePlayerAtStart();
    gameMap.displayMap();

    char command;
    while (true) {
        cin >> command;
        if (command == 'd') {
            gameMap.movePlayerForward();
        } else if (command == 'e') {
            gameMap.movePlayerBackward();
        } else if (command == 's') {
            break;
        }
        gameMap.displayMap();
    }

    return 0;
}
