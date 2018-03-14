//
//  main.cpp
//  hangman
//
//  Created by Nashir Janmohamed on 3/12/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//


#include "globals.h"
#include "draw.h"
#include "guess.h"

#include <iostream>
#include <string>
using namespace std;


int main()
{
    //pick word for user to guess
    string word = randomWord();
    
    //define an empty char array to be filled/compared to word
    size_t len = word.length();
    char user_word[len+1];
    for (int i = 0; i < len; i++)
    {
        user_word[i] = '_';
    }
    user_word[len] = '\0';
    
    //set difficulty
    int chances;
    char mode = difficulty(chances);
    
    draw(chances, user_word, mode);
    
    char user_in = 0;
    
    while (chances > 0)
    {
        cout << "guess a single letter: ";
        user_in = getInput(word);
        if (user_in == 0) //if user inputs a letter that they have already guessed
            continue;
        
        if (guess(word, user_in, len) == false)
            chances--;
        else
            update_word(user_in, len, word, user_word);
        
        bool areWordsEqual = true;
        for (int i = 0; i < len; i++){
            if (user_word[i] != word[i]){
                areWordsEqual = false;
                break;
            }
            else
                continue;
        }
        if (areWordsEqual){
            cout << "you won!! the word was " << word << endl;
            cout << "thanks for playing!" << endl;
            return 0;
        }
        else
            draw(chances, user_word, mode);
    }
    
    cout << "you lost... the word was " << word << "..." << endl;
    cout << "thanks for playing!" << endl;
    return 0;
}

