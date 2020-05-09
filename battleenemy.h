// This header file includes the function battleenemy()
// which is used in battle situations

#ifndef BATTLEENEMY_H
#define BATTLEENEMY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structs.h"
#include "presskey.h"
using namespace std;

// The function will return a boolean value
// If the player dies in the battle, the fucntion will return false
// Otherwise, if the player wins the battle, the function will return true
// The inputs are the current location of the player, pkayer's health, basic attack,
// the amount of gold player has and the the inventory array of the player.
bool battleenemy(int x, int maxHealth, int basicAttack, int &invenGold, int inven[]){
    int currentHealth = maxHealth;

    // This contains infomration for first enemy Asa
    EnemyInfo firstboss;
    // This contains information for second enemy Patel
    EnemyInfo secondboss;
    // This contains information for third enemy Majav
    EnemyInfo thirdboss;
    // This contains information for final enemy Karagon
    EnemyInfo finalboss;
    
    // The corresponding values are assigned to the enemies
	firstboss.ename = "Asa";
    firstboss.ehealth = 300;
    firstboss.eattack = 15;
    firstboss.egold = 300;
    
    secondboss.ename = "Patel";
    secondboss.ehealth = 450;
    secondboss.eattack = 30;
    secondboss.egold = 600;
    
    thirdboss.ename = "Majav";
    thirdboss.ehealth = 600;
    thirdboss.eattack = 50;
    thirdboss.egold = 900;
   
    finalboss.ename = "Karagon";
    finalboss.ehealth = 1000;
    finalboss.eattack = 80;
    finalboss.egold = 0;
    
    int ehealth, eattack, egold;
    string ename;
    // If currentLoc is 1, the enemy is Asa, so values of Asa will be stored
    if (x == 1){
        ename = firstboss.ename;
        ehealth = firstboss.ehealth;
        eattack = firstboss.eattack;
        egold = firstboss.egold;
    }
    // If currentLoc is 3, the enemy is Patel, so values of Asa will be stored
    else if (x == 3){
        ename = secondboss.ename;
        ehealth = secondboss.ehealth;
        eattack = secondboss.eattack;
        egold = secondboss.egold;
    }
    // If currentLoc is 5, the enemy is Majav, so values of Majav will be stored
    else if (x == 5){
        ename = thirdboss.ename;
        ehealth = thirdboss.ehealth;
        eattack = thirdboss.eattack;
        egold = thirdboss.egold;
    }
    // If currentLoc is 6, the enemy is Karagon, so values of Karagon will be stored
    else if (x == 7){
        ename = finalboss.ename;
        ehealth = finalboss.ehealth;
        eattack = finalboss.eattack;
        egold = finalboss.egold;
    }

    // time(NULL) is used for the seed for random
    // so that the value of random could be different everytime
    srand(time(NULL));
    int missrate, critrate, maxskilluse;
    string retur, answer;
    missrate = 15;
    critrate = 15;
    maxskilluse = 2;
    
    // This will be output in the beginnning of the battles
    // Information of the enemy and the player will shown
    cout << "Enemy Information: " << endl;
    cout << "Name: " << ename << endl;
    cout << "Health: " << ehealth << endl;
    cout << "Attack damage: " << eattack << endl;
    cout << endl;
    
    cout << "Player Information: " << endl;
    cout << "Health: " << maxHealth << endl;
    cout << "Attack damage: " << basicAttack << endl;
    cout << "Skill damage: " << 1.5*basicAttack << endl;
    cout << "Special skill available: " << maxskilluse << endl;
    // The for-loop calculates the number of potions the player has
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (inven[i] != 0) {
            count += 1;
        }
    }
    cout << "Number of potions you have: " << count << endl;
    cout << endl;
    
    // The while loop will continue until either the player's health or enemy's health goes equal or below zero
    while (maxHealth > 0 && ehealth > 0){
        cout << "To use basic attack, please type \"0\", to use special skill, please type \"1\", please type \"2\" to use health potion." << endl;
        cin >> answer;
        cout << endl;

        // Check whether the input is valid
        while (answer != "0" && answer != "1" && answer != "2"){
            cout << "*** Invalid input. Please type \"0\" to do basic attack, \"1\" to use special skill, or \"2\" to use health potion. ***" << endl;
            cin >> answer;
            cout << endl;
        }
        
        // If the player decides to deal basic attack
        // With using rand(),
        // The player may miss the attack (i.e., dealing 0 damage to the enemy),
        // do a critical damage (i.e., do more damage than the basic attack),
        // or just deal basic attack damage.
        if (answer == "0"){
            if (rand()%100 <= missrate) {
                cout << "You missed your basic attack!" << endl;
            }
            else {
                if (rand()%100<=critrate){
                    cout << "You dealt a critical hit!" << endl;
                    ehealth -= (2*basicAttack);
                }
                else {
                    cout << "You basic attacked " << ename << endl;
                    ehealth -= basicAttack;
                }
            }
            cout << ename << " health remaining: " << ehealth << endl;
            if (ehealth > 0) {
                cout << ename << " attacked you" << endl << endl;
                currentHealth -= eattack;
                cout << "Your health remaining: " << currentHealth << endl;
                cout << "Your special skill remaining: " << maxskilluse << endl;
                count = 0;
                for (int i = 0; i < 5; i++) {
                    if (inven[i] != 0) {
                        count += 1;
                    }
                }
                cout << "Number of potions you have: " << count << endl;
                cout << endl;
            }
        }

        // If the player decides to use special skill
        else if (answer == "1"){
            // The number of times the player can use the special skill is limited to two
            // If the value of maxskilluse is larger than one,
            // player will be allowed to use it.
            // Otherwise, it will tell the player that the special skill cannot be used
            // and instead do basic attack
        	if (maxskilluse >= 1){
            	cout << "You used special skill to " << ename << "!" << endl;
            	ehealth -= 3*basicAttack;
            	cout << ename << " health remaining: " << ehealth << endl << endl;
                if (ehealth > 0) {
                    cout << ename << " attacked you" << endl << endl;
                    currentHealth -= eattack;
                    maxskilluse -= 1;
                    cout << "Your health remaining: " << currentHealth << endl;
                    cout << "Your special skill remaining: " << maxskilluse << endl;
                    count = 0;
                    for (int i = 0; i < 5; i++) {
                        if (inven[i] != 0) {
                            count += 1;
                        }
                    }
                    cout << "Number of potions you have: " << count << endl;
                    cout << endl;
                }
            }

            // If maxskilluse is less than zero
            // Doing basic attack only
            else {
            	cout << "No more energy to use your special skill! You can only basic attack now." << endl;
            	if (rand()%100<=missrate){
                cout << "You missed your basic attack!" << endl;
            	}
            	else {
                	if (rand()%100<=critrate){
                    	cout << "You dealt critical hit!" << endl;
                    	ehealth -= (2*basicAttack);
                	}
                	else {
                    	cout << "You basic attacked " << ename << endl;
                    	ehealth -= basicAttack;
                	}
            	}
                if (ehealth > 0) {
                    cout << ename << " health remaining: " << ehealth << endl;
                }
                else {
                    cout << ename << " health remaining: 0" << ehealth << endl << endl;
                }
            	cout << ename << " attacked you" << endl;
            	currentHealth -= eattack;
            	cout << "Your health remaining: " << currentHealth << endl;
            	cout << "Your skill remaining: " << maxskilluse << endl;
                count = 0;
                for (int i = 0; i < 5; i++) {
                    if (inven[i] != 0) {
                        count += 1;
                    }
                }
                cout << "Number of potions you have: " << count << endl;
            	cout << endl;
			}    
        }

        // If the player decides to use health potions instead
        else if (answer == "2") {
            // If the player has max health, the player cannot use health potions
            if (currentHealth == maxHealth) {
                cout << "Your health is already full!" << endl << endl;
            }
            else {
                count = 0;
                // The for-loop calculates the number of potions the player has
                for (int i = 0; i < 5; i++) {
                    if (inven[i] != 0) {
                        count += 1;
                    }
                }
                if (count >= 1) {
                    currentHealth += 100;
                    // Although the health potion can refill 100 health,
                    // It cannot refill over the maximum health
                    // If the player has difference of less than 100 health,
                    // the health potion will only refill the diference
                    if (currentHealth > maxHealth) {
                        cout << "You use potion, health increased by " << maxHealth - (currentHealth - 100) << "." << endl;
                        currentHealth = maxHealth;
                    }
                    else {
                        cout << "You used potion, health increased by 100." << endl;
                    }
                    cout << "Your current heath is: " << currentHealth << endl;
                    cout << "Potions remaining: " << count - 1 << endl << endl;
                    // This updates the inventory of the player
                    for (int i = 0; i < 5; i++) {
                        if (inven[i] != 0) {
                            inven[i] = 0;
                            break;
                        }
                    }
                }
                else {
                    cout << "You have no potions." << endl;
                }
            }
        }
        
        // If the player's health becomes zero or less than zero,
        // It will ouput that the player is dead,
        // and the game will tell the player to return to last save point.
        // The function will return false.
        if (currentHealth <= 0){
            cout << "You have died." << endl;
            cout << endl;
            cout << "To return to last save point, please type \"return\"." << endl;
            cin >> retur;
            system("clear");
            while (retur != "return"){
                cout << "*** Invalid input. Please type \"return\" to select ***" << endl;
                cin >> retur;
                system("clear");
            }
            if (retur == "return")
            	return false;
        }
        
        // If the enemy's health becomes zero or less than zero,
        // It will output that the player has won.
        // It will also update the values of invenGold and the vector for the parts obtained.
        // Then it will ask the player to proceed to the next part.
        // The function will return true.
        else if (ehealth <=0){
            cout << ename << " health remaining: 0" << endl << endl;
            cout << "You have defeated " << ename << "!" << endl;
            cout << ename << " dropped its unique part." << endl;
            cout << ename << " dropped some golds." << endl;
            invenGold += egold;
            string part;
            part="Part from "+ename;
            inventory.push_back(part);
            cout << endl << "You now have " << invenGold << " golds." << endl;
            if (x != 4){
				cout << "You continue your journey and you enter a town." << endl;
                presskey();
                system("clear");
			}
            return true;
        }
    }
}

#endif
