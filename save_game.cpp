//
// Created by Motunrayo on 3/27/2026.
//

#include "save_game.h"
#include "fstream"
#include <iostream>
using namespace std;

bool save_game::saveGame(const GameState &state) {
    ofstream file("saved_game");
//Programiz(n.d)
    if (!file) {
        cout<<"Error:Unable to open file";
        return 1;
    }

    file<<state.playerName;
    file<<state.scenarioID;
    file<<state.health;
    file<<state.lives;
    file<<state.attack_power;

    file << state.inventory.size() << "\n";
    for (const auto& item : state.inventory) {
        file << item << "\n";
    }



}
