//
// Created by Motunrayo on 3/13/2026.
//

#ifndef IY453_COURSEWORK_P493421_ITEM_SCENARIO_H
#define IY453_COURSEWORK_P493421_ITEM_SCENARIO_H
#ifndef ITEM_SCENARIO_H
#define ITEM_SCENARIO_H

#include "scenario.h"
#include "item.h"
#include <string>

class ItemScenario : public scenario {
private:
    std::string description;
    item reward;

public:
    ItemScenario(const std::string &desc, const item &rewardItem)
        : description(desc), reward(rewardItem) {}

    void run(player &p) ;
};

#endif











#endif //IY453_COURSEWORK_P493421_ITEM_SCENARIO_H