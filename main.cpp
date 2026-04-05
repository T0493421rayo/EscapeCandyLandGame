#include "game.h"
#include "item.h"
#include "player.h"
#include "scenario.h"
#include "save_game.h"
#include "limits"

using namespace std;
int main() {
    srand(time(nullptr));
    cout << "Welcome to the Magic World of Gumball!\n";
    int choice;
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    choice=ValidChoice(1,2);



    GameState loadedState;
    string name;
    if (choice == 1) {
        bool valid = false;
        while (!valid) {
            cout << "Enter player's name: ";
            getline(cin, name);
            if (name == "") {
                cout << "Name cannot be empty Retry..\n";
                continue;
            }
            valid = true;
            for (char c : name) {
                if (!isalpha(c)) {
                    valid = false;
                    cout <<"Name can only contain letters.Try again.\n";
                    break;
                }
            }
        }
        game game(name);
        game.StartGame();
    }
    else if (choice == 2) {
        if (save_game::loadGame(loadedState)) {
            cout <<"Welcome back " << loadedState.playerName << "!\n";

            game game(loadedState.playerName);
            game.LoadScenarios();

            int startScene=game.LoadFromState(loadedState);
            cout<<"Scene: "<<startScene<<endl;

            game.StartGameFromScene(startScene);
        }
        else {
            cout << "No saved game found. Starting new game.\n";
            cout << "Enter player's name: ";
            getline(cin, name);
            game game(name);
            game.StartGame();
        }
    }

    return 0;
}