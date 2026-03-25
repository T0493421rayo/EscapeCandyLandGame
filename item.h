//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_ITEM_H
#define IY453_COURSEWORK_P493421_ITEM_H
#include <string>
using namespace std;

class item {
public:
    string name;
    string type;
    int health_effect;
    int attack_effect;


public:
    item(string itemName, string itemType, int health, int attack);
    string GetName() const {
        return name;
    }
    string GetType() const {
        return type;
    }
    int GetHealthEffect() const {
        return health_effect;
    }
    int GetAttackEffect() const {
        return attack_effect;
    }


};


#endif //IY453_COURSEWORK_P493421_ITEM_H
