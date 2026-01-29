<style>
</style>

| Module Code            | IY453                              |
| ---------------------- | ---------------------------------- |
| Group                  | A/B                                |
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
Stage 1 is the design and analysis necessary for the preparation of the actual program design. It includes three main stages which are the introduction,program purpose,input/output table and algorithm.The introduction is the basic overview what would be included .The sub categories under the program purpose include the functional and non-functional requirements,input and output table to show the user's task and the corresponding input and output for each task.Meanwhile, the algorithm is meant to display what the program is exactly meant to do by showing how data flows.

**Stage 1:Analysis And Design**

Program Specification
The software is designed to create a text based engaging adventurous game where the players:

**Functional Requirement**
**Player Interaction and Choices:**

The game should have at last 30 binary choices.                                                                Each choice leads to a particular scenario.                                                                        Provide clear feedback on the consequences of each choice

**Inventory Impact:**

Each player can encounter gears for weapon for combat and food and clothing for restoration.

**Save and Resume Functionality:**

Each player has their game saved to be resumed and saved for later times using text files.

**Game play scenario**                                                                                                                 The program should be a collection of various scenarios such as puzzles,combat based and item collection.

**Score system:**
Each of those game play scenario should have an effect on their player's score system depending on success or defeat.

**Error handling:**
The text based system should make sure user's input is validated to prevent crashes and errors.

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
