//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_ITEM_H
#define IY453_COURSEWORK_P493421_ITEM_H
#include <string>
using namespace std;

class Item {
public:
    string name;
    string type;
    int healthEffect;
    int attackEffect;

    Item(string itemName, string itemType, int health, int attack);
};


#endif //IY453_COURSEWORK_P493421_ITEM_H
