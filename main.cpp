#include <iostream>
#include <string>
using namespace std;

class item {
public:
    string itemname;
    string itemtype;
    int healtheffect;
    int attackeffect;
};

class player {
private:
    string playersname;
    int playershealth;
    int attackpower;
public:
    player(string name) {
        playersname= name;

    }
    void displayGreeting() {
        cout<<"\n Welcome" " "<< playersname <<" "  "To Magic World of Gumball";
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
};
