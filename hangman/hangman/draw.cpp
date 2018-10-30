//
//  draw.cpp
//  hangman
//
//  Created by Nashir Janmohamed on 3/12/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include "draw.h"
#include "globals.h"
#include <string>
#include <iostream>
using namespace std;


void draw(int chances, char* user_word, char mode)
{
    clearScreen();
    
    update(chances, mode);
    
    for (int i = 0; i < 7; i++)
        cout << grid[i] << endl;
    
    cout << "you have " << chances << " chances left" << endl;
    cout << "the word is: " << user_word << endl;
    cout << endl;
    
}


void drawLine(){
    //line drawing animation
    for (int i = 0; i < 20; i++)
    {
        cout << "-";
        fflush(stdout);
        sleeper(70);
    }
    cout << endl;
}

void update(int chances, char mode){
    if (mode == 'h'){
        switch(chances)
        {
            case 5:
                grid[2] = " |    O  ";
                break;
            case 4:
                grid[3] = " |    |  ";
                break;
            case 3:
                grid[3] = " |   -|  ";
                break;
            case 2:
                grid[3] = " |   -|- ";
                break;
            case 1:
                grid[4] = " |   /   ";
                break;
            case 0:
                grid[4] = " |   / \\ ";
                break;
        }
    }
    //else if (mode == 'e')
    else{
        switch(chances)
        {
            case 9:
                grid[2] = " |    O  ";
                break;
            case 8:
                grid[3] = " |    |  ";
                break;
            case 7:
                grid[3] = " |   -|  ";
                break;
            case 6:
                grid[3] = " |  --|  ";
                break;
            case 5:
                grid[3] = " |  --|- ";
                break;
            case 4:
                grid[3] = " |  --|--";
                break;
            case 3:
                grid[4] = " |   /   ";
                break;
            case 2:
                grid[5] = " |  /    ";
                break;
            case 1:
                grid[4] = " |   / \\ ";
                break;
            case 0:
                grid[5] = " |  /   \\";
                break;
        }
    }
}
