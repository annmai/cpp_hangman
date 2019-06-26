#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

using namespace std;

class Hangman {

    private:
        const int MAX_GUESSES = 8;
        int numGuessesLeft;
        string secretWord;
        string playerGuessedWord;
        bool isGameOver;

    public:
        Hangman(string words, int numWords);
        string readRandomWordFromFile(string filename, int numWords);
        void displayMenu();
        string getSecretWord() { return secretWord; }
};

#endif