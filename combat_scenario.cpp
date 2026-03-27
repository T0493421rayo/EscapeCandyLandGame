#include "combat_scenario.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

CombatScenario::CombatScenario(const std::string &descriptionText,int enemyHp,int enemyAttackValue,const std::string &enemyNameText,int sid1,int sid2): scenario(sid1, sid2){
    description = descriptionText;
    enemyHealth = enemyHp;
    enemyAttack = enemyAttackValue;
    enemyName = enemyNameText;
}

int CombatScenario::run(player &p) {
    cout << description << "\n";
    cout << "Choose your combat style:\n";
    cout << "1) Aggressive attack\n";
    cout << "2) Defensive attack\n";
    int choice = ValidChoice(1, 2);
    int attackModifier = (choice == 1 ? +2 : -1);
    while (p.GetHealth() > 0 && enemyHealth > 0) {
        int playerDamageStats = p.GetAttack() + attackModifier;
        int enemyDamageStats = enemyAttack;
        //w3school(n.d)
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
            return GetNext(choice);   // still branches correctly
        }
    }
    cout << "\nYou defeated the " << enemyName << "!\n";

    return GetNext(choice);  // branch after combat
}
