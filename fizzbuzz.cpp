//
//  main.cpp
//  fizz buzz
//
//  Created by Nashir Janmohamed on 7/18/16.
//  Copyright © 2016 Nashty. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    //Write a program that prints the numbers from 1 to 100. But for multiples of three print "Fizz" instead
    //of the number and for the multiples of five print "Buzz". For numbers which are multiples of both three
    //and five print "FizzBuzz".
    
    for (int x = 1; x<=100; x++)
    {
        if (((x % 3) == 0) && ((x % 5) == 0))
        {
            cout << "fizzbuzz" << endl;
        }
        else if ((x % 3) == 0)
        {
            cout << "fizz" << endl;
        }
        else if ((x % 5) == 0)
        {
            cout << "buzz" << endl;
        }
        else
            cout << x << endl;
    }
    
    return 0;
}
