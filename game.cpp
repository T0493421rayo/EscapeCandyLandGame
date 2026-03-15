#include "game.h"
#include "story_scenario.h"
#include "item_scenario.h"
#include "combat_scenario.h"
#include "puzzle_scenario.h"
#include "item.h"
#include "player.h"

void WhisperingBridgeEffect(int choice,player&p) {
    if (choice==1) {
        cout<<"Correct!+5 attack points.\n";
        p.IncreaseAttack(5);
    }else {
        cout<<"Wrong! You fall into a swamp. -10 health.\n";
        p.TakeDamage(10);
    }
}
void MathsPuzzleEffect(int choice , player&p) {
    if (choice==1) {
        cout<<"Correct!+5 attack points.\n";
        p.IncreaseAttack(5);
    }else {
        cout<<"Wrong! Lightning strikes you!. -10 health.\n";
        p.TakeDamage(10);
    }

}
void AnagramPuzzleEffect(int choice , player&p) {
    if (choice==1) {
        cout<<"Correct!+5 attack points.\n";
        p.IncreaseAttack(5);
    }else {
        cout<<"Wrong!Arrow hits you!. -10 health.\n";
        p.TakeDamage(10);
    }

}
void NaturePuzzleEffect(int choice, player &p) {
    if (choice == 2) {
        cout << "Correct! Goblin disappears.\n";
    } else {
        cout << "Wrong! Goblin hits you. -20 health.\n";
        p.TakeDamage(20);
    }
}


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
    "The forest path ends at a narrow bridge glowing with faint magic.\n"
    "A sudden chill runs through the air as the planks shift beneath your feet.\n"
    "A low voice murmurs: \"Traveler, answer my riddle to cross.\"\n"
    "What kind of band never plays music?\n"
    "1) A rubber band\n"
    "2) A chicken\n",
    1, 2,
    WhisperingBridgeEffect
    ));

    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 3: THE CRYSTAL BALL ---\n"
        "After crossing the whispering bridge, the path winds into a quiet clearing.\n"
        "A soft glow pulses behind a cluster of pink gumballs, as if calling your name.\n"
        "You brush them aside and uncover a small crystal sphere humming with faint magic.\n",
        item("Crystal ball", "Magic Item", 0, 0)
    ));
    scenes.push_back(new PuzzleScenario(
       "\n--- SCENARIO 4: MATH PUZZLE ---\n"
       "Beyond the clearing, the path narrows into a corridor of tall candy canes.\n "
       "Strange symbols glow faintly along their stripes, shifting as you walk past.\n"
       "A stone tablet rises from the ground, humming with quiet magic, and numbers \n"
       "Which number is even?\n"
       "1) 18\n"
       "2) 7\n",
       1, 2,
       MathsPuzzleEffect
   ));
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 5: POTION JUICE ---\n"
        "The air becomes very warm and you see some pixie dust moving quickly\n"
        " A fairy appears from behind the trees swiftly\n"
        " She hovers before you and offers you a potion bottle with a warm smile\n",
        item("Potion Juice", "Healing Item", 15, 0)
    ));

    // SCENE 6 — PUZZLE
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 6: ANAGRAM DOOR ---\n"
        "The forest darkens as you move forward, the trees bending inward like silent watchers.\n "
        "A stone archway rises from the ground, sealed by a heavy door carved with shifting letters. \n"
        "The symbols glow faintly, rearranging themselves as if trying to speak.\n "
        "A low hum fills the air, urging you to solve the word that will unlock the path ahead.\n"
        "Letters: C E E R U C S\n"
        "Which word unlocks the door?\n"
        "1) SECURE\n"
        "2) RESCUE\n",
        1, 2,
        AnagramPuzzleEffect
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 7: SMART QUESTION ---\n"
        "Beyond the unlocked door, a narrow tunnel crackles with static energy. "
        "Sparks dance along the walls, lighting your path in sharp flashes. "
        "A booming voice echoes through the chamber, its tone both ancient and impatient. "
        "It demands an answer about the storm that powers this place, testing your understanding of nature itself."
        "Which comes first: lightning or thunder?\n"
        "1) Same time\n"
        "2) Lightning\n",
        1, 2,
        NaturePuzzleEffect
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 8: FINAL BATTLE ---\n"
        "The tunnel opens into a vast crystalline arena, its walls shimmering with swirling colors. "
        "At the center stands a towering guardian forged from living stone and enchanted metal. "
        "Its golden eyes lock onto you, and the ground trembles as it raises its weapon. "
        "This is the final trial—your last obstacle before escaping the Magic World of Gumball."
        "\n 1) Attack the guard\n2) Use the crystal ball\n"
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

        cout << "Your strike caused " << playerDamage << " damage.\n";
        cout << enemyName << "strike caused" << enemyDamage << " damage.\n";

        if (p.GetHealth() <= 0) {
            cout << "\nYou were defeated!\n";
            return false;
        }
    }
    cout << "\nYou defeated the " << enemyName << "!\n";
    return true;
}


