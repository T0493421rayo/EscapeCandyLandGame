//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_SCENARIO_H
#define IY453_COURSEWORK_P493421_SCENARIO_H

#include "player.h"
#include <iostream>
#include <string>
#ifndef SCENARIO_H
#define SCENARIO_H


class scenario {
protected:
    int scene_id1;
    int scene_id2;

public:
    scenario(int n1, int n2);
    virtual ~scenario() {}
    virtual int run(player &p) = 0;

    int GetNext(int choice);
};

#endif

#endif //IY453_COURSEWORK_P493421_SCENARIO_H
