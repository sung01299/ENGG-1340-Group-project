/* main.cpp */

#include <iostream>
#include <fstream>
/* <fstream> is used for reading and writing files */
#include <stdlib.h>
/* <stdlib.h> is used for system("clear"). This function helps clear the screen */
#include <string>
#include <cstdio>
/* <cstdio> is used for remove() to remove files in UNIX */
#include "structs.h"
/* This header file includes the structs information needed for this game */
#include "askname.h"
/* This header file includes the function of askingName() */
#include "battleenemy.h"
/* This header file includes the function of battleenemy() */
#include "trade.h"
/* This header file includes the function of tradeandupgrade() */
#include "presskey.h"
/* This header file includes the function of presskey() */
using namespace std;

// This function would print an ASCII art of a town
void printTown() {
    cout << "              /\\" << endl;
    cout << "    ///\\     ||||" << endl;
    cout << "   ///  \\  //====\\\\" << endl;
    cout << "   ||| []| | |    | | |----||----|" << endl;
    cout << "___|||___|_|_|_[]_|_|_|_[]_||_[]_|___" << endl << endl;
}

void autosave(string pname, int maxHealth, int currentHealth, int basicAttack, int invenGold, int currentLoc, int inven[], vector<string> inventory) {
    cout << "Game saved!" << endl;

    ofstream fout;
    fout.open("savefile.txt");

    fout << pname << " " << maxHealth << " " << currentHealth << " " << basicAttack << " " << invenGold << " " << currentLoc << " " << inventory;
    for (int i = 0; i < 5; i++) {
        fout << inven[i] << " ";
    }
    for (int k=0; k < 5; k++) {
        fout << inventory[k] << " ";
    }
    fout.close();
}

