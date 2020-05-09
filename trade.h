// This header file includes the tradeandupgrade() function

#ifndef TRADE_H
#define TRADE_H

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <vector>
#include "presskey.h"
using namespace std;

// This function returns void as it only prints the options availbale in town.
// No input is needeed.
void action() {
    cout << "You can trade the unique parts for gold, upgrade weapon and armour or buy health potions" << endl;
    cout << "To trade the unique parts for gold, type \"1\"." << endl;
    cout << "To upgrade weapon, type \"2\"." << endl;
    cout << "To upgrade armor, type \"3\"." << endl;
    cout << "To buy health potions, type \"4\"." << endl;
    cout << "To exit, type \"0\"." << endl;
}

// The function return void.
// This function is used for all the actions done in town,
// i.e., trade items, upgrade weapon and armour, buy potions.
// The input parameters are current locaation of the player, the amount of gold player has, maximum health of player,
// basic attack of player and the inverntory array of player.
void tradeandupgrade(int currentLoc, int &invenGold, int &basicAttack, int &maxHealth, int inven[]) {
    string answer;
    currentLoc = currentLoc / 2;
    int number, num;
    vector<string> names;
    // Prints out the options available
    action();
    cin >> answer;
    system("clear");

    // Check whether the input is valid
    while (answer != "0" && answer != "1" && answer != "2" && answer != "3" && answer != "4") {
        cout << "*** Invalid input! ***" << endl;
        action();
        cin >> answer;
        system("clear");
    }

    while (answer != "0") {
        // If the player enters "1",
        // it will trade items for gold.
        if (answer == "1") {
            cout << "To view your inventory, type \"1\", to exit, type \"0\"" << endl;
            cin >> answer;
            system("clear");

            // Check whether input is valid.
            while (answer != "1" && answer != "0") {
                cout << "*** Invalid input. Please type \"1\" to view inventory otherwise type \"0\" to exit ***" << endl;
                cin >> answer;
                system("clear");
            }
            
            // It shows the inventory content (different from inven[])
            if (answer == "1") {
                if (inventory.size() >= 1) {
                    for (int i = 0; i < inventory.size(); i++) {
                        cout << i + 1 << ". " << inventory[i] << endl;
                    }
                    // Then it will ask the player how many items they would like to sell.
                    cout << "How many items would you like to sell?" << endl;
                    cin >> num;
                    system("clear");

                    if (num >= 1) {
                        // Base on the num,
                        // It will ask the player to input the number of the item for num times
                        // i.e., selling it one by one
                        for (int i = 0; i < num; i++) {
                            cout << "List the number of item that you would like to sell." << endl;
                            cin >> number;
                            system("clear");

                            cout << "You successfully traded " << inventory[number - 1] << " for 200 golds." << endl;
                            invenGold += 200;
                            inventory.erase(inventory.begin() + i + 1);
                            cout << "You now have " << invenGold << " golds." << endl;
                            presskey();
                            system("clear");
                        }
                    }
                }
                // If the player enters a number less than 1,
                // it will assume the player does not want to sell.
                else {
                    cout << "Nothing to sell in your inventory" << endl;
                    presskey();
                    system("clear");
                }
            }
        }

        // If the player enters "2",
        // it will upgrade player's attack damage with gold
        else if (answer == "2") {
            cout << "You can upgrade your weapon with " << 30 * currentLoc + basicAttack << " by spending " << 150 * currentLoc << " golds." << endl;
            cout << "Your current attack damage is " << basicAttack << "." << endl;
            cout << "You currently have " << invenGold << " golds." << endl;
            cout << "To upgrade, type \"1\", otherwise type \"0\" to exit." << endl;
            cin >> answer;
            system("clear");

            // If the player enters "1",
            // the player will upgrade their attack damage
            if (answer == "1") {
                // If the player has enough gold,
                // the player can upgrade the attack damage.
                if (invenGold >= 150 * currentLoc) {
                    // basicAttack is updated
                    basicAttack += 30 * currentLoc;
                    // corresponding amount of gold is deducted fromm invenGold
                    invenGold -= 150 * currentLoc;
                    cout << "Your attack damage increased to " << basicAttack << endl;
                    cout << "You now have " << invenGold << " golds." << endl;
                }
                // If the player does not have enough gold,
                // the player cannot upgrade their attack damage and
                // outputs they do not have enough gold.
                else {
                    cout << "You do not have enough gold!" << endl;
                }
                presskey();
                system("clear");
            }
        }

        // If the player enters "3",
        // it will upgrade player's health with gold
        else if (answer == "3") {
            cout << "You can upgrade armor to " << 30 * currentLoc + maxHealth << " by spending " << 100 * currentLoc << "." << endl;
            cout << "Your current defense is " << maxHealth << "." << endl;
            cout << "You currently have " << invenGold << " golds." << endl;
            cout << "To upgrade, type \"1\", otherwise type \"0\" to exit." << endl;
            cin >> answer;
            system("clear");

            // If the player enters "1",
            // the player will upgrade their health.
            if (answer == "1") {
                // If the player has enough gold,
                // the player can upgrade thir health
                if (invenGold >= 150 * currentLoc) {
                    // health is updated
                    maxHealth += 30 * currentLoc;
                    // the corressponding gold will be deducted from invenGold
                    invenGold -= 150 * currentLoc;
                    cout << "Your defense has increased to " << maxHealth << "." << endl;
                    cout << "You now have " << invenGold << " golds." << endl;
                }
                // If the player does not have enough gold,
                // the player cannot upgrade their heath and
                // outputs that the player does not have enough gold
                else {
                    cout << "You do not have enough gold!" << endl;
                }
                presskey();
                system("clear");
            }
        }
        
        // If the player enters "4",
        // players can buy health potions with gold
        else if (answer == "4") {
            cout << "You can buy a health potion for 100 golds" << endl;
            cout << "Would you like to spend 100 golds for a health potion?" << endl;
            cout << "You currently have " << invenGold << "." << endl;
            cout << "Type \"1\" for yes, \"0\" for no." << endl;
            cin >> answer;
            system("clear");

            // Checking whether the input is valid 
            while (answer != "1" && answer != "0") {
                cout << "*** Invalid input. Please type \"1\" to spend 100 golds for a health potion otherwise type \"0\" to exit ***" << endl;
                cin >> answer;
                system("clear");
            }

            // If the player enters "1",
            // the player will buy the potions.
            // The for-loop first checks how many health potions
            // the player has.
            if (answer == "1") {
                int countOfHP = 0;
                for (int i = 0; i < 5; i++) {
                    if (inven[i] == 1) {
                        countOfHP++;
                    }
                }
                // If the player does not have enough gold to buy the potion,
                // the player cannot buy the potions
                // and outputs that the player does not have enough gold.
                if (invenGold < 100) {
                    cout << "You do not have enough gold!" << endl;
                }
                // If the player has 5 health potions already,
                // the player cannot buy the potions
                // and outputs that the player has enough health potions.
                else if (countOfHP == 5) {
                    cout << "You are already holding maximum number of health potions!" << endl;
                }
                else {
                    cout << "You have bought a health potion with 100 golds." << endl;
                    // It will deduct 100 gold from the player.
                    invenGold -= 100;
                    // It will update the inventory of the player.
                    for (int i = 0; i < 5; i++) {
                        if (inven[i] == 0) {
                            inven[i] = 1;
                            break;
                        }
                    }
                    cout << "You now have " << invenGold << "." << endl;
                }
                presskey();
                system("clear");
            }
        }

        action();
        cin >> answer;
        system("clear");
    }
    cout << "You have left the town." << endl;
    presskey();
    system("clear");
}

#endif
