//
// Created by Motunrayo on 3/13/2026.
//

#ifndef IY453_COURSEWORK_P493421_PUZZLE_SCENARIO_H
#define IY453_COURSEWORK_P493421_PUZZLE_SCENARIO_H
#ifndef PUZZLE_SCENARIO_H
#define PUZZLE_SCENARIO_H

#include "scenario.h"
#include <string>
#include <functional>

class PuzzleScenario : public scenario {
private:
    std::string text;
    int minChoice;
    int maxChoice;
    std::function<void(int, player&)> handler;

public:
    PuzzleScenario(const std::string &t, int minC, int maxC,
                   std::function<void(int, player&)> h)
        : text(t), minChoice(minC), maxChoice(maxC), handler(h) {}

    void run(player &p) override;
};

#endif

#endif //IY453_COURSEWORK_P493421_PUZZLE_SCENARIO_H