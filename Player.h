//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_PLAYER_H
#define IY453_COURSEWORK_P493421_PLAYER_H


#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
using namespace std;

class Player {
private:
    string name;
    int health;
    int attackPower;
    int lives;

    bool crystalBall;
    bool potionJuice;

    vector<Item> inventory;

public:
    Player(string name);

    void takeDamage(int amount);
    void heal(int amount);
    void increaseAttack(int amount);

    void addItem(Item item);
    bool hasItem(string itemName);

    int getAttack();
    int getHealth();
    string getName();

    void printStatus();
    void displayGreetings();
};

int ValidChoice(int min, int max);

#endif

