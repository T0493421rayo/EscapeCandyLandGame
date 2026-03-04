<style>
</style>

| Module Code            | IY453                              |
| ---------------------- | ---------------------------------- |
| Group                  | A                                  |
| Module Title           | Software Design and Implementation |
| Assessment<br> Type    | Coursework Stage 1                 |
| Module Tutor<br> Name  | Mustafa<br> Ghashim                |
| Student ID<br> Number  | P493421                            |
| Date of<br> Submission | 29/1/26                            |

☒ *I confirm that this assignment is my own work. Where I have
referred to academic sources, I have provided in-text citations and included
the sources in the final reference list.*

 ☒ *Where I have used AI, I have
cited and referenced appropriately.*

**Introduction**

The purpose of the software design and implementation project is a project report which consist of four stages which encompasses the analysis and design which is necessary for the preparation, planning and breaking down of the program specification. Every aspects of the project revolves around this stage. The next stage in  completing for this project report is the implementation which is necessary to integrate the outcomes of the analysis and deisgn stage. Built upon the earlier stages is the testing stage. This stage is very crucial to determine if the program is performing at the right level by putting the program through a series of test in order to prevent any form of bugs before being used at the user's end. The final part of the report is the evaluation stage which is needed for assessing the program's effectiveness.

**Stage 1:Analysis And Design**

Program Specification
The software is designed to create a text-based, engaging adventurous game where the players:

**Functional Requirement**
**Player Interaction and Choices:**

The game would have at least 30 binary choices, which are stages for the player to escape the Magic World of Gumball.                                                                

Each choice leads to a particular scenario whichbranches out the game plot into puzzles, combat, and item collection scenes, which could lead to game over or victory.                                                                                                              Each choice should have a small description of what the user is experiencing and feeling in the game world.                                                                                                                   Provide detailed and personalized feedback on the consequences of each choice, which could be a new scene, weapon, or item collected successfully, a reduction or increase to health or attack power.

The main aim of this requirement is to engage the player in order to keep them informed on what is going to create a sense of the character in the game.

**Inventory and Items Impact:**

An inventory design to collect, save, and view weapons that would aid their journey in The Magic World of Gumball.                                                                

Each player can encounter various items. These items are designed to have an effect on the player's health and attack power in order for survival. For example, weapons will boost the player's attack power for combat scenarios, potions and food will restore the player after combat, keys to unlock doors and new pathways, and clothing will provide a layer of defense.

Each one of those items should create an effect on the player's stats and health when collected and added to the inventory to escape the Magic World of Gumball.

**Save and Resume Functionality:**

Each player should have their previous game saved to be resumed and saved for later in order to continue the escape adventure in the Magic World of Gumball at their own convenience, using text files.

Player's details that were part of the first phase of the game before they saved it, such as the lives count, player's name, scenarios, attack power, and collected items in inventory, should be saved. 

Provide an intuitive interface to allow user's determine whether they would like to start the game from scratch or be able to continue from the saved state.

**Story and Engagement**

Each story must have logical connections between each scenario from the moment they begin the escape from the Magic World of Gumball. This basically means that each binary decision made at any point in time would be a doorway into a new scenario

Each player's details stored during the save and resume functionality, such as the stats and player's name, should help create a personalized experience which would be integrated into dialogues, feedbacks and messages.

**Game play scenario**                                                                                                                 The program should be a collection of various scenarios, such as puzzles, combat-based, and item collection, which should be seamlessly aligned into the game.

The puzzles will either be maths-based, anagrams, or riddles that are designed to test the player's ability to apply logic and critical thinking skills. This would lead to a reward or a different scenario. 

The combat scenario will depend on the player's stats, mainly the inventory containing either weapons, potions,  or clothing. This would determine whether the player is going to be defeated or succeed when faced in combat against an enemy.

The item collection scenario will allow the player to gather the necessary items needed, such as food, clothing, and weapons, to influence the player's stats in order to help the player escape the Magic World of Gumball.

