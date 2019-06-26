#include "hangman.h"
#include <fstream>
#include <iostream>

Hangman::Hangman(string words, int numWords) {
    isGameOver = false;
    numGuessesLeft = MAX_GUESSES;
    secretWord = readRandomWordFromFile(words, numWords);
}

string Hangman::readRandomWordFromFile(string filename, int numWords) {

    ifstream wordsFile(filename);

    // read a word from a random line number in the file and
    // store the word read in member string 'secretWord'
    int randomNumber = rand() % numWords + 1;
    for(int i = 0; i < randomNumber; ++i) {
        getline(wordsFile, secretWord);
        
    }

    return secretWord;
}

void Hangman::displayMenu() {
    
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                               *\n";
	cout << "*              WELCOME TO HANGMAN!              *\n";
	cout << "*                                               *\n";
	cout << "*  Are you up for the challenge, my friend?     *\n";
    cout << "*                                               *\n";
	cout << "*  1.  Play                                     *\n";
	cout << "*  2.  Quit                                     *\n";
    cout << "*                                               *\n";
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";

}