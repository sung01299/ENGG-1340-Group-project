#ifndef NAME_H
#define NAME_H

#ifndef ASKNAME_H
#define ASKNAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "askname.h"
using namespace std;

string askingName() {
    /* Getting name from the player */
    string name, answer;
    cout << "Please enter your name: ";
    cin >> name;
    system("CLS");

    cout << "????: Hello, " << name << "." << endl;
    cout << "1 - How do you know me? Who are you?" << endl << "0 - That is not my name." << endl;
    cout << "Type \"1\" or \"0\" to select." << endl;
    cin >> answer;
    system("CLS");

    /* If the player inputs an invalid input, it will ask the player to input again */
    while (answer != "1" && answer != "0") {
        cout << "***Invalid input. Please type \"1\" or \"0\" to select.***" << endl;
        cin >> answer;
        system("CLS");
    }

    /* If the player answers "2", it will ask the player to enter their name again.*/
    if (answer == "0") {
        cout << "????: Then may I ask what your name is?" << endl;
        cout << "Please enter your name: ";
        cin >> name;
        system("CLS");
        cout << "????: Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
        cin >> answer;
        system("CLS");

        /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
        while (answer != "1" && answer != "0") {
            cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
            cin >> answer;
            system("CLS");
        }

        /* If the input name is still not what the player wants, the player can input it again until the player is satisfied. */
        if (answer == "0") {
            while (answer == "0") {
                cout << "????: May I ask again what your name is?" << endl;
                cout << "Please enter your name: ";
                cin >> name;
                system("CLS");
                cout << "????: Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
                cin >> answer;
                system("CLS");

                /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
                while (answer != "1" && answer != "0") {
                    cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
                    cin >> answer;
                    system("CLS");
                }
                if (answer == "1") {
                    cout << "????: Great!" << endl;
                }
            }
        }
    }

    cout << "????: My apologies for not introducing myself first." << endl;
    cout << "Noin: The name is Noin Arak, but you may call me Noin." << endl;
    cout << "Noin: There is something you need to know about this island." << endl;
    cout << "Noin: According to a legend, there was once a brave warrior called Alexander Nion." << endl;
    cout << "Noin: He protected the island with his mighty sword and was respected by many of the islanders." << endl;
    cout << "Noin: Before he disappeared, it is told that he has hidden his sword somewhere deep in the island." << endl;
    cout << "Noin: As now he disappeared, we have no protector in the island." << endl;
    cout << "Noin: So I want you to find this hidden swordand become the protector of the island." << endl;
    cout << "Noin: But beware, you may meet the guardians of the sword during your jounrey." << endl;
    cout << "Noin: Be safe out there and wishing you good luck." << endl;
    cout << "Noin: Remember, you are the CHOSEN ONE." << endl;

    return name;
}

#endif

#endif
