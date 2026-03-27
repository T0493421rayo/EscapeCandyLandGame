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
#include "game_state.h"
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
    string GetName() const;
    int GetHealth() const;
    int GetAttack() const;
    int GetLives() const;
    void TakeDamage(int amount);
    void Heal(int amount);
    void IncreaseAttack(int amount);
    void AddItem(const item &item);
    bool HasItem(string itemName);
    void LoseLife();
    void PrintStatus();
    void DisplayGreetings();
    string GetName();
    void SetName(const std::string& newName);
    void SetHealth(int h);
    void SetAttackPower(int a);
    void SetLives(int l);
    void SetInventory(const std::vector<item>& inv);
    GameState toGameState(int scenarioID) const;
    void fromGameState(const GameState& state);



};


int ValidChoice(int min, int max);

#endif

#endif

