cmake_minimum_required(VERSION 4.1)
project(IY453_Coursework_P493421)

set(CMAKE_CXX_STANDARD 20)

add_executable(IY453_Coursework_P493421 main.cpp
        Scenario.cpp
        Scenario.h
        Item.cpp
        Item.h
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        story_scenario.cpp
        story_scenario.h
        combat_scenario.cpp
        combat_scenario.h
        item_scenario.cpp
        item_scenario.h
        puzzle_scenario.cpp
        puzzle_scenario.h
)
