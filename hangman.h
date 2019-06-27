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
        string playerWord;
        bool isGameOver;
        string getSecretWord() { return secretWord; }
        string getPlayerWord() { return playerWord; }
        bool searchString(char c);

    public:
        Hangman(string words, int numWords);
        string readRandomWordFromFile(string filename, int numWords);
        void displayMenu();
        void play();
        
};

#endif