//
// Created by Motunrayo on 3/13/2026.
//

#ifndef IY453_COURSEWORK_P493421_COMBAT_SCENARIO_H
#define IY453_COURSEWORK_P493421_COMBAT_SCENARIO_H



#ifndef COMBAT_SCENARIO_H
#define COMBAT_SCENARIO_H

#include "scenario.h"
#include <string>

class CombatScenario : public scenario {
private:
    std::string description;
    int enemyHealth;
    int enemyAttack;
    int enemyDefence;
    std::string enemyName;

public:
    CombatScenario(const std::string &descriptionText,int enemyHp,int enemyAttackValue,const std::string &enemyNameText);

    void run(player &p);
};

#endif


#endif

