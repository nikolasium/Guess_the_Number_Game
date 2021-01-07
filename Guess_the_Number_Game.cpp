// Author Nikolas Beier

// Guess_the_Number_Game.cpp : This file contains function "main". Execution starts from here.
//

#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    char again;
    cout << "Hello and welcome to Guess the Number Game!\n\n";
    do{
    game_launcher();
    cout << "Would you like to play again? (y/n)\n\n";
    cin >> again;
    } while (tolower(again) == 'y');
    
    cout << "See you next time!\n";
    
    return 0;

}