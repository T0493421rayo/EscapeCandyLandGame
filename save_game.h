//
// Created by Motunrayo on 3/27/2026.
//

#ifndef IY453_COURSEWORK_P493421_SAVE_GAME_H
#define IY453_COURSEWORK_P493421_SAVE_GAME_H

#include "game_state.h"
class save_game {
public:
    static bool saveGame(const GameState& state);
    static bool loadGame(GameState& state);
};

#endif //IY453_COURSEWORK_P493421_SAVE_GAME_H