#ifndef PRESSKEY_H
#define PRESSKEY_H

#include <iostream>
using namespace std;

// This function would output "Enter any character to continue" and would wait until the player enters any characters
void presskey() {
    string inputLine;
    cout << "Enter any character to continue..." << endl;
    cin >> inputLine;
}

#endif