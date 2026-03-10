#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Item {
public:
    string name;
    string type;
    int healthEffect;
    int attackEffect;

    Item(string name,string type,int health,int attack) {
        name=name;
        type=type;
        healthEffect=health;
        attackEffect=attack;
    }

};

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
    Player(string name) {
        name = name;
        health = 100;
        attackPower = 5;
        lives = 5;
        crystalBall = false;
        potionJuice = false;
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    void heal(int amount) {
        health += amount;
    }

    void increaseAttack(int amount) {
        attackPower += amount;
    }
    void addItem(Item item) {
        inventory.push_back(item);

        cout<<"\nYou got:"<<item.name<<"("<<item.type<<")/n";

        if (item.healthEffect!=0) {
            cout<<"Health Effect:"<<item.healthEffect<<"\n";
            heal(item.healthEffect);
        }
    }

    bool hasItem(string itemName) {
        for (int i=0;i<inventory.size();i++) {
            if (inventory[i].name==itemName)
                return true;
        }
        return false;
    }

    int getAttack() {
        return attackPower;
    }
    int getHealth() {
        return health;
    }
    string getName() {
        return name;
    }


    void printStatus() {
        cout << "\n--- PLAYER STATUS ---\n";
        cout << "Name: " << name << "\n";
        cout << "Health: " << health << "\n";
        cout << "Lives: " << lives << "\n";
        cout << "Attack Power: " << attackPower << "\n";

        cout<<"Inventory:";
        if (inventory.empty()) {
            cout<<"No item in inventory!";
        }else {
            for (int i=0;i<inventory.size();i++) {
                cout<<"None/n";
                if (i<inventory.size()-1) cout<<",";
            }
            cout<<"\n";
        }
    }

    void displayGreetings() {
        cout << "\n--- Welcome " << name << " to the Magic World of Gumball! ---\n";
        cout << "--- Your mission is to escape while you still have lives! ---\n";
    }
};


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


class Scenario {
public:
    virtual void run(Player &p) {
        cout << "Base scenario.\n";
    }
};

// SCENARIO 1
class Scenario1 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENE 1: TALKING COTTON CANDY TREES ---\n";
        cout<<"Tree A is a fluffy blue cotton candy!\n";
        cout<<"Tree B is a fluffy red cotton candy!\n ";
        cout << "Tree A: 'Follow me to the safe path'\n";
        cout << "Tree B: 'No, he's lying I'm the actual safe path!'\n";
        cout << "1) Follow Tree A\n2) Follow Tree B\n";

        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "Tree A leads you into a snake swamp! -10 health.\n";
            p.takeDamage(10);
        } else {
            cout << "Tree B leads you safely across a bright brick red bridge.\n";
        }
    }
};

// SCENARIO 2
class Scenario2 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 2: THE WHISPERING BRIDGE ---\n";
        cout << "The forest path ends at a narrow bridge glowing with faint magic.\n";
        cout << "A sudden chill runs through the air as the planks shift beneath your feet.\n"; // ← one extra line
        cout << "A low voice murmurs: \"Traveler answer my riddle to cross.\"\n\n";
        cout << "What kind of band never plays music?\n";
        cout << "1) A rubber band\n2) A chicken\n";

        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "\nThe bridge hums approvingly.The gap closes!.\n";
            cout << "A warm glow surrounds you, strengthening your resolve. +5 attack power.\n";
        } else {
            cout<<"\n The bridge groans in disappointment.The bridge collapses!\n";
            cout << "Wrong! You fall into a swamp. The swamp candy snakes feast on you! -10 health.\n";
            p.takeDamage(10);
        }
    }
};

// SCENARIO 3
class Scenario3 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 3: THE CRYSTAL BALL ---\n";
        cout << "After crossing the whispering bridge, the path winds into a quiet clearing.\n";
        cout << "A soft glow pulses behind a cluster of pink gumballs, as if calling your name.\n";
        cout << "You brush them aside and uncover a small crystal sphere humming with faint magic.\n\n";

        cout << "1) Take the crystal ball\n";
        cout << "2) Leave it\n";

        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout<<"The crystal ball glows brighty as you picked it up!";
            cout << "You obtained the crystal ball!\n";
            Item crystal("Crystal ball","Magic Item",0,0);
            p.addItem(crystal);
        } else {
            cout << "You left the crystal ball behind!\n";
        }
    ;
    }
};

// SCENARIO 4
class Scenario4 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 4: MATH PUZZLE ---\n";
        cout<<"Beyond the clearing, the path narrows into a corridor of tall candy canes. ";
        cout<<"Strange symbols glow faintly along their stripes, shifting as you walk past. ";
        cout<<"A stone tablet rises from the ground, humming with quiet magic, and numbers ";

        cout << "Which number is even?\n";
        cout << "1) 18\n2) 7\n";

        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "Correct! A new path opens.\n";
        } else {
            cout << "Wrong! Lightning strikes you. -10 health.\n";
            p.takeDamage(10);
        }
    }

};

