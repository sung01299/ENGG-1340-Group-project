#ifndef BATTLEENEMY_H
#define BATTLEENEMY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structs.h"
#include "presskey.h"
using namespace std;

bool battleenemy(int x, int &maxHealth, int basicAttack, int &invenGold, int inven[]){
    int currentHealth = maxHealth;
    EnemyInfo firstboss;
    EnemyInfo secondboss;
    EnemyInfo thirdboss;
    EnemyInfo finalboss;

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
    if (x == 1){
        ename = firstboss.ename;
        ehealth = firstboss.ehealth;
        eattack = firstboss.eattack;
        egold = firstboss.egold;
    }
    else if (x == 3){
        ename = secondboss.ename;
        ehealth = secondboss.ehealth;
        eattack = secondboss.eattack;
        egold = secondboss.egold;
    }
    else if (x == 5){
        ename = thirdboss.ename;
        ehealth = thirdboss.ehealth;
        eattack = thirdboss.eattack;
        egold = thirdboss.egold;
    }
    else if (x == 7){
        ename = finalboss.ename;
        ehealth = finalboss.ehealth;
        eattack = finalboss.eattack;
        egold = finalboss.egold;
    }

    srand(time(NULL));
    int answer, missrate, critrate, maxskilluse;
    string retur;
    missrate = 15;
    critrate = 15;
    maxskilluse = 2;
    
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
    cout << endl;

    while (maxHealth > 0 && ehealth > 0){
        cout << "To use basic attack, please type \"0\", to use special skill, please type \"1\", please type \"2\" to use health potion." << endl;
        cin >> answer;
        cout << endl;
        while (answer != 0 && answer != 1 && answer != 2){
            cout << "*** Invalid input. Please type \"0\" to do basic attack, \"1\" to use special skill, or \"2\" to use health potion. ***" << endl;
            cin >> answer;
            cout << endl;
        }
        if (answer == 0){
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
            cout << ename << " attacked you" << endl << endl;
            currentHealth -= eattack;
            cout << "Your health remaining: " << currentHealth << endl;
            cout << "Your special skill remaining: " << maxskilluse << endl;
            cout << endl;
        }
        else if (answer == 1){ 
        	if (maxskilluse >= 1){
            	cout << "You used special skill to " << ename << "!" << endl;
            	ehealth -= 3*basicAttack;
            	cout << ename << " health remaining: " << ehealth << endl << endl;
            	cout << ename << " attacked you!" << endl;
            	currentHealth -= eattack;
              	maxskilluse-=1;
            	cout << "Your health remaining: " << currentHealth << endl;
            	cout << "Your special skill remaining: " << maxskilluse << endl;
            	cout << endl;
            }
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
            	cout << endl;
			}    
        }
        else if (answer == 2) {
            if (currentHealth == maxHealth) {
                cout << "Your health is already full!" << endl << endl;
            }
            else {
                int count = 0;
                for (int i = 0; i < 5; i++) {
                    if (inven[i] != 0) {
                        count += 1;
                    }
                }
                if (count >= 1) {
                    currentHealth += 100;
                    if (currentHealth > maxHealth) {
                        cout << "You use potion, health increased by " << maxHealth - (currentHealth - 100) << "." << endl;
                        currentHealth = maxHealth;
                    }
                    else {
                        cout << "You used potion, health increased by 100." << endl;
                    }
                    cout << "Your current heath is: " << currentHealth << endl;
                    cout << "Potions remaining: " << count - 1 << endl << endl;
                    for (int i = 0; i < 5; i++) {
                        if (inven[i] != 0) {
                            inven[i] = 0;
                            break;
                        }
                    }
                }
                else {
                    cout << "You have no more potions left." << endl;
                }
            }
        }
        
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
        else if (ehealth <=0){
            cout << "You have defeated " << ename << "!" << endl;
            cout << ename << " dropped its unique part." << endl;
            cout << ename << " dropped some golds." << endl;
            invenGold += egold;
            string part;
            part="Part from "+ename;
            inventory.push_back(part);
            cout << "You now have " << invenGold << " golds." << endl;
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
