//
// Created by Motunrayo on 3/10/2026.
//

#include "Scenario.h"
#include "Item.h"
#include <iostream>
using namespace std;

// SCENARIO 1
void Scenario1::run(Player &p) {
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


void Scenario2::run(Player &p)  {
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


void Scenario3::run(Player &p)  {
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

}


void Scenario4::run(Player &p)  {
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

void Scenario5::run(Player &p)  {
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


void Scenario6::run(Player &p)  {
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

void Scenario7::run(Player &p)  {
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

void Scenario8::run(Player &p) {
    cout << "\n--- SCENARIO 8: FINAL BATTLE ---\n";
    cout<<"The tunnel opens into a vast crystalline arena, its walls shimmering with swirling colors. ";
    cout<<"At the center stands a towering guardian forged from living stone and enchanted metal. ";
    cout<<"Its golden eyes lock onto you, and the ground trembles as it raises its weapon. ";
    cout<<"This is the final trial—your last obstacle before escaping the Magic World of Gumball.";

    cout << "\n 1) Attack the guard\n2) Use the crystal ball\n";


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

        if (p.hasItem("Crystal ball")) {
            cout << "The crystal ball blasts the ground! You escape!\n";
        } else {
            cout << "You don't have the crystal! Guard attacks. -20 health.\n";
            p.takeDamage(20);
        }
    }
}



