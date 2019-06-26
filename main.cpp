/*
@author Ann Mai
Simple Console-based Hangman Game
 */

#include <iostream>
#include "hangman.h"

int main() {

    Hangman game("lexicon.txt", 100);
    game.displayMenu();
    return 0;
}