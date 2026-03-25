
// Created by Motunrayo on 3/13/2026.
#ifndef PUZZLE_SCENARIO_H
#define PUZZLE_SCENARIO_H

#include "puzzle_scenario.h"
#include <iostream>
using namespace std;

PuzzleScenario::PuzzleScenario(const std::string &t,int minC,int maxC,void (*effect)(int, player&),int sid1,int sid2): scenario(sid1, sid2){
    text = t;
    minChoice = minC;
    maxChoice = maxC;
    puzzleEffect = effect;
}

int PuzzleScenario::run(player &p) {
    cout << text << "\n";
    cout << "Enter your answer:\n";
    int choice = ValidChoice(minChoice, maxChoice);
    puzzleEffect(choice, p);
    return GetNext(choice);
}
#endif