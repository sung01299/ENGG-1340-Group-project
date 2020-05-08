#include <iostream>
#include "trade.h"
using namespace std;

void tradeandupgrade(int pinfo.currentLoc){
    int answer0, answer1, answer2, answer3;
    vector<string> names;
    cout << "Player can trade the unique parts or upgrade weapon and armor." << endl;
    cout << "To trade the unique parts with gold, type \"1\", to upgrade weapon, type \"2\", to upgrade armor, type \"3\", to exit, type \"0\"" << endl;
    cin >> answer0;
    while (answer0 != 0){
        if (answer0 == "1"){
            cout << "Input numbers of item you would like to sell." << endl;
            cin >> answer1;
            string name;
            cout << "List the name of items that you would like to sell." << endl;
            for (int i=0; i<answer1; i++){
                cin >> name
                names[i]=name;
            }
            for (int i=0; i<names.size(); i++){
                cout << "Player successfully traded " << names[i] << " with " << value of names[i] << " gold." << endl;
                pinfo.invenGold += value of names[i];
            }
        }
        else if (answer0 == "2"){
            cout << "Player can upgrade weapon with " << /*amount of increase (attack damage)*/ << " by spending " << /*price to upgrade*/ << ". To upgrade, type \"1\"." << endl;
            cin >> answer2;
            if (answer2=="1"){
                pinfo.basicAttack += /*amount of increase (attack damage)*/;
                pinfo.invenGold -= /*price to upgrade*/;
                cout << "Player's attack damage increased to " << pinfo.basicAttack << endl;
                cout << "Player currently has " << pinfo.invenGold << " gold." << endl;
            }
        }
        else if (answer0 == "3"){
            cout << "Player can upgrade armor with " << /*amount of increase (health)*/ << " by spending " << /*price to upgrade*/ << ". To upgrade, type \"1\"." << endl;
            cin >> answer3;
            if (answer3=="1"){
                pinfo.maxHealth += /*amount of increase (health)*/;
                pinfo.invenGold -= /*price to upgrade*/;
                cout << "Player's health increased to " << pinfo.pdefense << endl;
                cout << "Player currently has " << pinfo.invenGold << " gold." << endl;
            }
        }
    }
    cout << "Player exits trademarket." << endl;
}
