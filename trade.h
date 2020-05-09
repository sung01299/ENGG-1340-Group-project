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

void action() {
    cout << "You can trade the unique parts for gold, upgrade weapon and armour or buy health potions" << endl;
    cout << "To trade the unique parts for gold, type \"1\"." << endl;
    cout << "To upgrade weapon, type \"2\"." << endl;
    cout << "To upgrade armor, type \"3\"." << endl;
    cout << "To buy health potions, type \"4\"." << endl;
    cout << "To exit, type \"0\"." << endl;
}

void tradeandupgrade(int currentLoc, int &invenGold, int &basicAttack, int &maxHealth, int inven[]) {
    string answer;
    currentLoc = currentLoc / 2;
    int number, num;
    vector<string> names;
    action();
    cin >> answer;
    system("clear");

    while (answer != "0" && answer != "1" && answer != "2" && answer != "3" && answer != "4") {
        cout << "*** Invalid input! ***" << endl;
        action();
        cin >> answer;
        system("clear");
    }

    while (answer != "0") {
        if (answer == "1") {
            cout << "To view your inventory, type \"1\", to exit, type \"0\"" << endl;
            cin >> answer;
            system("clear");

            while (answer != "1" && answer != "0") {
                cout << "*** Invalid input. Please type \"1\" to view inventory otherwise type \"0\" to exit ***" << endl;
                cin >> answer;
                system("clear");
            }

            if (answer == "1") {
                if (inventory.size() >= 1) {
                    for (int i = 0; i < inventory.size(); i++) {
                        cout << i + 1 << ". " << inventory[i] << endl;
                    }
                    cout << "How many items would you like to sell?" << endl;
                    cin >> num;
                    system("clear");

                    if (num >= 1) {
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
                else {
                    cout << "Nothing to sell in your inventory" << endl;
                    presskey();
                    system("clear");
                }
            }
        }

        else if (answer == "2") {
            cout << "You can upgrade your weapon with " << 30 * currentLoc + basicAttack << " by spending " << 150 * currentLoc << " golds." << endl;
            cout << "Your current attack damage is " << basicAttack << "." << endl;
            cout << "You currently have " << invenGold << " golds." << endl;
            cout << "To upgrade, type \"1\", otherwise type \"0\" to exit." << endl;
            cin >> answer;
            system("clear");

            if (answer == "1") {
                if (invenGold >= 150 * currentLoc) {
                    basicAttack += 30 * currentLoc;
                    invenGold -= 150 * currentLoc;
                    cout << "Your attack damage increased to " << basicAttack << endl;
                    cout << "You now have " << invenGold << " golds." << endl;
                }
                else {
                    cout << "You do not have enough gold!" << endl;
                }
                presskey();
                system("clear");
            }
        }
        else if (answer == "3") {
            cout << "You can upgrade armor to " << 30 * currentLoc + maxHealth << " by spending " << 100 * currentLoc << "." << endl;
            cout << "Your current defense is " << maxHealth << "." << endl;
            cout << "You currently have " << invenGold << " golds." << endl;
            cout << "To upgrade, type \"1\", otherwise type \"0\" to exit." << endl;
            cin >> answer;
            system("clear");

            if (answer == "1") {
                if (invenGold >= 150 * currentLoc) {
                    maxHealth += 30 * currentLoc;
                    invenGold -= 150 * currentLoc;
                    cout << "Your defense has increased to " << maxHealth << "." << endl;
                    cout << "You now have " << invenGold << " golds." << endl;
                }
                else {
                    cout << "You do not have enough gold!" << endl;
                }
                presskey();
                system("clear");
            }
        }
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

            if (answer == "1") {
                int countOfHP = 0;
                for (int i = 0; i < 5; i++) {
                    if (inven[i] == 1) {
                        countOfHP++;
                    }
                }
                cout << "countOfHP is " << countOfHP << endl;
                if (invenGold < 100) {
                    cout << "You do not have enough gold!" << endl;
                }
                else if (countOfHP == 5) {
                    cout << "You are already holding maximum number of health potions!" << endl;
                }
                else {
                    cout << "You have bought a health potion with 100 golds." << endl;
                    invenGold -= 100;
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
