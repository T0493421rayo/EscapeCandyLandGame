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
#include "Player.h"
#include "Scenario.h"


class Game {
private:
    Player player;
    std::vector<Scenario*> scenes;

public:
    Game(const std::string& playerName);
    ~Game(); // destructor to clean up memory

    void startGame();
};

#endif

























#endif //IY453_COURSEWORK_P493421_GAME_H