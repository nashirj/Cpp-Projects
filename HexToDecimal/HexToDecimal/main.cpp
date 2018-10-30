//
//  main.cpp
//  HexToDecimal
//
//  Created by Nashir Janmohamed on 2/24/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
using namespace std;

int hexToDec(std::string hexString)
{
    int dec = 0;
    
    int count = hexString.length() - 1, i = 0;
    while (count >= 0)
    {
        int powerSixt = 1;
        for (int j = 1; j < i+1; j++)
        {
            powerSixt *= 16;
            //cout << "powerSixt is: " << powerSixt << endl;
        }
        
        //handle negative hex values
        if (count == 0 && hexString[0] == '-')
        {
            return dec *= -1;
        }
        
        //convert hexString to int and add to dec
        int tempDec = 0;
        if (hexString[count] >= '0' && hexString[count] <= '9')
        {
            tempDec = (hexString[count] - 48);
        }
        else if (hexString[count] >= 'A' && hexString[count] <= 'F')
        {
            tempDec = (hexString[count] - 55);
        }
        else if (hexString[count] >= 'a' && hexString[count] <= 'f')
        {
            tempDec = (hexString[count] - 87);
        }
        
        dec += tempDec * powerSixt;
        
        //increment
        i++;
        count--;
    }
    
    return dec;
    
}

int main(int argc, const char * argv[]) {
    
    cout << hexToDec("-C") << endl;
    return 0;
}
