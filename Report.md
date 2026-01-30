<style>
</style>

| Module Code            | IY453                           |
| ---------------------- | ------------------------------- |
| Group                  | A                               |
| Module Title           | Software Design and Implementation |
| Assessment<br> Type    | Coursework Stage 1              |
| Module Tutor<br> Name  | Mustafa<br> Ghashim             |
| Student ID<br> Number  | P493421                         |
| Date of<br> Submission | 29/1/26                         |

☒ *I confirm that this assignment is my own work. Where I have
referred to academic sources, I have provided in-text citations and included
the sources in the final reference list.*

 ☒ *Where I have used AI, I have
cited and referenced appropriately.*

**Introduction**
Stage 1 is the design and analysis phase which is  necessary for the preparation of the actual program outline .Every aspect of the program revolves around the analysis and design phase. It comprises  of three main branches which are the introduction,program purpose,input/output table and algorithm design.

The introduction is the basic overview what would be included in this branch. The sub categories under the program purpose include the functional and non-functional requirements. The input and output table is a table built mainly to show the program's task and the corresponding input and output for each task. Meanwhile, the algorithm is meant to display what the program is exactly meant to do by showing how data flows.

**Stage 1:Analysis And Design**

Program Specification
The software is designed to create a text based engaging adventurous game where the players:

**Functional Requirement**
**Player Interaction and Choices:**

The game should have at least 30 binary choices.                                                                Each choice leads to a particular scenario which could lead to game over or victory.                                                                                                              Each choice should have a small description of what the user is experiencing.              Provide clear feedback on the consequences of each choice.

**Inventory and Items Impact:**

An inventory design to collect,save and view weapons.                                                                

Each player can encounter various gears. For example: weapons for combat and food for health and clothing for restoration.

Each one of those should create an effect on the player's stats and health necessary to have an effect on the player's combat and unlocking new routes etc.



**Save and Resume Functionality:**

Each player should have their previous game saved to be resumed and saved for later times using text files.

Included in the text file or binary file should be player's name to aid personalization and story engagement.

Provide an intuitive interface to save load games.

**Story and Engagement**

Each story must have logical connections inbetween scenario from the 

Each players details stored during the save and resume functionality should help create a personalized experience which would be integrated into dialogues and messages.

**Game play scenario**                                                                                                                 The program should be a collection of various scenarios such as puzzles,combat based and item collection which should be seamlessly align into the game.

Puzzles:Could be maths based, anagrams or riddles designed to the intellectual mind.

Combat based:The players inventory aand stats need to influence any combat act.

Item collection: The players should be able to gather any items to aid his game progression.

**Score system:**
Each of those game play scenario e.g a combat scene or puzzle ecene should have an effect on their player's score system depending on success or defeat.

Display score board at different critical points e.g after a scenario encounter and the beginning and the end.

**Error handling:**
The text based system should make sure user's input is validated to prevent crashes and errors.

Error messages should be provided when the user's input doesn't correlate to the data structure of the answer.

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

| Task                                              | Input                      | Process                                                                                                                    | Output                                                                                      |
| ------------------------------------------------- | -------------------------- | -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| Begin game                                        | Menu choice                | Processes the<br> player’s choice                                                                                          | New game or exit<br> game or view previous games.                                           |
| Start a new game                                  | Player’s gaming<br> name   | Saves player’s<br> name to memory and allows personalization in user’s interface                                           | Integrated<br> personalized dialogue message.                                               |
| View previous game                                | Name of previous<br> game  | Checks memory for<br> previous game                                                                                        | Displays previous<br> game.                                                                 |
| Play game                                         | Binary choice              | Processes the<br> choice and locates the route.                                                                            | Displays the puzzle<br> based scenario, combat scenario or item collection scenario.        |
| Puzzle(riddles,anagrams<br> or math based puzzle) | Puzzle answer              | Check if puzzle answer<br> is the same as stored program answer, update the score system and check for<br> the next route. | Display a personalized<br> message if correct or wrong , updated core system and next route |
| Combat                                            | Player’s combat<br> action | Check player’s health<br> and stats                                                                                        |                                                                                             |
