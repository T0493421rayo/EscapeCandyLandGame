//
// Created by Motunrayo on 3/13/2026.
//

#include "story_scenario.h"
#include <iostream>

StoryScenario::StoryScenario(const std::string &t, int sid1, int sid2): scenario(sid1, sid2), text(t) {}
int StoryScenario::run(player &p) {
    std::cout << text << "\n";
    int choice = ValidChoice(1, 2);
    return GetNext(choice);
}