//
//  guess.cpp
//  hangman
//
//  Created by Nashir Janmohamed on 3/13/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include "guess.h"
#include "globals.h"
#include "draw.h"
#include <iostream>
using namespace std;

bool guess(string answer, char temp, size_t length)
{
    //take users input and compare it to string
    bool guess = false;//starts out false, assuming no match
    
    for (int i = 0; i < length; i++)
    {
        if (temp == answer[i])
            guess = true; //match found
    }
    
    return guess;
}

void update_word(char guess, size_t length, string answer, char* user_word)
{
    /*
     *  create an array that stores all entered values and checks entered
     *  value to see if it has been guessed yet
     */
    
    
    //compare strings and update user guess
    for (int i = 0; i < length; i++)
    {
        if(answer[i] == guess)
            user_word[i] = answer[i];
    }
}


char difficulty(int &chances){
    //prompt user for input
    cout << "welcome to hangman!!" << endl;
    
    cout << "would you like to play on [e]asy or [h]ard mode? ";
    
    //user inputted value that determines number of chances to guess word
    char mode = getchar();
    cin.ignore(1000, '\n');
    
    if (isupper(mode))
        mode = tolower(mode);
    
    while (mode != 'h' && mode != 'e')
    {
        cout << "choose either [h] (hard) or [e] (easy): ";
        mode = getchar();
        cin.ignore(1000, '\n');
    }
    if (mode == 'h')
    {
        printf("you selected hard mode!\n");
        chances = HARD;
    }
    if (mode == 'e')
    {
        printf("you selected easy mode!\n");
        chances = EASY;
    }
    
    drawLine();
    //ask professor Nguyen about this, should print, then sleep, then print, etc...
    
    return mode;
}

bool alreadyGuessed(char user_in){
    static bool guessed[26] = {0};
    if (guessed[user_in - 97] == false){
        guessed[user_in - 97] = true;
        return false;
    }
    else
        return true;
}

char getInput(string answer){
    string user_in;
    char guess;
    getline(cin, user_in);
    
    if (user_in == answer){
        cout << "you won!! the word was " << answer << endl;
        cout << "thanks for playing!" << endl;
        exit(0);
    }
    
    while (user_in.length() == 0 || user_in.length() > 1){
        cout << "please input a single letter (i.e. 'a'): ";
        getline(cin, user_in);
        if (user_in == answer){
            cout << "you won!! the word was " << answer << endl;
            cout << "thanks for playing!" << endl;
            exit(0);
        }
    }
    
    if (isupper(user_in[0]))
        guess = tolower(user_in[0]);
    else
        guess = user_in[0];
    
    //if user inputs a char that they have already guessed, go to next iteration of loop
    if (alreadyGuessed(guess)){
        cout << "you have already guessed that letter..." << endl;
        return 0;
    }
    else
        return guess;
}
