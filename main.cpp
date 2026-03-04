#include <iostream>
#include <limits>
#include <string>
using namespace std;

class item {
public:
    string item_name;
    string item_type;
    int health_effect;
    int attack_effect;
};

class player {
public:
    string players_name;
    int players_health;
    int attack_power;
    int life_count;

    bool hasCrystalBall=false;
    bool hasPotionJuice=false;

    player(string name) {
        players_name= name;
        players_health=100;
        life_count=5;
        attack_power=5;
    }

    void PrintStatus(){
        cout<<"\n---PLAYER'S STATUS---" "\n";
        cout<<"Player's name: "<<players_name<<"\n";
        cout<<"Player's health: "<<players_health<<"\n";
        cout<<"Lives : "<<life_count<<"\n";
        cout<<"Attack power: "<<attack_power<<"\n";



    }
    void DisplayGreetings() {
        cout<<"\n---Welcome" " "<< players_name <<" "  "To Magic World of Gumball---";
        cout<< "\n---Your mission "<<players_name<<" " "is to escape the magic world of gumball while you have lives!---"<<endl;

    }


};
int ValidChoice(int min, int max) {
    int choice;
    bool valid=false;

    while (!valid) {
        cout<<"Enter choice("<<min<<"-"<<max<<"):";

        if (cin>>choice) {
            if (choice>= min && choice<=max) {
                valid=true;
            }else {
                cout<<"Please enter a number between"<<min<<"-"<<max;
            }

        }else {
            cout<<"Invalid input choice!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return choice;

}


void scenario1(player &player) {
    cout<<"\n---Scene 1: The talking trees---";
    cout<<"You wake up in dark forest with various unknown creatures\n";
    cout<<"Two trees whisper to you\n";
    cout<<"Tree A is huge and has a lot of leaves\n";
    cout<<"Tree B is small and has a lot of fruits\n";
    cout<<"Tree A: 'Follow me to the safe path'\n";
    cout<<"Tree B: 'No i'm the true safe path!'\n";
    cout << "1) Follow Tree A\n2) Follow Tree B\n";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"Tree A leads you to a swamp filled with snakes -10 health.\n";
        player.players_health -=10;
    }else {
        cout<<"Tree B leads you to a safe bridge";
    }
};

void scenario2(player&player) {
    cout<<"\n---SCENARIO 2: PUZZLE-THE BRIDGE---";
    cout<<"The bridge has a gap.It talks:\n";
    cout<<"What kind of band never plays music\n";
    cout << "1) A rubber band\n2) A chicken\n";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"The bridge gap is removed. Correct +5 health! \n";
        player.attack_power +=5;
    }else {
        cout<<"The bridge path didn't close forced to fall into swamp.Wrong -10 health!\n";
        player.players_health -=10;

    }


}
void scenario3(player &player) {
    cout<<"\n---SCENARIO 3:CRYSTAL BALL---\n";
    cout<<"\n You find a crystal ball behind a pink gumball \n";
    cout << "1) Take it\n2) Leave it\n";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"You have a crystal ball. It glows brighter!\n";
        player.hasCrystalBall=true;
    } else {
        cout<<"You left the crystal ball!";
    }
}

void scenario4(player &player) {
    cout<<"\n---SCENARIO 4:MATH PUZZLE---\n";
    cout<<"A magic math floating carpet:\n ";
    cout << "Which is an even number out of the options? \n";
    cout << "1) 18\n2)7\n ";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"Correct! You unlocked a new path surrounde by cotton candy!.";
    }else {
        cout<<"Incorrect! Lightning strikes!\n";
        player.players_health -=10;
    }
}

void scenario5(player &player) {
    cout<<"\n---SCENRIO 5:ITEM-POTION JUICE---\n";
    cout<<"A fairy offers you a potion juice\n";
    cout << "1)Collect it and drink it\n2) Refuse\n";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"Good energy boost!+15 Health.\n";
        player.hasPotionJuice;
    } else {
        cout<<"You didn't acquire any juice\n";
    }

}
void scenario6 (player &player) {
    cout<<"\n---SCENARIO 6:ANAGRAM PUZZLE DOOR---\n";
    cout<<"\n The brick door shows random glowing letters!'C E E R U C S'\n";
    cout<<"\n Which word unlocks the brick door\n";
    cout << "1) SECURE\n2) RESCUE\n";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"\n Right answer! Door opens.\n";
    } else {
        cout<<"\n Wrong answer! The door releases arrows which pierce you!";
        player.players_health-=15;
    }

}
void scenario7(player &player) {
    cout<<"\n---SCENARIO 7:PUZZLE-SMART QUESTION---";
    cout<<"\n A magic goblin comes up and says:\n";
    cout<<"\n Which comes first lightning or thunder? ";
    cout << "\n 1) They come at the same time\n2) Lightning\n";

    int choice=ValidChoice(1,2);
    if  (choice==1) {
        cout<<"\n Wrong!The goblin heats you with his stick and chews on your arm\n";
        player.players_health -=20;
    } else {
        cout<<"\nCorrect! Goblin disappears";
    }
}

void scenario8(player &player) {
    cout<<"\n---SCENARIO 8: BATTLE OF GUMBALL---\n";
    cout<<"\n You reach the battle ground. The gumball guard approaches you!";
    cout<<"\n 1)Attack the gumball guard \n 2)Use the crystal to blast the ground and door \n ";

    int choice=ValidChoice(1,2);
    if (choice==1) {
        cout<<"You attack with"<<player.attack_power;
        if (player.attack_power>=20) {
            cout<<"\n You defeat the gumball guard";
        } else {
            cout<<"\n Your avatar is weak!\n";
            player.players_health -=20;
        }
    } else {
        if (player.hasCrystalBall) {
            cout<<"\n The crystal ball saved you! You escaped the magic world of gumball!\n";
        } else {
            cout<<"\n You don't possess the ball! The guard attacks -20 health\n";
            player.players_health;
        }
    }
}

int main() {
    cout<<"Welcome to magic world of gumball!\n";
    cout<<"\n  Enter player's name: ";
    string name;
    getline(cin ,name);

    player p(name);
    p.DisplayGreetings();
    p.PrintStatus();

    scenario1(p);
    scenario2(p);
    scenario3(p);
    scenario4(p);
    scenario5(p);
    scenario6(p);
    scenario7(p);
    scenario8(p);

    cout<<"\n---GAME OVER---";
    p.PrintStatus();

    if (p.players_health>0) {
        cout<<"Congratulations"<<p.players_name<<"! you survived the magic world of gumball!";
    }else {
        cout<<"\n You didn't survive the Magic World Of Gumball!\n";
    }

};
