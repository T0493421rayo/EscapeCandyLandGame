//
// Created by Motunrayo on 3/27/2026.
//

#include "save_game.h"
#include "fstream"
#include <iostream>
using namespace std;

bool save_game::saveGame(const GameState &state) {
    ofstream file("saved_game.txt");
//Programiz(n.d)
    if (!file) {
        cout<<"Error:Unable to open file";
        return 1;
    }
    file<<state.playerName<<endl;
    file<<state.scenarioID<<endl;
    file<<state.health<<endl;
    file<<state.lives<<endl;
    file<<state.attack_power<<endl;

    file << state.inventory.size() << "\n";
    for (const auto& item : state.inventory) {
        file << item << "\n";
    }

    cout<<"Game saved successfully";
    return true;

}
//Progamiz(n.d)
bool save_game::loadGame(GameState &state) {
    ifstream file("saved_game.txt");
    if (!file.is_open()) {
        cout << "No saved file found\n";
        return false;
    }
    int inventoryCount;
    if (!getline(file, state.playerName))
        return false;

    if (!(file >> state.scenarioID))
        return false;
    if (!(file >> state.health))
        return false;
    if (!(file >> state.lives))
        return false;
    if (!(file >> state.attack_power))
        return false;

    if (!(file >> inventoryCount))
        return false;

    file.ignore();
    state.inventory.clear();
    for (int i = 0; i < inventoryCount; i++) {
        string item;
        if (!getline(file, item)) {
            cout << "Error: Save file corrupted.\n";
            return false;
        }
        state.inventory.push_back(item);
    }

    cout << "Game loaded successfully\n";
    return true;
}



