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
    score=0;
    crystal_ball = false;
    potion_juice = false;
}

string player::GetName() const {
    return name;
}

int player::GetHealth() const {
    return health;
}

int player::GetAttack() const {
    return attack_power;
}

int player::GetLives() const {
    return lives;
}

int player::GetScore() const {
    return score;
}
void player::AddScore(int amount) {
    score += amount;
}

void player::SetName(const std::string &newName) {
    name=newName;
}

void player::SetHealth(int h) {
    health=h;
}

void player::SetAttackPower(int attack) {
    attack_power=attack;
}

void player::SetLives(int l) {
    lives=l;
}

void player::SetInventory(const std::vector<item> &inv) {
    inventory=inv;
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

void player::AddItem(const item &it) {
    inventory.push_back(it);
    cout  << it.GetName()<<"has been added to your inventory.\n";
    if (it.GetHealthEffect() > 0) {
        cout << it.GetHealthEffect() << " Health Points\n";
    }
    if (it.GetAttackEffect() > 0) {
        cout << it.GetAttackEffect() << " Attack Power\n";
    }
    cout << endl;
}
bool player::HasItem(string itemName) {
    for (auto &it : inventory)
        if (it.GetName() == itemName)
            return true;
    return false;
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
void player::ShowInventory() const {
    cout <<"Inventory for: "<<name;
    if (inventory.empty()) {
        cout << "\n No items in inventory.\n";
        return;
    }
    for (const auto& it : inventory) {
        cout << "- " << it.GetName();
        if (it.GetHealthEffect() != 0)
            cout <<" | Health: "<< it.GetHealthEffect();
        if (it.GetAttackEffect() != 0)
            cout <<" | Attack: "<< it.GetAttackEffect();
    }

}
void player::PrintStatus() {
    cout << "\n--- PLAYER STATUS ---\n";
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Lives: " << lives << "\n";
    cout << "Attack Power: " << attack_power << "\n";
    cout << "Inventory: "<<"\n";
    cout<<"Score: "<<score<<"\n";
    if (inventory.empty()) {
        cout << "No item in inventory!";
    } else {
        for (int i = 0; i < inventory.size(); i++) {
            cout << inventory[i].GetName();
            if (i < inventory.size() - 1)
                cout << ", ";
        }
    }
    cout << "\n";
}
void player::DisplayGreetings() {
    cout << "\n Welcome " << name << " to the Magic World of Gumball!\n";
    cout << "Your mission is to escape while you still have lives! \n";
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

GameState player::toGameState(int scenarioID) const {
    GameState state;
    state.playerName = name;
    state.health = health;
    state.lives = lives;
    state.attack_power = attack_power;
    state.scenarioID = scenarioID;
    state.score=score;
    for (const auto& it : inventory)
        state.inventory.push_back(it.GetName());

    return state;
}
void player::fromGameState(const GameState& state) {
    name = state.playerName;
    health = state.health;
    lives = state.lives;
    attack_power = state.attack_power;
    score=state.score;
    inventory.clear();
    for (const auto& itemName : state.inventory)
        inventory.push_back(item(itemName, "Unknown", 0, 0));
}

