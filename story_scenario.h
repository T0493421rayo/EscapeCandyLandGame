//
// Created by Motunrayo on 3/13/2026.
//

#ifndef IY453_COURSEWORK_P493421_STORY_SCENARIO_H
#define IY453_COURSEWORK_P493421_STORY_SCENARIO_H
#include "scenario.h"
#include <string>

class StoryScenario : public scenario {
private:
    std::string text;
public:
   StoryScenario(const std::string&t,int sid1,int sid2);
   int run(player &p) override;
};
#endif //IY453_COURSEWORK_P493421_STORY_SCENARIO_H