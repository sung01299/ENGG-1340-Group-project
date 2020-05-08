#include <iostream>
#include "trade.h"
using namespace std;

void tradeandupgrade(){
    int answer0, answer1, answer2, answer3, number;
    vector<string> names;
    cout << "Player can trade the unique parts or upgrade weapon and armor." << endl;
    cout << "To trade the unique parts with gold, type \"1\", to upgrade weapon, type \"2\", to upgrade armor, type \"3\", to exit, type \"0\"" << endl;
    cin >> answer0;
    cout << endl;
    while (answer0 != 0){
        if (answer0 == 1){
            cout << "To view your inventory, type \"1\", to exit, type \"0\"" << endl;
            cin >> answer1;
            cout << endl;
            if (answer1 == 1){
            	if (inventory.size() >= 1){
            		for (int i=0; i<inventory.size(); i++){
            			cout << i+1 << ". " << inventory[i] << endl;
            		}
            		cout << "List the number of item that you would like to sell." << endl;
            		cin >> number;
            		cout << "Player successfully traded " << inventory[number-1] << " with 200 golds." << endl;
            		pinfo.invenGold += 200;
            		inventory.erase(inventory.begin());
            		cout << "You currently have " << pinfo.invenGold << " Golds." << endl;
            		cout << endl;
				}
				else{
					cout << "Nothing to sell in your inventory" << endl;
					cout << endl;
				}
			}

            cout << "To trade the unique parts with gold, type \"1\", to upgrade weapon, type \"2\", to upgrade armor, type \"3\", to exit, type \"0\"" << endl;
            cin >> answer0;
            cout << endl;
        }
        else if (answer0 == 2){
            cout << "Player can upgrade weapon with " << 30*pinfo.currentLoc << " by spending " << 150*pinfo.currentLoc << ". To upgrade, type \"1\"." << endl;
            cin >> answer2;
            cout << endl;
            if (answer2==1){
            	if (pinfo.invenGold >= 150*pinfo.currentLoc){
                	pinfo.basicAttack += 20*pinfo.currentLoc;
                	pinfo.invenGold -= 150*pinfo.currentLoc;
                	cout << "Player's attack damage increased to " << pinfo.basicAttack << endl;
                	cout << "Player currently has " << pinfo.invenGold << " gold." << endl;
                	cout << endl;
            	}
            	else {
            		cout << "Player has not enough balance" << endl;
            		cout << endl;
				}
			}
            cout << "To trade the unique parts with gold, type \"1\", to upgrade weapon, type \"2\", to upgrade armor, type \"3\", to exit, type \"0\"" << endl;
            cin >> answer0;
            cout << endl;
        }
        else if (answer0 == 3){
            cout << "Player can upgrade armor with " << 30*pinfo.currentLoc << " by spending " << 100*pinfo.currentLoc << ". To upgrade, type \"1\"." << endl;
            cin >> answer3;
            cout << endl;
            if (answer3==1){
            	if (pinfo.invenGold >= 150*pinfo.currentLoc){
                	pinfo.maxHealth += 30*pinfo.currentLoc;
                	pinfo.invenGold -= 150*pinfo.currentLoc;
                	cout << "Player's health increased to " << pinfo.maxHealth << endl;
                	cout << "Player currently has " << pinfo.invenGold << " gold." << endl;
                	cout << endl;
            	}
            	else {
            		cout << "Player has not enough balance" << endl;
            		cout << endl;
				}
			}
            cout << "To trade the unique parts with gold, type \"1\", to upgrade weapon, type \"2\", to upgrade armor, type \"3\", to exit, type \"0\"" << endl;
            cin >> answer0;
            cout << endl;
        }
    }
    cout << "Player exits trademarket." << endl;
    cout << endl;
