//
// Created by Motunrayo on 3/10/2026.
//

#include "scenario.h"
#include "item.h"
#include <iostream>
using namespace std;

scenario::scenario(int sid1, int sid2){
    scene_id1 = sid1;
    scene_id2 = sid2;
}
int scenario::GetNext(int choice){
    return (choice == 1 ? scene_id1 : scene_id2);
}

