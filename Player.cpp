//
// Created by Motunrayo on 3/10/2026.
//
#include "Player.h"
#include <limits>

Player::Player(string name) {
    this->name = name;
    health = 100;
    attackPower = 5;
    lives = 5;
    crystalBall = false;
    potionJuice = false;
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

void Player::heal(int amount) {
    health += amount;
}

void Player::increaseAttack(int amount) {
    attackPower += amount;
}

void Player::addItem(Item item) {
    inventory.push_back(item);

    cout << "\nYou got: " << item.name << " (" << item.type << ")\n";

    if (item.healthEffect != 0) {
        cout << "Health Effect: " << item.healthEffect << "\n";
        heal(item.healthEffect);
    }
}

bool Player::hasItem(string itemName) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].name == itemName)
            return true;
    }
    return false;
}

int Player::getAttack() {
    return attackPower;
}

int Player::getHealth() {
    return health;
}

string Player::getName() {
    return name;
}

void Player::printStatus() {
    cout << "\n--- PLAYER STATUS ---\n";
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Lives: " << lives << "\n";
    cout << "Attack Power: " << attackPower << "\n";

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

void Player::displayGreetings() {
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

#include "Player.h"