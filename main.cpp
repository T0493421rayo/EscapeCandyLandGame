#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "Game.h";
#include "Item.h";
#include "Player.h";
#include "Scenario.h"
using namespace std;



int main() {
    cout << "Welcome to the Magic World of Gumball!\n";
    cout << "Enter player's name: ";

    string name;
    getline(cin, name);

    Game game(name);
    game.startGame();

    return 0;
}