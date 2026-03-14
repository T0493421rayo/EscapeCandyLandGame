//
// Created by Motunrayo on 3/13/2026.
//


#define PUZZLE_SCENARIO_H

#include "scenario.h"
#include <string>
#ifndef IY453_COURSEWORK_P493421_PUZZLE_SCENARIO_H
#define IY453_COURSEWORK_P493421_PUZZLE_SCENARIO_H

#include "scenario.h"
#include <string>

class PuzzleScenario : public scenario {
private:
    std::string text;
    int minChoice;
    int maxChoice;
    void (*puzzleEffect)(int, player&);

public:
    PuzzleScenario(const std::string &t, int minC, int maxC, void (*effect)(int, player&))
        : text(t), minChoice(minC), maxChoice(maxC), puzzleEffect(effect) {}

    void run(player &p) override;
};

#endif