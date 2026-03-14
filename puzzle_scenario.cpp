//
// Created by Motunrayo on 3/13/2026.
//
#include "puzzle_scenario.h"
#include <iostream>
using namespace std;

void PuzzleScenario::run(player &p) {
    cout << text << "\n";

    int choice = ValidChoice(minChoice, maxChoice);
    handler(choice, p);
}