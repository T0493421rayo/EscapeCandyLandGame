# C++ Escape Candy-Text-Based Adventure Game

A text-based choose-your-own-adventure game developed in **C++** using object-oriented programming principles. The player explores a branching candy-themed world containing puzzles, combat encounters, item collection, and multiple possible paths.

The project was developed as part of the **IY453 Software Design and Implementation** coursework.

## Features

* Branching choose-your-own-adventure gameplay
* **34 scenarios/end states** implemented in the game
* Binary choices that determine the player's next scenario
* Player name integration and personalised game interaction
* Multiple scenario types:

  * Story scenarios
  * Puzzle scenarios
  * Combat scenarios
  * Item collection scenarios
* Puzzle challenges including:

  * Riddles
  * Mathematics questions
  * Anagrams
  * General knowledge questions
* Combat encounters against different enemies
* Player health, attack, lives and score systems
* Inventory system with collectible items
* Items that can affect player statistics
* Save and load functionality using game-state data
* Input validation for player choices
* Game-over and life-loss mechanics
* End-of-game player status display
* Object-oriented class structure
* Polymorphic scenario execution
* Dynamic memory management for scenario objects

## Gameplay

The player progresses through a series of interconnected scenarios.

At each scenario, the player is presented with two choices. Depending on the selected option, the game can:

* Move the player to another scenario
* Trigger a puzzle
* Start a combat encounter
* Provide an item
* Change player statistics
* Cause health loss
* Lead towards a different branch of the story
* Eventually reach the ending or game over

The game maintains the player's current state throughout the adventure.

## Scenario System

The game uses different scenario classes to represent different types of gameplay.

Examples include:

### Story Scenarios

Used for narrative sections and player decisions.

### Puzzle Scenarios

Used for challenges such as:

* The Whispering Bridge riddle
* Mathematics questions
* Anagram challenges
* Knowledge-based questions

Correct and incorrect answers can produce different effects on the player's statistics and score.

### Combat Scenarios

The player encounters enemies with defined health, attack and defence values.

Combat calculates damage based on the player's attack and the enemy's defence, while the enemy can damage the player's health.

Examples of enemies implemented include:

* Stone Guardian
* Licorice Spider
* Cocoa Beast
* Candy Bandits
* Caramel Wraith
* Peppermint Knight
* Sugar Serpent
* Candy Golem
* Sour Bat Swarm
* Frosted Minotaur

### Item Scenarios

The player can discover and collect items such as:

* Crystal Ball
* Potion Juice
* Sugar Lantern
* Strawberry Shield
* Blueberry Amulet

Items can provide effects such as additional attack, defence or healing.

## Player System

The player maintains several gameplay attributes, including:

* Name
* Health
* Attack
* Lives
* Score
* Inventory

The player can also:

* Take damage
* Increase attack
* Add score
* Lose lives
* View inventory
* Save the current game state
* Restore a previously saved state

## Save and Load System

The game includes a save-state system using a `GameState` structure.

The player's current state can be converted into a saveable representation and restored when loading:

* Player information
* Current scenario
* Gameplay statistics
* Inventory/state information supported by the player state

This allows the player to save their progress and resume from the stored scenario.

## Object-Oriented Design

The project uses object-oriented programming to separate gameplay responsibilities.

The scenario system uses a common scenario interface/base class with specialised scenario implementations.

Examples include:

* `StoryScenario`
* `PuzzleScenario`
* `CombatScenario`
* `ItemScenario`

Scenarios are stored using base-class pointers and executed polymorphically:

```cpp
scenario *s = scenes[current];
int next = s->run(p);
```

This allows the game engine to execute different scenario types through a common interface.

### Key OOP Principles

**Encapsulation**

Player functionality and state are managed through the `player` class and its member functions.

**Inheritance**

Specialised scenario classes build upon the common scenario structure.

**Polymorphism**

Different scenario types can be executed through a common `scenario` pointer and the `run()` function.

**Modularity**

Game logic is separated into multiple classes and source/header files, including scenario, player, item and save-game functionality.

## Memory Management

Scenario objects are dynamically allocated and stored by the game.

The `game` destructor releases the allocated scenario objects:

```cpp
game::~game() {
    for (scenario *s : scenes) {
        delete s;
    }
}
```

This prevents dynamically allocated scenario objects from remaining in memory after the game ends.

## Error Handling and Input Validation

The game validates menu choices before continuing gameplay.

For example, the main game menu accepts:

1. Continue
2. View Inventory
3. Save Game

Invalid selections are handled through the game's choice-validation functionality.

The game also checks the player's health after scenarios and handles life loss when health reaches zero.

## Project Structure

The project is organised into separate components for the different parts of the game.

```text
.
├── game.cpp
├── game.h
├── player.cpp
├── player.h
├── item.cpp
├── item.h
├── scenario files
├── story_scenario
├── puzzle_scenario
├── combat_scenario
├── item_scenario
├── save_game
├── CMakeLists.txt
└── README.md
```

## Technologies

* **C++**
* **C++17**
* **Object-Oriented Programming**
* **CMake**
* **CLion**
* Text-based console interface
* File-based game-state persistence

## Running the Project

### Requirements

* C++17-compatible compiler
* CMake
* CLion or another compatible C++ IDE

### Using CLion

1. Clone the repository.
2. Open the project in CLion.
3. Allow CLion to load the CMake project.
4. Build the project.
5. Run the executable.
6. Follow the instructions displayed in the console.

## Gameplay Controls

The game uses numbered choices displayed in the console.

For example:

```text
1. Continue
2. View Inventory
3. Save game
```

Enter the number corresponding to your chosen action.

During scenarios, select one of the two available choices to determine how the story progresses.

## Scoring

The player can earn points through successful gameplay actions.

For example, successfully completing certain puzzles increases the player's attack and score.

The current score is displayed during gameplay, and the final player status is displayed when the game ends.

## Coursework Context

**Module:** IY453 Software Design and Implementation
**Assessment:** Coursework Stage 4
**Language:** C++
**Development environment:** CLion
**Standard:** C++17+

The project focuses on software design, object-oriented programming, branching game logic, file handling, input validation, testing and modular software development.

## Version Control

The project is maintained using Git and GitHub.

Development history can be used to track changes to the implementation and documentation throughout the project.

## Testing

Testing covers gameplay functionality including:

* Player choices
* Scenario transitions
* Puzzle outcomes
* Combat encounters
* Item collection
* Player statistics
* Inventory functionality
* Save/load functionality
* Invalid input handling
* Game-over conditions

**Detailed testing results and measured pass rates will be added after the implementation has been independently tested.**

## Future Improvements

Potential improvements include:

* Expanding the combat system with additional mechanics
* Adding more varied item effects
* Increasing puzzle variety
* Improving save-file error handling
* Expanding automated testing
* Improving the user interface and gameplay feedback
* Adding additional branching paths and endings

## Author

Developed as an individual C++ software development project.

