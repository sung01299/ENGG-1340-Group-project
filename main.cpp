#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine, name, answer;

    cout << "~~~~~~~~~~ MYSTERIOUS YYETNAL ~~~~~~~~~~" << endl;
    cout << "Developed by CHOI Yoon Sun and HUH Sung." << endl;
    cout << "Type \"start\" to start the game." << endl;
    cin >> inputLine;

    /* If the player inputs something other than "start", it will ask the player to input again until it is a valid input (i.e., start)*/
    while (inputLine != "start") {
        cout << "Invalid input. Please type \"start\" to start the game." << endl;
        getline(cin, inputLine);
    }

    /* Getting name from the player */
    cout << endl << "Please enter your name: ";
    cin >> name;
    cout << endl << "????: Hello, " << name << "." << endl;
    cout << "1 - How do you know me? Who are you?" << endl << "0 - That is not my name." << endl;
    cout << "Type \"1\" or \"0\" to select." << endl;
    cin >> answer;

    /* If the player inputs an invalid input, it will ask the player to input again */
    while (answer != "1" && answer != "0") {
        cout << "***Invalid input. Please type \"1\" or \"0\" to select.***" << endl;
        cin >> answer;
    }

    /* If the player answers "2", it will ask the player to enter their name again.*/
    if (answer == "0") {
        cout << endl << "????: Then may I ask what your name is?" << endl;
        cout << "Please enter your name: ";
        cin >> name;
        cout << endl << "????: Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
        cin >> answer;

        /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
        while (answer != "1" && answer != "0") {
            cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
            cin >> answer;
        }

        /* If the input name is still not what the player wants, the player can input it again until the player is satisfied. */
        if (answer == "0") {
            while (answer == "0") {
                cout << endl << "????: May I ask again what your name is?" << endl;
                cout << "Please enter your name: ";
                cin >> name;
                cout << endl << "Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
                cin >> answer;

                /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
                while (answer != "1" && answer != "0") {
                    cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
                    cin >> answer;
                }
                if (answer == "1") {
                    cout << endl << "????: Great!";
                }
            }
        }
    }

    cout << endl << "????: My apologies for not introducing myself first." << endl;
    cout << "Noin: The name is Noin Arak, but you may call me Noin." << endl;

    return 0;
}
