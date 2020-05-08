#include <iostream>
#include <fstream>
/* <fstream> is used for reading and writing files */
#include <stdlib.h>
/* <stdlib.h> is used for system("CLS") and system("PAUSE"). The former clears the screen 
while the latter waits for the user to enter any keys to continue */
#include <string>
#include <cstdio>
/* <cstdio> is used for remove() to remove files in UNIX */
#include "structs.h"
/* This header file includes the structs information needed for this game */
#include "askname.h"
/* This header file includes the function of askingName() */
//#include "battleenemy.h"
/* This header file includes the function of battleenemy() */
using namespace std;

void printTown() {
    cout << "What would you like to do?" << endl;
    cout << "1 - Go to trade market" << endl;
    cout << "2 - Continue journey" << endl;
}

void townAction(string inputLine) {
    if (inputLine == "1") {
        cout << 1 << endl;
    }
    else if (inputLine == "2") {
        cout << 2 << endl;
    }
}

int main()
{
    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine;
    PlayerInfo pinfo;

    /* Main start menu */
    cout << "~~~~~~~~~~ MYSTERIOUS YYETNAL ~~~~~~~~~~" << endl;
    cout << "Developed by CHOI Yoon Sun and HUH Sung." << endl;
    cout << "Type \"start\" to start the game." << endl;
    cin >> inputLine;
    system("CLS");

    ifstream fin;
    fin.open("savefile.txt");
    if (fin.fail()) {
        cout << "Thank you for playing Yyetnal!" << endl;
        cout << "Enjoy your adventure!" << endl;
        pinfo.pname = askingName();
        system("PAUSE");
        system("CLS");

        cout << "*You wake up and you see a paper lying on the floor*" << endl << "Type \"read\" to read the paper" << endl;
        cin >> inputLine;
        system("CLS");

        cout << "\"The sword is hidden somewhere in the mountains, near the town of Aran.\"" << endl;
        system("PAUSE");
        system("CLS");

        cout << pinfo.pname << ": That's weird. I'm sure this wasn't here before I went to sleep." << endl;
        cout << pinfo.pname << ": But this journey sounds interesting." << endl;
        system("PAUSE");
        system("CLS");
        
        // Starting player stats
        pinfo.maxHealth = 150;
        pinfo.currentHealth = 150;
        pinfo.basicAttack = 45;
        pinfo.invenGold = 0;
        pinfo.currentLoc = 1;

        cout << "*You take your sword and leave the house*" << endl;
        cout << "*Your journey to the town of Aran starts*" << endl;
        cout << "Type \"continue\" to continue or \"save\" to save and quit the game" << endl;
        cin >> inputLine;

        pinfo.currentLoc = 1;
    }
    else {
        cout << "Saved file found..." << endl;
        cout << "Loading game..." << endl;
        cout << "Game loaded!" << endl;
        fin >> pinfo.pname >> pinfo.maxhealth >> pinfo.currentHealth >> pinfo.basicAttack >> pinfo.invenGold >> pinfo.currentLoc;
        for (int i = 0; i < 5; i++) {
            fin >> pinfo.inven[i];
        }
        fin.close();
        cout << endl << "Work it, " << pinfo.pname << "! You got this!";
        system("PAUSE");
        system("CLS");
    }

    /* If the player inputs something other than "start", it will ask the player to input again until it is a valid input (i.e., start)*/
    while (inputLine != "start") {
        cout << "***Invalid input. Please type \"start\" to start the game.***" << endl;
        cin >> inputLine;
        system("CLS");
    }
    
    pinfo.currentLoc = 0;
    cout << "Testng Input: ";
    cin >> inputLine;
    system("CLS");

    while (inputLine != "save") {
        if (pinfo.currentLoc == 1) {
            cout << "* While on your way, you encounter the monster, Asa and it suddenly charges on you *" << endl;

            //battleenemy();

            cout << "You have defeated Asa and obtained " << endl;
            cout << "Type \"continue\" to continue or \"save\" to save and quit the game" << endl;
            cin >> inputLine;

            pinfo.currentLoc = 2;
        }

        else if (pinfo.currentLoc == 2) {
            cout << "\"You are now in the town of Tanook\"" << endl;
            while (inputLine != "2") {
                printTown();
                cin >> inputLine;
                townAction(inputLine);
            }
            pinfo.currentLoc = 3;
        }

        else if (pinfo.currentLoc == 3) {
            cout << "* While on your way, you encounter bandit Patel *" << endl;
            cout << endl << "Patel: Where are you going, little kid? Now, give me all you have!" << endl;
            if (battleenemy() == false) {}
            pinfo.currentLoc = 4;
        }

        else if (pinfo.currentLoc == 4) {
            cout << "\"You are now in the town of Terra\"" << endl;
            while (inputLine != "2") {
                printTown();
                cin >> inputLine;
                townAction(inputLine);
            }
            pinfo.currentLoc = 5;
        }

        else if (pinfo.currentLoc == 5) {
            if (battleenemy() == false) {}
            pinfo.currentLoc = 6;
        }

        else if (pinfo.currentLoc == 6) {
            cout << "\"You are now in the town of Aran\"" << endl;
            while (inputLine != "2") {
                printTown();
                cin >> inputLine;
                townAction(inputLine);
            }
        }

        else if (pinfo.currentLoc == 7) {
            if (battleenemy() == false) {}
            pinfo.currentLoc = 8;

            cout << "You have defeated the final guardian of the sword Karagon." << endl;
            cout << "\"You have obtained the key to the sword\"" << endl;
            system("PAUSE");
            system("CLS");

            cout << "Type \"unlock\" to unlock the door to the sword" << endl;
            cin << inputLine;
            system("CLS");

            cout << "  /\\ " << endl; 
            cout << "  || " << endl;
            cout << "  || " << endl;
            cout << "  || " << endl;
            cout << "  || " << endl;
            cout << " '--'" << endl;
            cout << "  [] " << endl;
            cout << "You have obtained the legendary sword!" << endl;
            system("PAUSE");
            system("CLS");

            cout << "????: Ha ha" << endl;
            cout << "????: So you have found the sword" << endl;
            cout << "Noin: That sword belongs to me" << endl;
            cout << "Noin: By going through the difficulties coming here, you have proven me that I have not made a mistake choosing you" << endl;
            cout << "Noin: I hope you could continue my legacy and protect Yyetnal" << endl;
            system("PAUSE");
            system("CLS");

            cout << "---------------- THE END ----------------" << endl;
            cout << "Thank you for playing Mysterious Yyetnal!" << endl;
            cout << "Developed by CHOI Yoon Sun and HUH Sung" << endl;
            cout << "Type \"exit\" to exit the game" << endl;
            cin >> inputLine;
            system("CLS");

            while (inputLine != "exit") {
                cout << "*** Invalid input. Please type \"exit\" to exit ***" << endl;
                cin >> inputLine;
                system("CLS");
            }
            inputLine = "save";
        }
    }
    
    /* If the player completes the game (i.e., beating the final boss), the saved file will be deleted, so that the player can start the game again */
    if (pinfo.currentLoc == 8) {
        remove("savefile.txt");
    }

    /* If the player did complete the game and quits, the data will be saved in a file called "savefile.txt" */
    else {
        ofstream fout;
        fout.open("savefile.txt");

        fout << pinfo.pname << pinfo.maxhealth << pinfo.currentHealth << pinfo.basicAttack << pinfo.invenGold << pinfo.currentLoc;
        for (int i = 0; i < 5; i++) {
            fout << pinfo.inven[i];
        }
        fout.close();
    }
    
    //stats
    EnemyInfo firstboss;
    EnemyInfo secondboss;
    EnemyInfo thirdboss;
    EnemyInfo finalboss;
    
    
    battleenemy(1);
    tradeandupgrade();
    pinfo.currentLoc+=1;
    
    battleenemy(2);
    tradeandupgrade();
    pinfo.currentLoc+=1;
    
    battleenemy(3);
    tradeandupgrade();
    pinfo.currentLoc+=1;
    
    battleenemy(4);
    
    return 0;
}
