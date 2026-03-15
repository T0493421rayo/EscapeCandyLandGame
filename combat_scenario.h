#include "player.h"
#include "scenario.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class CombatScenario : public scenario {
private:
    std::string description;
    int enemyHealth;
    int enemyAttack;
    std::string enemyName;
public:
    CombatScenario(const std::string &descriptionText,int enemyHp,int enemyAttackValue,const std::string &enemyNameText,int sid1, int sid2);
    int run(player &p) override;
};



