# ENGG1340 Group Project
## Group Members (Group 135)
- CHOI Yoon Sun (UID: 3035683784)
- HUH Sung (UID: 3035660744)

## Game Description
*The story of the game is an original idea, but the battle style in this game is referenced from the Pokémon series.*

The game *Mysterious Yyetnal* is a role-playing game which is set in a fictional place called Yyetnal during the middle age.

After reading a paper the player found at home, the player goes on a journey to find the legendary sword. While on his/her journey, the player meets different monsters, bandits and gatekeepers to the sword. In order to advance, the player needs to battle them and win. If he wins the battle, he gains golds and unique parts which can be used to upgrade weapon and armour. Once the player reaches the place where the legendary sword is hidden, he has to defeat the final guardian, Karagon, who is protecting the sword in order to get it. The game ends once the player gets the legendary sword after defeating the final guardian.

Before the start of the game, the game will ask the player to name the character. There will be a total of 4 boss battles, including the final guardian. After every stage, the player will be able to go to a new town and therefore, the player can unlock three different towns, Tanook, Terra and Aran.  At the towns, the player can trade the unique parts they have earned from battles with townspeople for gold and the gold can be used to upgrade the player's weapon and armour and also buy health potions that could be used in battles. At the towns, the player's health will healed back to 100% automatically.

During each battle, the player can choose to basic attack or use special skill which deals 1.5 times of basic attack and is limited to 2 times per battle. Player and the enemy take turns to attack. The player could use health potions to refill their health when they are low on health. If player's health becomes zero, player dies and the game restarts from the last save point. If the enemy's health goes below 1, the player wins and earns unique parts and gold.

## Libraries used in the game
   - iostream
   - fstream is used for read and write of files (i.e., ifstream, ofstream)
   - stdlib.h is used for system("clear")
      - This function helps clear the screen
   - string for string data type
   - vector to use vector for dynamic memory management
      - This is used when player sells their unique parts for gold in tradeandupgrade() function.
   - cstdio to use remove() for removing files in UNIX environment
      - This is used after the player completes the game and will remove the savefile.txt so that the player can start the game again.
   - ctime to use time()
      - This is used as seed for random function.
   - cstdib to use rand() and srand()
      - This is used for the randomness of the attacks in battles.
   
## Sample inputs
   - Sample inputs have not been included. Even though the same data has been input, the result of the game will be different due to the randomness during battles. 
   - We have included checks for invalid data. So if the player enters invalid data, the game will ask the player to input again until the input is valid.
   - The input requirements are stated explicitly in the game.
      - (e.g. Type "continue to continue) Then the player is expected to type "continue".

## Compilation and execution
   - A Makefile is included in this porject.
   - These are the steps to compile and excute the program:
      1. Enter "make main"
      2. Enter "./main"
      
## List of Features/Functions
1. Generation of random game sets or events
   - In battles, the player will deal a fixed amount of damage to his/her enemy based on the weapon the player is using. However, sometimes the player may miss the attack, or instead do a critical damage to the enemy. This will be decided randomly by percentage which is basically set 15% each. The library cstdlib and ctime will be included to use the rand() and srand() funtions to randomly generate such situations.

2. Data structures for storing game status
   - The basic information of a player including name, maximum health, attack damage, gold, current location, and obtained items (inventory) are stored. For the basic information, these information are stored in the form of struct called PlayerInfo, where the name is in string, health, attack damage, and gold are in integer. The data of inventory will be sotred in integer type 1D array.
   
   - Information of the enemies has to be stored. Similar to the player information, the name, attack damage and health and the amount of gold the enemy is worth. These will also be stored in a form of struct called , where name is in string, attack damage, health and gold are in integer.
   
3. Dynamic memory management
   - When the player is at the town, the player can trade any amounts of item they want for gold. The total price depends on the type and the quantity of items that are being traded. The townspeople will ask the player how many items the player would like to trade. For example, if the players enters 3, a vector with the length of 3 will be created and the player has to input the three items he/she would like to trade. As the length of array depends on the amount of item the player wants to sell, vector needs to be used. Based on the vector, the townspeople will do the calculation and give the corresponding amount of gold to the player.
   
4. File input/output
   - Players can save the game and reload their save files to continue their game. If it is their first time saving their progress, the game save file will be saved in a new called savefile.txt file. If it is not their first time saving their progress, it will overwrite the original save file. By loading the savefile.txt file, players can reload their progress. If the player dies during the battle, the game will restart from its last save file. These could be done including the library fstream. 

5. Program codes in multiple files
   - The game program consists of .cpp and .h files. Functions used in main() function was written into separate header files. Finally, makefile was used in Linux to compile the files and make the game program executable. Five header files have been created, battleenemy.h which stores battleenemy() function (used in battle scenarios), structs.h which stores structs information, trade.h which stores tradeandupgrade() function (used in town market), askname.h which stores askingName() function (used in the beginning of the game to ask for name of the player), presskey.h which stores presskey() function (used for Press any keys to continue).
