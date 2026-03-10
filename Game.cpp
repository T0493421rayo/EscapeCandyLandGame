//
// Created by Motunrayo on 3/10/2026.
//

#include "Game.h"
#include "Game.h"

using namespace std;

Game::Game(const string& playerName)
    : player(playerName)
{
    Scenario1* s1 = new Scenario1();
    Scenario2* s2 = new Scenario2();
    Scenario3* s3 = new Scenario3();
    Scenario4* s4 = new Scenario4();
    Scenario5* s5 = new Scenario5();
    Scenario6* s6 = new Scenario6();
    Scenario7* s7 = new Scenario7();
    Scenario8* s8 = new Scenario8();

    scenes = { s1, s2, s3, s4, s5, s6, s7, s8 };
}

Game::~Game() {
    // Clean up dynamically allocated scenarios
    for (Scenario* s : scenes) {
        delete s;
    }
}

void Game::startGame() {
    cout << "Welcome to the Magic World of Gumball!\n";
    player.displayGreetings();
    player.printStatus();

    for (Scenario* s : scenes) {
        s->run(player);

        if (player.getHealth() <= 0) {
            cout << "\nYou died! Game over.\n";
            return;
        }
    }

    cout << "\n--- GAME OVER ---\n";
    player.printStatus();

    if (player.getHealth() > 0) {
        cout << "Congratulations " << player.getName() << "! You survived!\n";
    } else {
        cout << "You did not survive the Magic World of Gumball.\n";
    }
}