//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_SCENARIO_H
#define IY453_COURSEWORK_P493421_SCENARIO_H

#include "player.h"
#include <iostream>
#include <string>
using namespace std;
class scenario {
public:
    virtual void run(player &p) = 0;
    virtual ~scenario() {}
};


#endif //IY453_COURSEWORK_P493421_SCENARIO_H
