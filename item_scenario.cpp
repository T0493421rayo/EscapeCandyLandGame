//
// Created by Motunrayo on 3/13/2026.
//

#include "item_scenario.h"
#include <iostream>
using namespace std;
void ItemScenario::run(player &p) {
    cout << description << "\n";
    p.AddItem(reward);
    }

