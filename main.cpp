#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "structs.h"
#include "name.h"
#include "battleenemy.h"
#include "trade.h"
using namespace std;

int main()
{
    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine, answer;

    /* Main start menu */
    cout << "~~~~~~~~~~ MYSTERIOUS YYETNAL ~~~~~~~~~~" << endl;
    cout << "Developed by CHOI Yoon Sun and HUH Sung." << endl;
    cout << "Type \"start\" to start the game." << endl;
    cin >> inputLine;

    /* If the player inputs something other than "start", it will ask the player to input again until it is a valid input (i.e., start)*/
    while (inputLine != "start") {
        cout << "***Invalid input. Please type \"start\" to start the game.***" << endl;
        cin >> inputLine;
    }

    PlayerInfo pinfo;
    askingname();
    
    cout << endl << "*You wake up and you see a paper lying on the floor*" << endl << "Type \"read\" to read the paper" << endl;
    cin >> inputLine;
    
    cout << endl << "\"The sword is hidden somewhere in the mountains, near the town of Aran.\"" << endl;

    cout << endl << pinfo.pname << ": That's weird. I'm sure this wasn't here before I went to sleep." << endl;
    cout << pinfo.pname << ": But this journey sounds interesting." << endl;

    cout << endl << "*You take your sword and leave the house*" << endl;

    cout << "*Your journey to the town of Aran starts*" << endl;

    cout << endl << "* While on your way, you encounter the monster, Asaand it suddenly charges on you *" << endl;


    
    //set player's stat
    pinfo.maxHealth=100;
    pinfo.currentHealth=100;
    pinfo.basicAttack=20;
    pinfo.invenGold=0;
    pinfo.currentLoc=1;
    
    
    EnemyInfo firstboss;
    EnemyInfo secondboss;
    EnemyInfo tirdboss;
    EnemyInfo fourthboss;
    EnemyInfo finalboss;
    
    ItemInfo -----;
    
    SkillInfo ------;
        
    
    for (int k=0; k<4; k++){
        battleenemy(pinfo.currentLoc);
        trade(pinfo.currentLoc);
        pinfo.currentLoc+=1;
        
    if (pinto.currentLoc == 5){
        cout << Fight with final boss left << endl;
        battleenemy(pinfo.currentLoc);
        if (//player wins){
            cout << congratulations! you defeated evey bosses! << endl;
    
    }
    
    
    

    return 0;
}