int main()
{
    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine;
    PlayerInfo pinfo;
    bool dead = false;

    /* Main start menu */
    cout << "~~~~~~~~~~ MYSTERIOUS YYETNAL ~~~~~~~~~~" << endl;
    cout << "Developed by: " << endl;
    cout << "CHOI Yoon Sun  UID: 3035683784" << endl;
    cout << "HUH Sung   UID: 3035660744" << endl;
    cout << endl << "** The battle style in this game is referenced from the Pokemon Series **" << endl;
    cout << endl <<  "Type \"start\" to start the game." << endl;
    cin >> inputLine;
    system("clear");

    /* If the player inputs something other than "start", it will ask the player to input again until it is a valid input (i.e., start)*/
    while (inputLine != "start") {
        cout << "***Invalid input. Please type \"start\" to start the game.***" << endl;
        cin >> inputLine;
        system("clear");
    }

    ifstream fin;
    fin.open("savefile.txt");
    if (fin.fail()) {
        cout << "Thank you for playing Yyetnal!" << endl;
        cout << "Enjoy your adventure!" << endl;

        // Starting player stats
        pinfo.maxHealth = 150;
        pinfo.currentHealth = 150;
        pinfo.basicAttack = 45;
        pinfo.invenGold = 0;
        for (int i = 0; i < 5; i++) {
            pinfo.inven[i] = 0;
        }

        pinfo.pname = askingName();
        presskey();
        system("clear");

        cout << "* You wake up and you see a paper lying on the floor *" << endl << "Type \"read\" to read the paper." << endl;
        cin >> inputLine;
        system("clear");

        while (inputLine != "read") {
            cout << "***Invalid input. Please type \"read\" to read the paper.***" << endl;
            cin >> inputLine;
            system("clear");
        }

        cout << "\"The sword is hidden somewhere in the mountains, near the town of Aran.\"" << endl;
        presskey();
        system("clear");

        cout << pinfo.pname << ": That's weird. I'm sure this wasn't here before I went to sleep." << endl;
        cout << pinfo.pname << ": But this journey sounds interesting." << endl;
        presskey();
        system("clear");

        cout << "*You take your sword and leave the house*" << endl;
        cout << "*Your journey to the town of Aran starts*" << endl;
        cout << "Type \"continue\" to continue or \"save\" to save and quit the game." << endl;
        cin >> inputLine;
        system("clear");

        while (inputLine != "continue" && inputLine != "save") {
            cout << "***Invalid input. Please type \"continue\" to continue or \"save\" to save and quit the game." << endl;
            cin >> inputLine;
            system("clear");
        }

        pinfo.currentLoc = 1;
        autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
    }
    else {
        cout << "Saved file found..." << endl;
        cout << "Loading game..." << endl;
        cout << "Game loaded!" << endl;
        fin >> pinfo.pname >> pinfo.maxHealth >> pinfo.currentHealth >> pinfo.basicAttack >> pinfo.invenGold >> pinfo.currentLoc;
        for (int i = 0; i < 5; i++) {
            fin >> pinfo.inven[i];
        }
        for (int k = 0; k < 5; k++) {
            fin >> inventory[k];
        }
        fin.close();
        cout << endl << "Work it, " << pinfo.pname << "! You got this!" << endl;
        cout << "Type \"continue\" to continue" << endl;
        cin >> inputLine;
        system("clear");

        while (inputLine != "continue") {
            cout << "***Invalid input. Please type \"continue\" to continue" << endl;
            cin >> inputLine;
            system("clear");
        }
    }
    while (dead == false) {
        while (inputLine != "quit" && dead == false) {
            if (pinfo.currentLoc == 1) {
                cout << "* While on your way, you encounter the monster, Asa and it suddenly charges on you *" << endl;
                if (battleenemy(1, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.inven) == false) {
                    dead = true;
                }
                else {
                    pinfo.currentLoc = 2;
                    autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                }
            }

            else if (pinfo.currentLoc == 2) {
                cout << "\"You are now in the town of Tanook\"" << endl;
                printTown();
                tradeandupgrade(pinfo.currentLoc, pinfo.invenGold, pinfo.basicAttack, pinfo.maxHealth, pinfo.inven);
                autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                pinfo.currentLoc = 3;
            }

            else if (pinfo.currentLoc == 3) {
                cout << "* While on your way, you encounter bandit Patel *" << endl;
                cout << endl << "Patel: Where are you going, little kid? Now, give me all you have!" << endl << endl;
                if (battleenemy(3, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.inven) == false) {
                    dead = true;
                }
                else {
                    pinfo.currentLoc = 4;
                    autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                }
            }

            else if (pinfo.currentLoc == 4) {
                cout << "\"You are now in the town of Terra\"" << endl;
                printTown();
                tradeandupgrade(pinfo.currentLoc, pinfo.invenGold, pinfo.basicAttack, pinfo.maxHealth, pinfo.inven);
                autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                pinfo.currentLoc = 5;
            }

            else if (pinfo.currentLoc == 5) {
                cout << "* While on your way, you encounter royal soldier, Majav *" << endl;
                cout << endl << "Majav: Where do you think, you're going? This place is off-limit for peasants like you." << endl;
                cout << "Majav: You shall fight me to pass this place!" << endl << endl;
                if (battleenemy(5, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.inven) == false) {
                    dead = true;
                }
                else {
                    pinfo.currentLoc = 6;
                    autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                }
            }

            else if (pinfo.currentLoc == 6) {
                cout << "\"You are now in the town of Aran\"" << endl;
                printTown();
                tradeandupgrade(pinfo.currentLoc, pinfo.invenGold, pinfo.basicAttack, pinfo.maxHealth, pinfo.inven);
                autosave(pinfo.pname, pinfo.maxHealth, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.currentLoc, pinfo.inven, inventory);
                pinfo.currentLoc = 7;
            }

            else if (pinfo.currentLoc == 7) {
                cout << "After passing the town of Aran, you find a mysterious stone path leading to somewhere deep in the mountains..." << endl;
                cout << "After walking for some time, you hear an old man..." << endl;
                presskey();
                system("clear");

                cout << "Old man: Hello, young blood. Are you lost?" << endl;
                presskey();
                system("clear");

                cout << pinfo.pname << ": No, I'm here to look for the sword" << endl;
                cout << pinfo.pname << ": Do you know where it is?" << endl;
                presskey();
                system("clear");

                cout << "Old man: Oh, you have come to the right place..." << endl;
                cout << endl << "* Old man suddenly turns into a stone bodided giant *" << endl;
                presskey();
                system("clear");

                cout << "Karagon: HOW DARE YOU COME HERE" << endl;
                cout << "Karagon: I HAVE BEEN ORDERED TO GUARD THIS SACRED PLACE" << endl;
                cout << "Karagon: NOBODY HAS LEFT THIS PLACE ALIVE AND SO WILL YOU!" << endl;
                presskey();
                system("clear");

                battleenemy(7, pinfo.currentHealth, pinfo.basicAttack, pinfo.invenGold, pinfo.inven);
                pinfo.currentLoc = 8;

                cout << "You have defeated the final guardian of the sword Karagon." << endl;
                cout << "\"You have obtained the key to the sword\"" << endl;
                presskey();
                system("clear");

                cout << "Type \"unlock\" to unlock the door to the sword" << endl;
                cin >> inputLine;
                system("clear");

                while (inputLine != "unlock") {
                    cout << "*** Invalid input. Please type \"unlock\" to unlock the door to the sword ***" << endl;
                    cin >> inputLine;
                    system("clear");
                }

                cout << "  /\\ " << endl;
                cout << "  || " << endl;
                cout << "  || " << endl;
                cout << "  || " << endl;
                cout << "  || " << endl;
                cout << " '--'" << endl;
                cout << "  [] " << endl;
                cout << "You have obtained the legendary sword!" << endl;
                presskey();
                system("clear");

                cout << "????: Ha ha" << endl;
                cout << "????: So you have found the sword" << endl;
                cout << "Noin: That sword belongs to me" << endl;
                cout << "Noin: By going through the difficulties coming here, you have proven me that I have not made a mistake choosing you" << endl;
                cout << "Noin: I hope you could continue my legacy and protect Yyetnal" << endl;
                presskey();
                system("clear");

                cout << "---------------- THE END ----------------" << endl;
                cout << "Thank you for playing Mysterious Yyetnal!" << endl;
                cout << "Developed by CHOI Yoon Sun and HUH Sung" << endl;
                cout << "Type \"exit\" to exit the game" << endl;
                cin >> inputLine;
                system("clear");

                while (inputLine != "exit") {
                    cout << "*** Invalid input. Please type \"exit\" to exit ***" << endl;
                    cin >> inputLine;
                    system("clear");
                }
                inputLine = "save";
            }

            if (pinfo.currentLoc != 8) {
                cout << "Type \"continue\" to continue or \"quit\" to quit the game" << endl;
                cin >> inputLine;
                system("clear");
            }

            while (inputLine != "continue" && inputLine != "quit") {
                cout << "***Invalid input. Please type \"continue\" to continue or \"quit\" to quit the game." << endl;
                cin >> inputLine;
                system("clear");
            }
        }
        dead = false;
        if (inputLine == "quit") {
            break;
        }
    }

    /* If the player completes the game (i.e., beating the final boss), the saved file will be deleted, so that the player can start the game again */
    if (pinfo.currentLoc == 8) {
        remove("savefile.txt");
    }

    return 0;
}
