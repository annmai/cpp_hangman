#include "hangman.h"
#include <fstream>
#include <iostream>
#include <time.h>

Hangman::Hangman(string words, int numWords) {
    isGameOver = false;
    numGuessesLeft = MAX_GUESSES;
    secretWord = readRandomWordFromFile(words, numWords);
    playerWord = secretWord;

    for(int i = 0; i < secretWord.length() - 1; ++i)
        playerWord[i] = '-';
}

string Hangman::readRandomWordFromFile(string filename, int numWords) {

    ifstream wordsFile(filename);

    // seed random with time
    srand(time(0));

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

void Hangman::play() {

    while(numGuessesLeft > 0 && !isGameOver) {

        char guess;

        displayHangedMan(numGuessesLeft);

        cout << "The word looks like this: ";
        cout << playerWord << endl;
        cout << "You have " << numGuessesLeft << " guesses left.\n";
        cout << "Enter your guess: ";
        cin >> guess;

        if(searchString(guess)) {
            cout << "Your guess is correct.\n";
            if(secretWord.compare(playerWord) == 0) {
                cout << "You win!\n";
                isGameOver = true;
                cout << "The word was " << playerWord << endl;
            }
        }
            
        else {
            cout << "Sorry, there is no " << guess << " in the word.\n";
            numGuessesLeft--;
            if(numGuessesLeft == 0) {
                isGameOver = true;
                displayHangedMan(0);
                cout << "You lose!\n";
            }
                
        }

    }
}

bool Hangman::searchString(char c) {

    for(int i = 0; i < secretWord.length() - 1; ++i) {
        if(secretWord[i] == c && playerWord[i] != c) {
            playerWord[i] = tolower(c);
            return true;
        }
    }

    return false;
}

void Hangman::displayHangedMan(int guessesLeft) {

    switch(guessesLeft) {

        case 8:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                |                     *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 7:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 6:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |                 |                    *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 5:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|                    *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 4:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|----<               *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 3:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|----<               *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                /                     *\n";
            cout << "*        |               /                      *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 2:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|----<               *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                / \\                  *\n";
            cout << "*        |               /   \\                 *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 1:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|----<               *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                / \\                  *\n";
            cout << "*        |             __/   \\                 *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        case 0:

            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                               *\n";
	        cout << "*        ------------------                     *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                ( )                   *\n";
            cout << "*        |            >----|----<               *\n";
	        cout << "*        |                 |                    *\n";
	        cout << "*        |                / \\                  *\n";
            cout << "*        |             __/   \\__               *\n";
	        cout << "*        |                                      *\n";
            cout << "*        |                                      *\n";
            cout << "*   ------------                                *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
            break;

        default: break;

    }


}