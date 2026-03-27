//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_GAME_H
#define IY453_COURSEWORK_P493421_GAME_H

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "scenario.h"
class game {
private:
    player p;
    std::vector<scenario*> scenes;
    bool running;
public:
    game(const std::string& playerName);
    ~game();
    void StartGame();
    void LoadScenarios();
    bool Combat(player &p, int enemyHealth, int enemyAttack, int enemyDefence, const std::string &enemyName);
    void LoadFromState(const GameState& state);
};

#endif

























#endif //IY453_COURSEWORK_P493421_GAME_H