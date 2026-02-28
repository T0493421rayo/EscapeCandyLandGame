#include <iostream>
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

    player(string name) {
        players_name= name;
        players_health=100;
        life_count=5;
        attack_power=5;
    }

    void printStatus(){
        cout<<"\n---PLAYER'S STATUS---" "\n";
        cout<<"Player's name: "<<players_name<<"\n";
        cout<<"Player's health: "<<players_health<<"\n";
        cout<<"Lives : "<<life_count<<"\n";
        cout<<"Attack power: "<<attack_power<<"\n";



    }
    void displayGreeting() {
        cout<<"\n---Welcome" " "<< players_name <<" "  "To Magic World of Gumball---";
    }


};


class scenario {
public:
};


int main() {
    cout<<"Welcome to magic world of gumball!\n";
    cout<<"\n  Enter player's name: ";
    string name;
    getline(cin ,name);

    player p(name);
    p.displayGreeting();
    p.printStatus();
};
