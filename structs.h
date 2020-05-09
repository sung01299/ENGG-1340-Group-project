#ifndef STRUCTS_H
#define STRUCTS_H 

#include <vector>
#include <string>
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

#endif
