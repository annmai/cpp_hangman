/*
@author Ann Mai
Simple Console-based Hangman Game
 */

#include <iostream>
#include <climits>
#include "hangman.h"

int main() {

    int userChoice;
    bool isInvalidSelection = false;

    while(true) {
        
        Hangman game("lexicon.txt", 100);
        game.displayMenu(); 

        cout << "Enter Your Selection: ";
        cin >> userChoice;

        do {

            if(userChoice == 1) {
                cout << "Let the game begin!\n";
                game.play();
                break;
            }
            else if(userChoice == 2) {
                cout <<  "Goodbye!";
                return 0;
            }

            else {
                isInvalidSelection = true;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid Choice. Enter Your Selection: ";
                cin >> userChoice;
            }
        }
        while(isInvalidSelection);
    }
  
    return 0;
}