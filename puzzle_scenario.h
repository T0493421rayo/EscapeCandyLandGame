
#include "scenario.h"
#include <string>

class PuzzleScenario : public scenario {
private:
    std::string text;
    int minChoice;
    int maxChoice;
    void (*puzzleEffect)(int, player&);

public:
    PuzzleScenario(const std::string &t,int minC,int maxC,void (*effect)(int, player&),int sid1, int sid2);
    int run(player &p) override;
};



