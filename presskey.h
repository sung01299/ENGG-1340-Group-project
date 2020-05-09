// This header file includes the function presskey().

#ifndef PRESSKEY_H
#define PRESSKEY_H

#include <iostream>
using namespace std;

// This function would output "Enter any character to continue" and would wait until the player enters any characters
// The funnction returns void.
// No input is needed.
void presskey() {
    string inputLine;
    cout << "Enter any character to continue..." << endl;
    cin >> inputLine;
}

#endif
