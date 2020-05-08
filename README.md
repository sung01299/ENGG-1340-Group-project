# ENGG1340 Group Project
## Group Members (Group 135)
- Yoon Sun CHOI (UID: 3035683784)
- Sung HUH (UID: 3035660744)

## Game Description
*The story of the game is an original idea, but the battle style in this game is referenced from the Pokémon series.*

The game *Mysterious Yyetnal* is a role-playing game which is set in a fictional place called Yyetnal during the middle age.

After reading an old book the player found at home, the player goes on a journey to the legendary sword. While on his/her journey, the player meets different monsters, bandits and gatekeepers to the treasure. In order to advance, the player needs to battle them and win. If he wins the battle, he gains hints to the place where the sword is hidden and also gains gold and unique parts. Once the player reaches the place where the legendary sword is hidden, he has to defeat the final guardian who is protecting the sword in order to get the legendary sword. The game ends once the player gets the legendary sword after defeating the final guardian.

Before the start of the game, the game will ask the player to name the character. There will be a total of 6 boss battles, including the final guardian. After every stage, the player will be able to go to a new town and therefore, the player can unlock five different towns. At the towns, the player can trade the unique parts they have earned from battles with townspeople for gold and gold can be used to upgrade the player's weapon and armor.

During each battle, the player can choose an attack among few options (e.g. use first skill, use second skill, etc.) Player and the enemy take turns to attack. If player's health becomes zero, player dies and the game restarts from the last save point.  

## List of Features/Functions
1. Generation of random game sets or events
   - In battles, the player will deal a fixed amount of damage to his/her enemy based on the weapon the player is using. However, sometimes the player may miss the attack, or instead do a critical damage to the enemy. This will be decided randomly. After winning the battle, the items that the player will get from the enemy will also be random. The library stdlib.h will be included to use the rand() and srand() funtions to randomly generate such situations.

2. Data structures for storing game status
   - The basic information of a player including name, health, attack and defence stats, gold, current location, obtained items (inventory) and obtained skills needs to be stored. For the basic information, these information would be stored in the form of struct, where the name is in string, attack and defence stats, gold are in integer. The data of inventory and obtained skills will be sotred in integer type 2D array.
   
   - Information of the enemies has to be stored. Similar to the player information, the name, attack stats and health and the amount of gold the enemy is worth. These will also be stored in a form of struc, where name is in string, attack stats, health and gold are in integer.
   
   - A struct for item information will be created. In the struc, the ID of the item, its name and price will be stored. The ID and price will be in integer, while the name of the item will be in string.
   
   - The skill information will be stored in struc. In the struc, the ID of the skill, skill name, basic damage amount and maximum times the skill can be used will be stored. ID, damage, maximum usage will be stored as integer and skill name will be stored as string.
   
3. Dynamic memory management
   - When the player is at the town, the player can trade any amounts of item they want for gold. The total price depends on the type and the quantity of items that are being traded. The townspeople will ask the player how many items the player would like to trade. For example, if the players enters 3, a vector with the length of 3 will be created and the player has to input the three items he/she would like to trade. As the length of array depends on the amount of item the player wants to sell, vector needs to be used. Based on the vector, the townspeople will do the calculation and give the corresponding amount of gold to the player.
   
4. File input/output
   - Players can save the game and reload their save files to continue their game. If it is their first time saving their progress, the game save file will be saved in a new .txt file. If it is not their first time saving their progress, it will overwrite the original save file. By loading these saved .txt files, players can reload their progress. If the player dies during the battle, the game will restart from its last save file. These could be done including the library fstream. 

5. Program codes in multiple files
   - The game program will consist of .cpp and .h files. Functions used in main() function will be written into separate files. Finally, makefile will be used in Linux to compile the files and make the game program executable.
