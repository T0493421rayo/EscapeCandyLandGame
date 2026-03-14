#include "combat_scenario.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

CombatScenario::CombatScenario(const std::string &descriptionText, int enemyHp, int enemyAttackValue, const std::string &enemyNameText) {
    description=descriptionText;
    enemyHealth=enemyHp;
    enemyAttack=enemyAttackValue;
    enemyName=enemyNameText;
}

void CombatScenario::run(player &p) {
    cout << description << "\n";

    while (p.GetHealth() > 0 && enemyHealth > 0) {

        int playerDamageStats = p.GetAttack();
        int enemyDamageStats = enemyAttack;
        int playerDamage = playerDamageStats + (rand() % 6 - 2);
        int enemyDamage  = enemyDamageStats + (rand() % 6 - 2);
        if (playerDamage < 0) playerDamage = 0;
        if (enemyDamage < 0) enemyDamage = 0;

        enemyHealth -= playerDamage;
        p.TakeDamage(enemyDamage);

        cout << "Your strike caused " << playerDamage << " damage.\n";
        cout << enemyName << " strike caused " << enemyDamage << " damage.\n";
        if (p.GetHealth() <= 0) {
            cout << "\nYou were defeated!\n";
            return;
        }
    }

    cout << "\nYou defeated the " << enemyName << "!\n";
}