// SCENARIO 5
class Scenario5 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 5: POTION JUICE ---\n";
        cout<<"\nThe air becomes very warm and you see some pixie dust moving quickly\n";
        cout<<"\n A fairy appears from behind the trees swiftly\n";
        cout<<"\n She hovers before you and offers you a potion bottle with a warm smile\n";

        cout << "1) Drink it\n2) Refuse\n";

        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            Item potion("Potion juice","Healing item",15,0);
            p.addItem(potion);
            cout << "You feel energized! +15 health.\n";

            p.heal(15);

        } else {
            cout << "You refused the potion!\n";
        }
    }
};

class Scenario6 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 6: ANAGRAM DOOR ---\n";
        cout<<"The forest darkens as you move forward, the trees bending inward like silent watchers. ";
        cout<<"A stone archway rises from the ground, sealed by a heavy door carved with shifting letters. ";
        cout<<"The symbols glow faintly, rearranging themselves as if trying to speak. ";
        cout<<"A low hum fills the air, urging you to solve the word that will unlock the path ahead.";
        cout << "Letters: C E E R U C S\n";

        cout << "Which word unlocks the door?\n";
        cout << "1) SECURE\n2) RESCUE\n";


        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "Correct! The door opens!.\n";
        } else {
            cout << "Wrong! Arrow strikes you on the chest and you groan in pain!. -10 health.\n";
            p.takeDamage(10);
        }
    }
};

class Scenario7 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 7: SMART QUESTION ---\n";
        cout<<"Beyond the unlocked door, a narrow tunnel crackles with static energy. ";
        cout<<"Sparks dance along the walls, lighting your path in sharp flashes. ";
        cout<<"A booming voice echoes through the chamber, its tone both ancient and impatient. ";
        cout<<"It demands an answer about the storm that powers this place, testing your understanding of nature itself.";

        cout << "Which comes first: lightning or thunder?\n";
        cout << "1) Same time\n2) Lightning\n";


        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "Wrong! Goblin hits you. -20 health.\n";
            p.takeDamage(20);
        } else {
            cout << "Correct! Goblin disappears.\n";
        }
    }
};

class Scenario8 : public Scenario {
public:
    void run(Player &p) override {
        cout << "\n--- SCENARIO 8: FINAL BATTLE ---\n";
        cout<<"The tunnel opens into a vast crystalline arena, its walls shimmering with swirling colors. ";
        cout<<"At the center stands a towering guardian forged from living stone and enchanted metal. ";
        cout<<"Its golden eyes lock onto you, and the ground trembles as it raises its weapon. ";
        cout<<"This is the final trial—your last obstacle before escaping the Magic World of Gumball.";

        cout << "1) Attack the guard\n2) Use the crystal ball\n";


        int choice = ValidChoice(1, 2);

        if (choice == 1) {
            cout << "You attack with " << p.getAttack() << " power.\n";
            if (p.getAttack() >= 20) {
                cout << "You defeated the guard!\n";
            } else {
                cout << "Too weak! The guard hits you. -20 health.\n";
                p.takeDamage(20);
            }
        } else {

            if (p.hasItem("Crystal Ball")) {
                cout << "The crystal ball blasts the ground! You escape!\n";
            } else {
                cout << "You don't have the crystal! Guard attacks. -20 health.\n";
                p.takeDamage(20);
            }
        }
    }
};
class Game {
private:
    Player player;
    vector<Scenario*> scenes;

public:
    Game(const string& playerName) : player(playerName) {
        Scenario1* s1 = new Scenario1();
        Scenario2* s2 = new Scenario2();
        Scenario3* s3 = new Scenario3();
        Scenario4* s4 = new Scenario4();
        Scenario5* s5 = new Scenario5();
        Scenario6* s6 = new Scenario6();
        Scenario7* s7 = new Scenario7();
        Scenario8* s8 = new Scenario8();
        scenes = { s1, s2, s3, s4, s5, s6, s7, s8 };
    }



    void start() {
        cout << "Welcome to the Magic World of Gumball!\n";
        player.displayGreetings();
        player.printStatus();

        for (Scenario* s : scenes) {
            s->run(player);

            if (player.getHealth() <= 0) {
                cout << "\nYou died! Game over.\n";
                return;
            }
        }

        cout << "\n--- GAME OVER ---\n";
        player.printStatus();

        if (player.getHealth() > 0) {
            cout << "Congratulations " << player.getName() << "! You survived!\n";
        } else {
            cout << "You did not survive the Magic World of Gumball.\n";
        }
    }
};

int main() {
    cout << "Welcome to the Magic World of Gumball!\n";
    cout << "Enter player's name: ";

    string name;
    getline(cin, name);

    Game game(name);
    game.start();

    return 0;
}