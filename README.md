# ENGG 1340 Group project
## Team Members (Group 135)
- Yoon Sun CHOI (UID: 3035683784)
- Sung HUH (UID: 3035660744)

## Game Description
*The story of the game is an original idea, but the battle style in this game is referenced from the Pokémon series.*

The game Mysterious Yyetnal is a role-playing game which is set in a fictional place called Yyetnal during the middle age.

After reading an old book the player found at home, the player goes on a journey to the legendary sword. While on his journey, he meets different monsters, bandits and gatekeepers to the treasure. In order to advance, the player needs to battle them and win. If he wins the battle, he gains hints to the place where the sword is hidden and also gains gold and unique parts. Once the player reaches the place where the legendary sword is hidden, he has to defeat the final guardian who is protecting the sword in order to get the legendary sword. The game ends once the player defeats the guardian and gets the legendary sword.

Before the start of the game, the game will ask the player to name the character. There will be a total of 6 boss battles, including the final guardian. After every stage, the player will be able to go to a new town, so therefore, the player can unlock five different towns. At the towns, players can trade with the town people the unique parts they have earned from battles to gold and gold can be used to upgrade his weapon and armor.

During each battle with monsters, the player can choose an action among few options (e.g. use first skill, use second skill, etc.) Player and monster take turn alternatively to attack. If player kills monsters, monsters may drop golds and items which can be used to purchase or exchange from the town. Or if player's health becomes below zero, player dies and game ends.  

## List of Features/Functions
1. Generation of random game sets or events
   - In battles, the player will deal a fixed amount of damage to his/her enemy based on the weapon the player is using. However, sometimes the player may miss the attack, or instead do a critical damage to the enemy. This will be decided randomly and the libraries <stdlib.h> will be included to use the rand() and srand() funtions to randomly generate such situations.

2. Data structures for storing game status
   - The basic information of a player including name, health, attack and defence stats, gold, current location and obtained items (inventory) needs to be stored. For the basic information, these information would be stored in the form of struct, where the name is in string, attack and defence stats, gold are in integer. The data of inventory will be sotred in 2D array.
   
   - Information of the enemies has to be stored. Similar to the player information, the name, attack stats and health and the amount of gold the enemy is worth. These will also be stored in a form of struc, where name is in string, attack stats, health and gold are in integer.

3. Dynamic memory management

4. File input/output
   - Players can save the game and reload their save files to continue their game. If it is their first time saving their progress, the game save file will be saved in a new .txt file. If it is not their first time saving their progress, it will overwrite the original save file. By loading these saved .txt files, players can reaload their progress. These could be done including the library fstream. 

5. Program codes in multiple files
   - The game program will consist of .cpp and .h files. Functions used in main() function will be written into separate files. Finally, we will use makefile in Linux to compile files and make programe executable.
