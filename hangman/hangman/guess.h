//
//  guess.h
//  hangman
//
//  Created by Nashir Janmohamed on 3/13/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#ifndef guess_h
#define guess_h

#include <iostream>
#include <string>

bool guess(std::string answer, char temp, size_t length);
void update_word(char guess, size_t length, std::string answer, char *user_word);
bool alreadyGuessed(char user_in);

char difficulty(int &chances);
char getInput(std::string answer);

#endif /* guess_h */
