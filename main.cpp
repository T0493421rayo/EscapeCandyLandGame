#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "game.h";
#include "item.h";
#include "player.h";
#include "scenario.h"
using namespace std;
int main() {
    srand(time(nullptr));
    cout << "Welcome to the Magic World of Gumball!\n";
    cout << "Enter player's name: ";

    string name;
    getline(cin, name);

    game game(name);
    game.StartGame();

    return 0;
}