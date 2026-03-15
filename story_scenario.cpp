//
// Created by Motunrayo on 3/13/2026.
//

#include "story_scenario.h"
#include <iostream>

StoryScenario::StoryScenario(const std::string &t, int n1, int n2): scenario(n1, n2), text(t) {}
int StoryScenario::run(player &p) {
    std::cout << text << "\n";
    std::cout << "1) Continue\n2) Turn back\n";
    int choice = ValidChoice(1, 2);
    return GetNext(choice);
}