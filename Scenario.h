//
// Created by Motunrayo on 3/10/2026.
//

#ifndef IY453_COURSEWORK_P493421_SCENARIO_H
#define IY453_COURSEWORK_P493421_SCENARIO_H


#include "Player.h"
#include <iostream>
using namespace std;


class Scenario {
public:
    virtual void run(Player &p) {
        cout << "Base scenario.\n";
    }
};

class Scenario1 : public Scenario {public: void run(Player &p) override;};
class Scenario2 : public Scenario {public: void run(Player &p) override;};
class Scenario3 : public Scenario {public: void run(Player &p) override;};
class Scenario4 : public Scenario {public: void run(Player &p) override;};
class Scenario5 : public Scenario {public: void run(Player &p) override;};
class Scenario6 : public Scenario {public: void run(Player &p) override;};
class Scenario7 : public Scenario {public: void run(Player &p) override;};
class Scenario8 : public Scenario {public: void run(Player &p) override;};








#endif //IY453_COURSEWORK_P493421_SCENARIO_H
