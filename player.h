//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_PLAYER_H
#define IY453_COURSEWORK_P493421_PLAYER_H
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "item.h"
#include "player.h"
using namespace std;
class player {
private:
    string name;
    int health;
    int attack_power;
    int defense;
    int lives;
    bool crystal_ball;
    bool potion_juice;
    vector<item> inventory;
public:
    player(string name);
    int GetHealth();
    int GetAttack();
    int GetLives();
    void TakeDamage(int amount);
    void Heal(int amount);
    void IncreaseAttack(int amount);
    void AddItem(const item &item);
    bool HasItem(string itemName);
    void LoseLife();
    void PrintStatus();
    void DisplayGreetings();
    string GetName();
};


int ValidChoice(int min, int max);

#endif

#endif

