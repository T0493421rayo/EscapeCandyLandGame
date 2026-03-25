#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "game.h"
#include "item.h"
#include "player.h"
#include "scenario.h"
using namespace std;
int main() {
    srand(time(nullptr));
    cout << "Welcome to the Magic World of Gumball!\n";
    string name;
    bool valid = false;
    while (!valid) {
        cout << "Enter player's name: ";
        getline(cin, name);
        if (name == "") {
            cout << "Name cannot be blank. Please try again.\n";
            continue;
        }
        valid = true;
        for (char c : name) {
            if (!isalpha(c)) {
                valid = false;
                cout << "Name can only contain letters. Try again.\n";
                break;
            }
        }
    }
    game game(name);
    game.StartGame();
    return 0;
}