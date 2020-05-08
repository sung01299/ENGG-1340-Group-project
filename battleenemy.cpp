#include <iostream>
#include <cstdlib>
#include <ctime>
#include "battleenemy.h"
using namespace std;

void battleenemy(int pinfo.currentLoc){
    srand(time(NULL));
    int answer, retur, missrate, critrate;
    missrate = 5;
    critrate = 5;
    while (pinfo.maxHealth > 0 && einfo.ehealth > 0){
        cout << "To use basic attack, please type \"0\", to use skill, please type \"1\"." << endl;
        cin >> answer;
        while (answer != "0" && answer != "1"){
            cout << "***Invalid input. Please type \"0\" or \"1\" to select.***" << endl;
            cin >> answer;
        }
        if (answer == "0"){
            if (rand()%100<=missrate){
                cout << "Player misses basic attack!" << endl;
            }
            else {
                if (rand()%100<=critrate){
                    cout << "Player deals critical hit!" << endl;
                    einfo.ehealth -= (2*pinfo.basicAttack);
                }
                else {
                    cout << "Player basic attacks enemy" << endl;
                    einfo.ehealth -= pinfo.basicAttack;
                }
            }
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
            cout << "Player died." << endl;
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
            cout << "Player defeated enemy." << endl;
            cout << "Enemy dropped its unique part" << endl;
            
            cout << "Player can now move on to next town." << endl;
        }
    }
}
