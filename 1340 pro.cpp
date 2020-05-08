#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

vector<string> inventory;

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
    int basicAttack;
    int invenGold;
    int currentLoc;
} pinfo;


/* This struct is used to store enemy information 
    ename for enemy's name
    ehealth for enemy's health
    edefense for enemy's defense
    egold for the amount of gold player could ontain from defeating it */
struct EnemyInfo {
    string ename;
    int ehealth;
    int eattack;
    int egold;
} firstboss, secondboss, thirdboss, finalboss;


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
} sinfo;




void askingName() {
    int answer;
    /* Getting name from the player */
    string name;
    cout << endl << "Please enter your name: ";
    cin >> name;
    cout << endl << "????: Hello, " << name << "." << endl;
    cout << "1 - How do you know me? Who are you?" << endl << "0 - That is not my name." << endl;
    cout << "Type \"1\" or \"0\" to select." << endl;
    cin >> answer;

    /* If the player inputs an invalid input, it will ask the player to input again */
    while (answer != 1 && answer != 0) {
        cout << "***Invalid input. Please type \"1\" or \"0\" to select.***" << endl;
        cin >> answer;
    }

    /* If the player answers "2", it will ask the player to enter their name again.*/
    if (answer == 0) {
        cout << endl << "????: Then may I ask what your name is?" << endl;
        cout << "Please enter your name: ";
        cin >> name;
        cout << endl << "????: Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
        cin >> answer;

        /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
        while (answer != 1 && answer != 0) {
            cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
            cin >> answer;
        }

        /* If the input name is still not what the player wants, the player can input it again until the player is satisfied. */
        if (answer == 0) {
            while (answer == 0) {
                cout << endl << "????: May I ask again what your name is?" << endl;
                cout << "Please enter your name: ";
                cin >> name;
                cout << endl << "Is " << name << " your name?" << endl << "Type \"1\" for yes or \"0\" for no." << endl;
                cin >> answer;

                /* If the player inputs an invalid input, it will ask the player to input a valid input (i.e., 1 or 0) again */
                while (answer != 1 && answer != 0) {
                    cout << "***Invalid input. Please type \"1\" or \"0\" to answer.***" << endl;
                    cin >> answer;
                }
                if (answer == 1) {
                    cout << endl << "????: Great!";
                }
            }
        }
    }

    pinfo.pname = name;
    
    cout << endl << "????: My apologies for not introducing myself first." << endl;
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

}

bool battleenemy(int x){
	pinfo.currentHealth = pinfo.maxHealth;
	firstboss.ename="Asq";
    firstboss.ehealth=200;
    firstboss.eattack=15;
    firstboss.egold=300;
    
    secondboss.ename="Patel";
    secondboss.ehealth=400;
    secondboss.eattack=20;
    secondboss.egold=600;
    
    thirdboss.ename="Majav";
    thirdboss.ehealth=600;
    thirdboss.eattack=50;
    thirdboss.egold=900;
   
    finalboss.ename="Karagon";
    finalboss.ehealth=800;
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
    missrate = 10;
    critrate = 10;
    maxskilluse=3;
    
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
            	cout << "Enemy health remaining: " << ehealth << endl;
            	cout << "Enemy attacks player" << endl;
            	pinfo.currentHealth -= eattack;
            	cout << "Player health remaining: " << pinfo.currentHealth << endl;
            	cout << "Player skill remaining: " << maxskilluse << endl;
            	cout << endl;
			}    
        }
       
        if (ehealth <=0){
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
	else if (pinfo.currentHealth <= 0){
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
    }
}



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
                	pinfo.basicAttack += 30*pinfo.currentLoc;
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
}

int main()
{
    /* variable inputline stores the input from the user
       variable name stores the name of the player/character
       variable answer stores the choice (e.g. 1/0) from the player */
    string inputLine, answer;

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

    askingName();
    
    cout << endl << "*You wake up and you see a paper lying on the floor*" << endl << "Type \"read\" to read the paper" << endl;
    cin >> inputLine;
    
    cout << endl << "\"The sword is hidden somewhere in the mountains, near the town of Aran.\"" << endl;

    cout << endl << pinfo.pname << ": That's weird. I'm sure this wasn't here before I went to sleep." << endl;
    cout << pinfo.pname << ": But this journey sounds interesting." << endl;

    cout << endl << "*You take your sword and leave the house*" << endl;

    cout << "*Your journey to the town of Aran starts*" << endl;

    cout << endl << "* While on your way, you encounter the monster, Asaand it suddenly charges on you *" << endl;

    
    
    //set player's stat
    pinfo.maxHealth=150;
    pinfo.currentHealth=150;
    pinfo.basicAttack=45;
    pinfo.invenGold=0;
    pinfo.currentLoc=1;
    
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
    
    cout << "Congratulations!! You defeated every monsters!!!" << endl;

    return 0;
}
