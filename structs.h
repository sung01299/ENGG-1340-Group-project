#ifndef STRUCTS_H
#define STRUCTS_H 

#include <vector>
#include <string>
using namespace std;

vector<string> inventory;

/* This struct is used to store player's information
    pname for player's name
    maxHealth for player's health
    basicAttack for the basic amount of damage the player can deal;
    pdefense for player's current health
    invenGold for amound of gold the player has
    currentLoc for current location of the player
    inven for player's inventory and the maximum number of items the player can hold is 5
    obtainedSkill for the skills the player has and the maximum number of skills players can use*/
struct PlayerInfo {
    string pname;
    int maxHealth;
    int basicAttack;
    int invenGold;
    int currentLoc;
    int inven[5];
};

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
};

#endif
