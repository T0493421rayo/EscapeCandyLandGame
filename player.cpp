//
// Created by Motunrayo on 3/10/2026.
//
#include "player.h"
#include "game_state.h"
#include <limits>
#include "item.h"
player::player(string name) {
    this->name = name;
    health = 50;
    attack_power = 5;
    lives=3;
    crystal_ball = false;
    potion_juice = false;
}
void player::TakeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
void player::Heal(int amount) {
    health += amount;
}
void player::IncreaseAttack(int amount) {
    attack_power += amount;
}

void player::AddItem(const item &item) {
    inventory.push_back(item);
    cout << "\nYou got: " << item.name << " (" << item.type << ")\n";
    if (item.GetHealthEffect() != 0) {
        health +=item.GetHealthEffect();
        cout<<"You gained health points:"<<item.GetHealthEffect()<<"\n";
    }
    if (item.GetAttackEffect()!=0) {
        attack_power+=item.GetAttackEffect();
        cout<<"You gained attack points:"<<item.GetAttackEffect()<<"\n";
    }
}


bool player::HasItem(string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].name == itemName)
            return true;
    }
    return false;
}
int player::GetAttack() {
    return attack_power;
}
int player::GetHealth() {
    return health;
}
int player::GetLives() {
    return lives;
}
string player::GetName() {
    return name;
}
void player::LoseLife() {
    if (lives>0) {
        lives--;
    }
    if (lives>0) {
        health=100;
        cout<<"\n You lost a life!"<<endl;
        cout<<"Lives left:"<<lives<<endl;
    } else {
        cout<<"No lives left!";
    }
}
void player::PrintStatus() {
    cout << "\n--- PLAYER STATUS ---\n";
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Lives: " << lives << "\n";
    cout << "Attack Power: " << attack_power << "\n";

    cout << "Inventory: ";
    if (inventory.empty()) {
        cout << "No item in inventory!";
    } else {
        for (int i = 0; i < inventory.size(); i++) {
            cout << inventory[i].name;
            if (i < inventory.size() - 1) cout << ", ";
        }
    }
    cout << "\n";
}
void player::DisplayGreetings() {
    cout << "\n--- Welcome " << name << " to the Magic World of Gumball! ---\n";
    cout << "--- Your mission is to escape while you still have lives! ---\n";
}
int ValidChoice(int min, int max) {
    int choice;
    bool valid = false;
    while (!valid) {
        cout << "Enter choice (" << min << "-" << max << "): ";
        if (cin >> choice) {
            if (choice >= min && choice <= max) {
                valid = true;
            } else {
                cout << "Please enter a number between " << min << " and " << max << ".\n";
            }
        } else {
            cout << "Invalid input! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}
#include "player.h"
