#include "game.h"
#include "story_scenario.h"
#include "item_scenario.h"
#include "combat_scenario.h"
#include "puzzle_scenario.h"
#include "item.h"
#include "player.h"
#include "save_game.h"

void WhisperingBridgeEffect(int choice, player &p) {
    if (choice == 1) {
        cout << "Correct! +5 attack points.\n";
        p.IncreaseAttack(5);
        p.AddScore(5);
    } else {
        cout << "Wrong! You fall into a swamp. -10 health.\n";
        p.TakeDamage(10);

    }
}
void MathsPuzzleEffect(int choice, player &p) {
    if (choice == 1) {
        cout << "Correct! +5 attack points.\n";
        p.IncreaseAttack(5);
        p.AddScore(5);
    } else {
        cout << "Wrong! Lightning strikes you! -10 health.\n";
        p.TakeDamage(10);

    }
}
void AnagramPuzzleEffect(int choice, player &p) {
    if (choice == 1) {
        cout << "Correct! +5 attack points.\n";
        p.IncreaseAttack(5);
        p.AddScore(5);
    } else {
        cout << "Wrong! Arrow hits you! -10 health.\n";
        p.TakeDamage(10);

    }
}
void NaturePuzzleEffect(int choice, player &p) {
    if (choice == 2) {
        cout << "Correct! Goblin disappears.\n";
    } else {
        cout << "Wrong! Goblin hits you. -20 health.\n";
        p.TakeDamage(20);
        p.AddScore(5);
    }
}
game::game(const std::string &playerName) : p(playerName) {
    running = true;
}
game::~game() {
    for (scenario *s : scenes) {
        delete s;
    }
}
int game::LoadFromState(const GameState& state) {
    p.fromGameState(state);
    cout << "Game state loaded successfully.\n";
    return state.scenarioID;
}
void game::StartGame() {
    p.DisplayGreetings();
    LoadScenarios();
    StartGameFromScene(0);
}


void game::StartGameFromScene(int startIndex) {
    int current = startIndex;
    while (current != -1) {
        cout << "\n1. Continue\n";
        cout << "2. View Inventory\n";
        cout << "3. Save game\n";
        int menuChoice = ValidChoice(1, 3);
        if (menuChoice == 2) {
            p.ShowInventory();
            continue;
        }
        if (menuChoice == 3) {
            GameState state = p.toGameState(current);
            save_game::saveGame(state);
            cout <<"Game saved!";
            break;
        }
        scenario *s = scenes[current];
        int next = s->run(p);
        if (p.GetHealth() <= 0) {
            p.LoseLife();
            if (p.GetLives() <= 0) {
                cout <<"No lives left!\n";
                break;
            }
            cout << "\nYou lost a life!\n";
            cout << "Lives left: "<< p.GetLives() << "\n";
            current = next;
            continue;
        }
        current = next;
        cout<<"Current score: "<<p.GetScore()<<"\n";
    }
    p.PrintStatus();
    cout << "THE END OF THE MAGIC WORLD OF GUMBALL\n";
}

