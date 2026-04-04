//
// Created by Motunrayo on 3/27/2026.
//
#include "save_game.h"
#include <fstream>
#include <iostream>
using namespace std;


bool save_game::saveGame(const GameState &state) {
    bool success = true;

    //Programiz (n.d)
    ofstream file("saved_game.txt");
    if (!file) {
        cout << "Error: Unable to open file";
        success = false;
    }
    else {
        file  <<state.playerName << endl;
        file  <<state.scenarioID << endl;
        file  << state.health << endl;
        file  <<state.lives << endl;
        file << state.attack_power << endl;
        file  <<state.inventory.size() << "\n";
        file<<state.score <<"\n";
        for (const auto& item : state.inventory) {
            file << item << "\n";
        }
        cout << "Game saved successfully";
    }
    return success;
}
// Programiz (n.d)
bool save_game::loadGame(GameState &state) {
    bool success = true;
    ifstream file("saved_game.txt");
    if (!file.is_open()) {
        cout << "No saved file found\n";
        success = false;
    }
    else {
        int inventoryCount;
        if (!getline(file, state.playerName))
            success = false;
        else if (!(file >> state.scenarioID))
            success = false;
        else if (!(file >> state.health))
            success = false;
        else if (!(file >> state.lives))
            success = false;
        else if (!(file >> state.attack_power))
            success = false;
        else if (!(file >> inventoryCount))
            success = false;
        else if (!(file >> state.score))
            success = false;
        else {
            file.ignore();
            state.inventory.clear();
            for (int i = 0; i < inventoryCount; i++) {
                string item;
                if (!getline(file, item)) {
                    cout << "Error: Save file corrupted.\n";
                    success = false;
                    break;
                }
                state.inventory.push_back(item);
            }
        }
        if (success)
            cout << "Game loaded successfully\n";
    }
    return success;
}



