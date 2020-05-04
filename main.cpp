#include <iostream>
#include <string>
using namespace std;

void battleenemy{
    while (pinfo.maxHealth > 0 && einfo.ehealth > 0){
        int answer;
        string retur;
        cout << "To use basic attack, please type \"0\", to use skill, please type \"1\"." << endl;
        cin >> answer;
        while (answer != "0" && answer != "1"){
            cout << "***Invalid input. Please type \"0\" or \"1\" to select.***" << endl;
            cin >> answer;
        }
        if (answer == "0"){
            cout << "Player basic attacks enemy" << endl;
            einfo.ehealth -= pinfo.basicAttack;
            cout << "Enemy health remaining: " << einfo.ehealth << endl;
            cout << "Enemy attacks player" << endl;
            pinfo.maxHealth -= einfo.eattack;
            cout << "Player health remaining: " << pinfo.maxHealth << endl;
        }
        else if (answer == "1"){
            cout << "Player uses skill to enemy" << endl;
            einfo.ehealth -= sinfo.damage;
            cout << "Enemy health remaining: " << einfo.ehealth << endl;
            cout << "Enemy attacks player" << endl;
            pinfo.maxHealth -= einfo.eattack;
            cout << "Player health remaining: " << pinfo.maxHealth << endl;
        }
        
        if (pinfo.maxHealth <= 0){
            cout << "You died." << endl;
            cout << "To return to main menu, please type \"return\"." << endl;
            cin >> retur;
            while (retur != "return"){
                cout << "***Invalid input. Please type \"return\" to select.***" << endl;
                cin >> retur;
            }
            if (retur == "return"){
                //code to return main menu
            }
        }
        else if (einfo.ehealth <=0){
            cout << "You defeated enemy." << endl;
            cout << "You can now move on to next village." << endl;
        }
    }
}

int main()
{

    /* This struct is used to store player's information
        pname for player's name
        maxHealth for player's health
        currentHealth for player's current health
        basicAttack for the basic amount of damage the player can deal;
        pdefense for player's current health
        invenGold for amound of gold the player has
        currentLoc for current location of the player
        inven for player's inventory and the maximum number of items the player can hold is 5
        obtainedSkill for the skills the player has and the maximum number of skills players can use*/
    struct PlayerInfo {
        string pname;
        int maxHealth;
        int currentHealth;
        int pdefense;
        int basicAttack;
        int invenGold;
        int currentLoc;
        string inven[5];
        string obtainedSkill[3];
    };

    /* This struct is used to store enemy information 
        ename for enemy's name
        ehealth for enemy's health
        edefense for enemy's defense
        egold for the amount of gold player could ontain from defeating it */
    struct EnemyInfo {
        string ename;
        int ehealth;
        int edefense;
        int egold;
    };

    /* This struct is used to store item information 
        itemID for ID of the item
        itemName for name of the item
        itemPrice for price of the item */
    struct ItemInfo {
        string itemID;
        string itemName;
        int itemPrice;
    };

    /* This struct is used to store skill information
        skillID for ID of the skill
        skillName for name of the skill
        damage for the amount of damage the skill can deal
        maxTimes for the number of times the skill could be used */
    struct SkillInfo {
        string skillID;
        string skillName;
        int damage;
        int maxTimes;
    };

    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine, name, answer;

    /* Main start menu */
    cout << "~~~~~~~~~~ MYSTERIOUS YYETNAL ~~~~~~~~~~" << endl;
    cout << "Developed by CHOI Yoon Sun and HUH Sung." << endl;
    cout << "Type \"start\" to start the game." << endl;
    cin >> inputLine;

    /* If the player inputs something other than "start", it will ask the player to input again until it is a valid input (i.e., start)*/
    while (inputLine != "start") {
        cout << "***Invalid input. Please type \"start\" to start the game.***" << endl;
        cin >> inputLine;
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

    PlayerInfo pinfo;
    pinfo.pname = name;
    cout << endl << "????: My apologies for not introducing myself first." << endl;
    cout << "Noin: The name is Noin Arak, but you may call me Noin." << endl;

    return 0;
}
