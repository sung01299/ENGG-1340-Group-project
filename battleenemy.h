#ifndef BATTLEENEMY_H
#define BATTLEENEMY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool battleenemy(int x, int &maxHealth, int basicAttack, int &invenGold) {
	pinfo.currentHealth = pinfo.maxHealth;
	firstboss.ename="Asq";
    firstboss.ehealth=300;
    firstboss.eattack=15;
    firstboss.egold=300;
    
    secondboss.ename="Patel";
    secondboss.ehealth=450;
    secondboss.eattack=30;
    secondboss.egold=600;
    
    thirdboss.ename="Majav";
    thirdboss.ehealth=600;
    thirdboss.eattack=50;
    thirdboss.egold=900;
   
    finalboss.ename="Karagon";
    finalboss.ehealth=1000;
    finalboss.eattack=80;
    finalboss.egold=0;
    
  	int ehealth, eattack, egold;
  	string ename;
    if (x == 1){
        ename = firstboss.ename;
        ehealth = firstboss.ehealth;
        eattack = firstboss.eattack;
        egold = firstboss.egold;
    }
    else if (x == 2){
        ename = secondboss.ename;
        ehealth = secondboss.ehealth;
        eattack = secondboss.eattack;
        egold = secondboss.egold;
    }
    else if (x == 3){
        ename = thirdboss.ename;
        ehealth = thirdboss.ehealth;
        eattack = thirdboss.eattack;
        egold = thirdboss.egold;
    }
    else if (x == 4){
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
	if (pinfo.currentLoc == 1){
		maxskilluse=0;
	}
	else{
		maxskilluse=2;
	}
	
    cout << "Enemy Information: " << endl;
    cout << "Name: " << ename << endl;
    cout << "Health: " << ehealth << endl;
    cout << "Attack damage: " << eattack << endl;
    cout << endl;
    
    cout << "Player Information: " << endl;
    cout << "Health: " << pinfo.maxHealth << endl;
    cout << "Attack damage: " << pinfo.basicAttack << endl;
    cout << "Skill damage: " << 1.5*pinfo.basicAttack << endl;
    cout << endl;
    while (pinfo.currentHealth > 0 && ehealth > 0){
        cout << "To use basic attack, please type \"0\", to use skill, please type \"1\"." << endl;
        cin >> answer;
        cout << endl;
        while (answer != 0 && answer != 1){
            cout << "***Invalid input. Please type \"0\" or \"1\" to select.***" << endl;
            cin >> answer;
            cout << endl;
        }
        if (answer == 0){
            if (rand()%100<=missrate){
                cout << "Player misses basic attack!" << endl;
            }
            else {
                if (rand()%100<=critrate){
                    cout << "Player deals critical hit!" << endl;
                    ehealth -= (2*pinfo.basicAttack);
                }
                else {
                    cout << "Player basic attacks enemy" << endl;
                    ehealth -= pinfo.basicAttack;
                }
            }
            cout << "Enemy health remaining: " << ehealth << endl;
            cout << "Enemy attacks player" << endl;
            pinfo.currentHealth -= eattack;
            cout << "Player health remaining: " << pinfo.currentHealth << endl;
            cout << "Player skill remaining: " << maxskilluse << endl;
            cout << endl;
        }
        else if (answer == 1){
			if (pinfo.currentLoc == 1){
				cout << "You have not acquired skill yet! You can only basic attack." << endl;
				if (rand()%100<=missrate){
                cout << "Player misses basic attack!" << endl;
            	}
            	else {
                	if (rand()%100<=critrate){
                    	cout << "Player deals critical hit!" << endl;
                    	ehealth -= (2*pinfo.basicAttack);
                	}
                	else {
                    	cout << "Player basic attacks enemy" << endl;
                    	ehealth -= pinfo.basicAttack;
                	}
            	}
			}
			else {
        		if (maxskilluse >= 1){
            		cout << "Player uses skill to enemy" << endl;
            		ehealth -= 3*pinfo.basicAttack;
            		cout << "Enemy health remaining: " << ehealth << endl;
            		cout << "Enemy attacks player" << endl;
            		pinfo.currentHealth -= eattack;
              		maxskilluse-=1;
            		cout << "Player health remaining: " << pinfo.currentHealth << endl;
            		cout << "Player skill remaining: " << maxskilluse << endl;
            		cout << endl;
            	}
            	else {
            		cout << "No more energy to use skill! You can only basic attack." << endl;
            		if (rand()%100<=missrate){
                		cout << "Player misses basic attack!" << endl;
            		}
            		else {
                		if (rand()%100<=critrate){
                    		cout << "Player deals critical hit!" << endl;
                    		ehealth -= (2*pinfo.basicAttack);
                		}
                		else {
                    		cout << "Player basic attacks enemy" << endl;
                    		ehealth -= pinfo.basicAttack;
                		}
            		}
				}
			}
            	cout << "Enemy health remaining: " << ehealth << endl;
            	cout << "Enemy attacks player" << endl;
            	pinfo.currentHealth -= eattack;
            	cout << "Player health remaining: " << pinfo.currentHealth << endl;
            	cout << "Player skill remaining: " << maxskilluse << endl;
            	cout << endl;
				}    
        	}
        
        if (pinfo.currentHealth <= 0){
            cout << "Player died." << endl;
            cout << endl;
            cout << "To return to main menu, please type \"return\"." << endl;
            cin >> retur;
            while (retur != "return"){
                cout << "***Invalid input. Please type \"return\" to select.***" << endl;
                cin >> retur;
            }
            if (retur == "return")
            	return false;
           
        }
        else if (ehealth <=0){
            cout << "Player defeated enemy!" << endl;
            cout << "Enemy dropped its unique part." << endl;
            cout << "Enemy dropped some golds." << endl;
            pinfo.invenGold+=egold;
            string part;
            part="Part from "+ename;
            inventory.push_back(part);
            cout << "Player currently have " << pinfo.invenGold << " golds." << endl;
            if (x != 4){
				cout << "Player can now move on to next town." << endl;
			}
			cout << endl;
            return true;
        }
    }
}

#endif