void game::LoadScenarios() {
    scenes.push_back(new StoryScenario(
        "\n--- START---"
        "Tree A is a fluffy blue cotton candy!\n"
        "Tree B is a fluffy red cotton candy!\n"
        "Tree A: 'Follow me to the safe path'\n"
        "Tree B: 'No, he's lying I'm the actual safe path!'\n"
        "1) Follow Tree A\n"
        "2) Follow Tree B\n",
        1, 2
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 1: THE WHISPERING BRIDGE ---\n"
        "The forest path ends at a narrow bridge glowing with faint magic.\n"
        "A sudden chill runs through the air as the planks shift beneath your feet.\n"
        "A low voice murmurs: \"Traveler, answer my riddle to cross.\"\n"
        "What kind of band never plays music?\n"
        "1) A rubber band\n"
        "2) A chicken\n",
        1, 2,
        WhisperingBridgeEffect,
        3, 4
    ));
    scenes.push_back(new StoryScenario(
        "\n--- SCENARIO 2: THE DARK PATH ---\n"
        "The forest grows darker and the air becomes heavy.\n"
        "Two bridges with separate pathways appear from a distance\n"
        "One red made of cherry licorice\n"
        "Second is pink made of chewed gumball\n"
        "1) Follow Bridge A\n"
        "2) Follow Bridge B\n",
        5, 6
    ));
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 3: THE CRYSTAL BALL ---\n"
        "After crossing the whispering bridge, the path winds into a quiet clearing.\n"
        "A soft glow pulses behind a cluster of pink gumballs.\n"
        "You uncover a small crystal sphere humming with faint magic.\n",
        item("Crystal ball", "Magic Item", 0, 0),
        7, 8
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 4: MATH PUZZLE ---\n"
        "Beyond the clearing, the path narrows into a corridor of tall candy canes.\n "
        "Strange symbols glow faintly along their stripes, shifting as you walk past. \n"
        "A stone tablet rises from the ground, humming with quiet magic, and numbers .\n"
        "Which number is even?\n"
        "1) 18\n"
        "2) 7\n",
        1, 2,
        MathsPuzzleEffect,
        9, 10
    ));
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 5: POTION JUICE ---\n"
        "The air becomes very warm and you see some pixie dust moving quickly\n"
        " A fairy appears from behind the trees swiftly\n"
        " She hovers before you and offers you a potion bottle with a warm smile\n",
        item("Potion Juice", "Healing Item", 15, 0),
        11, 12
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 6: ANAGRAM DOOR ---"
        "\nThe forest darkens as you move forward, the trees bending inward like silent watchers. "
        "\nA stone archway rises from the ground, sealed by a heavy door carved with shifting letters. "
        "\nThe symbols glow faintly, rearranging themselves as if trying to speak. "
        "\nA low hum fills the air, urging you to solve the word that will unlock the path ahead."
        "\nLetters: C E E R U C S"
        "\nWhich word unlocks the door?"
         "1) SECURE\n2) RESCUE\n",
        1, 2,
        AnagramPuzzleEffect,
        13, 14
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 7: SMART QUESTION ---"
        "\nBeyond the unlocked door, a narrow tunnel crackles with static energy. "
        "\nSparks dance along the walls, lighting your path in sharp flashes. "
        "\nA booming voice echoes through the chamber, its tone both ancient and impatient. "
        "\nIt demands an answer about the storm that powers this place, testing your understanding of nature itself."
        "\nWhich comes first: lightning or thunder?"
        "1) Same time\n"
        "2) Lightning\n",
        1, 2,
        NaturePuzzleEffect,
        15, 16
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 8: GUARDIAN BATTLE ---\n"
        "\nThe tunnel opens into a vast crystalline arena, its walls shimmering with swirling colors. "
        "\nAt the center stands a towering guardian forged from living stone and enchanted metal. "
        "\nIts golden eyes lock onto you, and the ground trembles as it raises its weapon. "
        "\nThis is the final trial—your last obstacle before escaping the Magic World of Gumball."
        "\n 1) Attack the guard\n2) Use the crystal ball\n",
        50, 15, "Stone Guardian",
        17, 18
    ));
    scenes.push_back(new StoryScenario(
     "\n--- SCENARIO 9: THE CANDY FOG ---\n"
        "A thick fog of powdered sugar rolls across the path.\n"
        "Shadows move inside it, whispering your name.\n"
        "Do you walk through or wait for it to clear?\n"
        "1) Walk through\n"
        "2) Wait\n",
        19,20
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 10: THE SWEET SCALE ---\n"
        "A magical scale blocks your path.\n"
        "It glows with two items:\n"
        "A deep voice from a cloud echoes:\n"
        "Which weighs more?\n"
        "1) 1kg of marshmallows\n"
        "2) 1kg of chocolate\n",
        1, 2,
        MathsPuzzleEffect,
        21, 22
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 11: LICORICE SPIDER ---\n"
        "You continue walking until you reach a dark cave\n"
        "Despite, the darkness you decided to enter inside!\n"
        "You see some shadow figurines moving about\n"
        "A giant spider woven from black licorice drops from above.\n",
        40, 12, "Licorice Spider",
        23,24
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 12: COCOA BEAST ---\n"
        "You follow a warm, sticky trail deeper into the forest.\n"
        "The ground begins to bubble beneath your feet, releasing bursts of hot chocolate steam.\n"
        "Suddenly, the bubbling pool rises and forms into a towering creature.\n"
        "A creature made of molten chocolate roars as it emerges from the pool.\n",
        45, 14, "Cocoa Beast",
        25, 26
    ));
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 13: SUGAR LANTERN ---\n"
        "After defeating the Cocoa Beast, the bubbling chocolate pool settles into a calm, glossy surface.\n"
        "A warm breeze sweeps through the clearing, carrying tiny sparkles of sugar through the air.\n"
        "A narrow path reveals itself between two gumdrop boulders, glowing faintly as if guiding you forward.\n"
        "You follow the shimmering trail deeper into the forest, where the air becomes cooler and sweeter.\n"
        "Hanging from a low branch, you notice a soft, pulsing light\n"
        "A glowing lantern made of crystallized sugar hangs from a branch.\n",
         item("Sugar Lantern", "Magic Item", 0, 5),
        27, 28
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 14: LICORICE SPIDER ---\n"
        "With the Sugar Lantern lighting your path, the forest grows darker and the air turns sticky.\n"
        "Licorice webs cling to your arms as you step into a shadowy cave.\n"
        "Shapes crawl along the walls, shifting in the dim glow of your lantern.\n"
        "A giant spider woven from black licorice drops from above, ready to strike.\n ",
        40, 12, "Licorice Spider",
        29, 30
    ));
    scenes.push_back(new StoryScenario(
        "\n--- SCENARIO 15: THE HONEY RIVER ---\n"
        "As you continue, down the path\n"
        "You spot a shiny, viscous liquid flowing\n"
        "A golden river of honey blocks your path.\n"
        "A fairy hovers around your head with a wand.\n"
        "1) Accept fairy help\n"
        "2) Cross alone\n",
        31, 18
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 16: CANDY BANDITS ---\n"
        "Two mischievous candy bandits leap from the bushes.\n",
        55, 16, "Candy Bandits",
        17, 18
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 17: THE COOKIE CODE ---\n"
        "A stone door displays three cookies.\n"
        "Which cookie was invented first?\n"
        "1) Ginger\n"
        "2) Chocolate chip\n",
        1, 2,
        AnagramPuzzleEffect,
        19, 20
    ));
    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 18: STRAWBERRY SHIELD ---\n"
        "Trials and tribulations have got you wondering if you're in a dream\n"
        "The cloud goes dark above your head\n"
        "As the darkness you notice something in the grass\n"
        "A shield shaped like a giant strawberry lies in the grass.\n",
        item("Strawberry Shield", "Defense Item", 0, 10),
        21, 22
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 19: CARAMEL WRAITH ---\n"
        "Your legs get weaker and your head grows heavier\n"
        "In the attempt of a rest\n"
        "You realise you have unexpected company\n"
        "A ghostly wraith dripping with caramel floats toward you.\n",
        50, 15, "Caramel Wraith",
        27,30

    ));
    scenes.push_back(new StoryScenario(
        "\n--- SCENARIO 20: THE SOUR CROSSROADS ---\n"
        "The last adventure got you in despair\n"
        "But you realised you have to keep going\n"
        "Two glowing paths appear.\n"
        "1) Left path\n"
        "2) Right path\n",
        23, 24
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 21: PEPPERMINT KNIGHT ---\n"
        "At some point you hear a parade\n"
        "This feels like a sound of victory not knowing it's another obstacle to accomplish\n"
        "Things turn south faster than you can believe it\n"
        "A knight clad in peppermint armor challenges you.\n",
        70, 20, "Peppermint Knight",
        23, 24
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 22: THE CAKE RIDDLE ---\n"
        "The sky rains down some sprinkles flowing done from the clouds\n"
        "Today might be your lucky day\n"
        "You spot your favorite dessert\n"
        "A magical cake floats in the air.\n"
        "It asks: 'What has layers but is not a cake?'\n"
        "1) An onion\n"
        "2) A cookie\n",
        1, 2,
        NaturePuzzleEffect,
        23, 24
    ));
    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 23: SUGAR SERPENT ---\n"
        "Your sharp ear spots some hissing noises\n"
        "As ths sound grew louder, your body temperature rises\n"
        "A long serpent made of crystallized sugar slithers toward you.\n",
        80, 22, "Sugar Serpent",
        25, 26
    ));
    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 24: THE MATHEMATICAN GUMMY ---\n"
        "Some little children rhyme maths song plays at a distance\n"
        "You hum to the rythm and start tap dancing\n"
        "This lightens your mood\n"
        "A bear leaps and asks you:\n"
        "What comes once in a minute, twice in a moment but never in a thousand years\n"
        "1)M"
        "2)20",
        1, 2,
        MathsPuzzleEffect,
        27, 28
    ));

    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 25: THE CANDY PADLOCK ---\n"
        "A giant padlock is placed on a door with a bunch of letters and a guardian beside\n"
        "The letters are TENILS\n"
        "The guardian ask you to pick the correct unscrambled form\n"
        "1) LISTEN\n"
        "2) SILENT\n",
        1, 2,
        AnagramPuzzleEffect,
        29, 30
    ));

    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 26: THE MARSHMALLOW RIDDLE ---\n"
        "You approach a bed with a pink mastress\n"
        "This is the moment you have been waiting for\n"
        "As soon as you lie in it your fast asleep\n"
        "The wizard asks you:What melts but is never hot?\n"
        "1) Ice\n"
        "2) Chocolate\n",
        1, 2,
        AnagramPuzzleEffect,
        31, 32
    ));


    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 27: CANDY GOLEM ---\n"
        "The ground rumbles profusely causing a panic within you\n"
        "This made you scream in attempt of help from the sky\n"
        "A massive caramel golem emerges from beneath you.\n",
        60, 18, "Candy Golem",
        33, 30
        ));


    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 28: SOUR BAT SWARM ---\n"
        "As it gets dark once more\n"
        "This time you notice some creatures flying in the distance\n"
        "You assume their fairies to alignate your fear\n"
        "A swarm of sour bats screeches overhead.\n",
        35, 10, "Sour Bat Swarm",
        33, 31
    ));

    scenes.push_back(new CombatScenario(
        "\n--- SCENARIO 29: FROSTED MINOTAUR ---\n"
        "Swift flashes of light circle around you\n"
        "In your mind, you think maybe this could be your guardian angel\n"
        "A towering minotaur coated in icy frosting charges.\n",
        75, 25, "Frosted Minotaur",
        33, 32
    ));

    scenes.push_back(new ItemScenario(
        "\n--- SCENARIO 30: BLUEBERRY AMULET ---\n"
        "The winds grow fierce and the cloud rumbles\n"
        "You approach a tree which you sit beneath for some shelther\n"
        "A glowing amulet hangs from a candy cane tree.\n",
        item("Blueberry Amulet", "Magic Item", 0, 5),
        31, 32
    ));

    scenes.push_back(new StoryScenario(
        "\n--- SCENARIO 31: THE COTTON CANDY MAZE ---\n"
        "While you're sitting you sight some pink fluffy favorite sweet of yours\n"
        "This makes you excited and run swiftly towards it as if you were being chased\n"
        "You enter a maze of swirling cotton candy walls.\n"
        "1) Left path\n"
        "2) Right path\n",
        32, 33
        ));


    scenes.push_back(new PuzzleScenario(
        "\n--- SCENARIO 32: THE PUZZLE OF OZ ---\n"
        "The wizard appears with a huge white beard.\n"
        "His deep voice says: \"Traveler, answer my riddle and you'll leave longer.\"\n"
        "I'm tall when i'm young, and short when i'm old"
        "What am i?\n"
        "1) A candle\n"
        "2) A pan\n",
        1, 2,
        AnagramPuzzleEffect,
        3, 4
    ));



    scenes.push_back(new StoryScenario(
        "\n--- SCENARIO 33: THE SUGAR FALLS ---\n"
        "A roaring waterfall of liquid sugar blocks your path.\n"
        "You step forward and disappear into the sweetness.\n",
        34, 34
    ));

    scenes.push_back(new StoryScenario(
        "\n--- ENDING 34: SWEET RELEASE ---\n"
        "You escape the Candy Realm at last.\n",
        -1, -1
    ));

}

bool game::Combat(player &p, int enemyHealth, int enemyAttack, int enemyDefence, const std::string &enemyName) {
    cout << "You vs " << enemyName << "\n";
    while (p.GetHealth() > 0 && enemyHealth > 0) {
        int playerDamage = p.GetAttack() - enemyDefence;
        if (playerDamage < 0) playerDamage = 0;
        int enemyDamage = enemyAttack;
        if (enemyDamage < 0) enemyDamage = 0;
        enemyHealth -= playerDamage;
        p.TakeDamage(enemyDamage);
        cout << "Your strike caused " << playerDamage << " damage.\n";
        cout << enemyName << " strike caused " << enemyDamage << " damage.\n";
        if (p.GetHealth() <= 0) {
            cout << "\nYou were defeated!\n";
            return false;
        }
    }
    cout << "\nYou defeated the " << enemyName << "!\n";
    return true;
}