**Score system:**
Each of those game play scenario e.g a combat scene or puzzle scecene should have an effect on their player's score system depending on success or defeat during the escape from the Magic World of Gumball. Successful actions, such as a correct puzzle answer, are designed to increase the player's score, while failures should reduce the player's life count and health status.

Display score board at different critical points e.g after and before a scenario encounter, in order to create a cohesive experience. This would allow the player to know the effect of their decisions.

**Error handling:**
The text based system should make sure the user's input is validated to prevent crashes and errors in the Magic World of Gumball

Error messages should be provided when the user's input doesn't correlate to the data structure of the answer. For example in 

**Non Functional Requirement**
**Code quality:**
The program should have all related classes in a single group and have subscene categories.

**User Experience:**
Clear and detailed personalized text based interface 
Each detail in the interface should clearly show the action being done to inform the user.

**Testing:**
All activities or path(puzzles,combat,save/load) integrated to the game should be accurately checked and tested for any loop holes. 
All cases should be validated and each error must be adequately documented.

**Performance:**
Game must run smoothly and efficiently to create a seamless experience.
Low amount of memory should be used.

**Compatibility:**
The program must run on different operating systems.

**Documentation:**
Methods and classes should have comments for documentation.

Input Process Output Table

<style>
</style>

| Task                                              | Input                                          | Process                                                                                                                                                    | Output                                                                                                                              |
| ------------------------------------------------- | ---------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| Begin game                                        | Player selects "begin game" from menu          | Processes and load's player's health board, stats.                                                                                                         | First game scene and a welcome text.                                                                                                |
| Personalization of the game                       | Player’s gaming<br> name                       | Saves player’s<br> name to memory and allows personalization in user’s interface                                                                           | Integrated<br> personalized dialogue message.                                                                                       |
| Displays first game/story scene                   | Game state                                     | Checks memory for game description and choices                                                                                                             | Game text and binary options shown.                                                                                                 |
| Select a choice from binary option                | Player enters (1 or 2)                         | Check if player enters 1 or 2 and processes the next story scene                                                                                           | Choice is either 1 or 2, the next story scene is shown if not an error message                                                      |
| Error Validation                                  | Non numeric input                              | Processes error and reprompts prayer                                                                                                                       | Error message and previous prompt                                                                                                   |
| Puzzle(riddles,anagrams<br> or math based puzzle) | Puzzle answer                                  | Check if puzzle answer<br> is the same as stored program answer, update the score system and check for<br> the next route.                                 | Display a personalized<br> message if correct or wrong , updated core system and next route                                         |
| Combat                                            | Player’s combat<br> action                     | Enable battle influenecd by player's inventory and health,calculate damage, update health, score board and determine the winner and locate the next route. | Display a peronalized message  depending on whether successful or not, display score board and health stats and next step or route. |
| Item collection                                   | Player picks up  item(weapon,food or clothing) | Item is added to inventory                                                                                                                                 | Display a personalized message and an inventory with the item added inside.                                                         |
| View item inventory                               | Player selects view inventory                  | Checks memory for items in inventory                                                                                                                       | Displays items                                                                                                                      |
| Use item                                          | Player selects item                            | Review the item effects based on whether it's clothing,food or weapon and updates stats                                                                    | Updated player's stats                                                                                                              |
| Save game                                         | Player selects save                            | Save game in memory                                                                                                                                        | Dislay confirmation message                                                                                                         |
| Complete game                                     | Player's stats were enough to end game         | Calculate player's stats                                                                                                                                   | Victory personalized message and final score                                                                                        |
| Resume previous game                              | Player selects resume game                     | Retrieves game from memory                                                                                                                                 | Display game from last scene                                                                                                        |
| Exit game                                         | Player selects exit                            | Save and closes game program                                                                                                                               | Exit text displayed                                                                                                                 |

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20133740.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20133753.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20133802.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20133935.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20134046.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20134057.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20134108.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20134118.png)

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-07%20134126.png)

**Class Diagram **

![h](C:\Users\Motunrayo\OneDrive\Pictures\Screenshots\Screenshot%202026-02-17%20205447.png)
