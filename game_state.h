//
// Created by Motunrayo on 3/27/2026.
//

#ifndef IY453_COURSEWORK_P493421_GAMESTATE_H
#define IY453_COURSEWORK_P493421_GAMESTATE_H

#include <string>
#include <vector>

struct GameState {
    std::string playerName;
    int scenarioID;
    int health;
    int attack_power;
    int lives;
    std::vector<std::string> inventory;
};

#endif //IY453_COURSEWORK_P493421_GAMESTATE_H