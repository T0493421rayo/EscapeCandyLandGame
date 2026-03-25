// Created by Motunrayo on 3/13/2026.

#include "item_scenario.h"
#include <iostream>
#include "player.h"
using namespace std;
using namespace std;
ItemScenario::ItemScenario(const std::string &desc,const item &i,int sid1,int sid2): scenario(sid1, sid2), description(desc), reward(i){
}
int ItemScenario::run(player &p) {
    cout << description << "\n";
    cout << "Do you want to collect the item?\n";
    cout << "1) Yes\n";
    cout << "2) No\n";
    int choice = ValidChoice(1, 2);
    if (choice == 1) {
        cout << "You collected: " << reward.GetName() << "\n";
        p.AddItem(reward);
        if (reward.GetHealthEffect() > 0) {
            p.Heal(reward.GetHealthEffect());
            cout << "+ " << reward.GetHealthEffect() << " health.\n";
        }
        if (reward.GetAttackEffect() > 0) {
            p.IncreaseAttack(reward.GetAttackEffect());
            cout << "+ " << reward.GetAttackEffect() << " attack.\n";
        }
        if (reward.GetAttackEffect() < 0) {
            p.IncreaseAttack(reward.GetAttackEffect());
            cout << reward.GetAttackEffect() << " attack (negative item).\n";
        }
    } else {
        cout << "You decided to leave the item.\n";
    }
    return GetNext(choice);
}