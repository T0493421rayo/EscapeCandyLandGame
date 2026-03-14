#include "game.h"
#include "story_scenario.h"
#include "item_scenario.h"
#include "combat_scenario.h"
#include "puzzle_scenario.h"
#include "item.h"
#include "player.h"

game::game(const std::string &playerName):p(playerName){
    running=true;
}
game::~game() {
    for (scenario*s:scenes) {
        delete s;
    }
};
void game::StartGame() {
    p.DisplayGreetings();
    LoadScenarios();

    for (scenario*s :scenes) {
        if (p.GetHealth()<=0&&p.GetLives()<=0) {
            cout<<"\n No live left!";
            break;
        }
        s->run(p);
        if (p.GetHealth()<=0) {
            p.LoseLife();
            if (p.GetLives()<=0) {
                cout<<"No lives left!\n";
                break;
            }
        }
    }
    cout<<"THE END OF THE MAGIC WORLD OF GUMBALL\n";
}


void game::LoadScenarios() {
    scenes.push_back(new StoryScenario(
        "\n--- SCENE 1: TALKING COTTON CANDY TREES ---\n"
        "Tree A is a fluffy blue cotton candy!\n"
        "Tree B is a fluffy red cotton candy!\n"
        "Tree A: 'Follow me to the safe path'\n"
        "Tree B: 'No, he's lying I'm the actual safe path!'\n"
        "1) Follow Tree A\n"
        "2) Follow Tree B\n"
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 2: THE WHISPERING BRIDGE ---\n"
        "What kind of band never plays music?\n"
        "1) A rubber band\n"
        "2) A chicken\n",
        1, 2,
        [](int choice, player &p) {
            if (choice == 1) {
                cout << "Correct! +5 attack.\n";
                p.IncreaseAttack(5);
            } else {
                cout << "Wrong! You fall into a swamp. -10 health.\n";
                p.TakeDamage(10);
            }
        }
    ));

    // ITEM SCENE
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 3: THE CRYSTAL BALL ---\n"
        "You obtained the crystal ball!\n",
        item("Crystal ball", "Magic Item", 0, 0)
    ));

    // PUZZLE SCENE (MATH)
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 4: MATH PUZZLE ---\n"
        "Which number is even?\n"
        "1) 18\n"
        "2) 7\n",
        1, 2,
        [](int choice, player &p) {
            if (choice == 1) {
                cout << "Correct! +5 attack.\n";
                p.IncreaseAttack(5);
            } else {
                cout << "Wrong! Lightning strikes you. -10 health.\n";
                p.TakeDamage(10);
            }
        }
    ));

    // ITEM SCENE
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 5: POTION JUICE ---\n"
        "A fairy gives you a potion. +15 health!\n",
        item("Potion juice", "Healing item", 15, 0)
    ));

    // PUZZLE SCENE (ANAGRAM)
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 6: ANAGRAM DOOR ---\n"
        "Letters: C E E R U C S\n"
        "Which word unlocks the door?\n"
        "1) SECURE\n"
        "2) RESCUE\n",
        1, 2,
        [](int choice, player &p) {
            if (choice == 1) {
                cout << "Correct! The door opens.\n";
            } else {
                cout << "Wrong! Arrow hits you. -10 health.\n";
                p.TakeDamage(10);
            }
        }
    ));

    // PUZZLE SCENE (NATURE)
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 7: SMART QUESTION ---\n"
        "Which comes first: lightning or thunder?\n"
        "1) Same time\n"
        "2) Lightning\n",
        1, 2,
        [](int choice, player &p) {
            if (choice == 2) {
                cout << "Correct! Goblin disappears.\n";
            } else {
                cout << "Wrong! Goblin hits you. -20 health.\n";
                p.TakeDamage(20);
            }
        }
    ));

    //
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 8: FINAL BATTLE ---\n"
        "A towering guardian blocks your path!\n",
        50, 15, "Stone Guardian"
    ));

    //for combat scenes
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 9: GUMMY BEAR ATTACK ---\n"
        "A giant red gummy bear leaps at you!\n",
        40, 10, "Gummy Bear"
    ));
}
bool game::Combat(player &p, int enemyHealth, int enemyAttack, int enemyDefence, const std::string &enemyName) {
    cout<<"You vs"<<enemyName<<"/n";
    while (p.GetHealth() > 0 && enemyHealth > 0) {
        int playerDamage = p.GetAttack() - enemyDefence;
        if (playerDamage < 0) playerDamage = 0;

        int enemyDamage = enemyAttack - p.GetHealth();
        if (enemyDamage < 0) enemyDamage = 0;

        enemyHealth -= playerDamage;
        p.TakeDamage(enemyDamage);

        cout << "You deal " << playerDamage << " damage.\n";
        cout << enemyName << " deals " << enemyDamage << " damage.\n";

        if (p.GetHealth() <= 0) {
            cout << "\nYou were defeated!\n";
            return false;
        }
    }
    cout << "\nYou defeated the " << enemyName << "!\n";
    return true;
}


