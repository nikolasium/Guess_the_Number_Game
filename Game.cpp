// Author Nikolas Beier

#include <iostream>
#include <iomanip>
#include "Game.h"

using namespace std;

// Game launcher loads the selected game mode
void game_launcher()
{
    int game_selection;
    cout << "**Main menu**\n";
    cout << "Please select a game mode: computer guesses(enter 1) or user guesses(enter 2)\n";
    cin >> game_selection;
    while (cin.fail())
    {
        cout << "Please enter a number(1/2)!\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> game_selection;
    }
    switch (game_selection)
    {
    case 1:
        cout << "Game mode 1 selected!\n\n";
        game_mode_1();
        break;
    case 2:
        cout << "Game mode 2 selected!\n\n";
        game_mode_2();
        break;
    }
}


/**
 *
 * @param upper_limit corresponds to maximum value for the search range
 * @return returns the maximum value read in
 */

int read_max(int upper_limit)
{
    int max = 0;
    while (max < 2 || max > upper_limit) 
    {
        cout << "Enter the range of numbers to search for (min:2 max:" << upper_limit << ")" << endl;
        cin >> max;
        if (max > upper_limit)
        {
            cout << "Please enter a number until " << upper_limit << endl;
        }
        else if (max < 2) 
        {
            cout << "Please enter a number greater than 1!\n";
        }
    }

    return max;
}

/**
 *
 * @param n Stores number of search queries
 * @param m saves current middle of the search value
 * @return returns the answer
 */

int read_answer(int n, int m)
{
	char answer = 'x';
	while (tolower(answer) != 'y' && tolower(answer) != 'n')
	{
		cout << "Q" << n << ": " << "Is the imagined number less than or equal to " << m << "? (y/n)" << endl;
		cin >> answer;
	}
	return answer;
}

/*
* ------
*/

/**
 *
 * @param upper_limit stores value of upper limit of selected search area
 * @param lower_bound stores value of lower bound of selected search area
 * @return returns the selected search area
 */

int read_search_area(int upper_limit, int lower_bound)
{
    int search_area = 0;
    while (search_area > upper_limit || search_area < lower_bound)
    {
        cout << "How large should the search range be? (max:" << upper_limit << " /min:" << lower_bound << ")" << endl;
        cin >> search_area;
        if (search_area > upper_limit)
        {
            cout << "Please do not enter numbers above " << upper_limit << endl;
        }
        else if (lower_bound > search_area)
        {
            cout << "Please do not enter numbers below " << lower_bound << endl;
        }

    }

    return search_area;
}


/**
 *
 * @param thought_number stores value of random created number, which the user has to guess for
 * @return returns the number of attempts
 */

int read_attempt(int thought_number)
{
    int attempt = 0;
    int number_attempts = 0;

    while (attempt != thought_number)
    {
        number_attempts++;
        cout << "Please enter your number for guess: " << "(Attempt: " << number_attempts << ")" << endl;
        cin >> attempt;
        if (attempt != thought_number) {
            cout << "Unfortunately wrong! Please try again!\n";
        }
        if (attempt > thought_number) {
            cout << "Hint: The imaginary number is smaller than " << attempt << endl;
        }
        if (attempt < thought_number) {
            cout << "Hint: The imaginary number is greater than " << attempt << endl;
        }

    }

    return number_attempts;
}

// Game mode 1 - Computer has to guess for a number
int game_mode_1() 
{
    const int upper_limit = 100;
    int max = read_max(upper_limit);
    int min = 1;
    int counter = 0;
    while (min != max) 
    {
        int center = min + (max - min) / 2;
        counter++;
        char answer = read_answer(counter, center);
        if (tolower(answer) == 'y') 
        {
            max = center;
        }
        else 
        {
            min = center + 1;
        }
    }
    cout << "The imagined number is: " << max << "\n";

    return 0;
}

// Game mode 2 - User has to guess for a number
int game_mode_2()
{
    srand(clock());
    const int upper_limit = 100;
    const int lower_bound = 2;

    int search_area = read_search_area(upper_limit, lower_bound);
    int thought_number = (rand() % search_area) + 1;
    int number_attempts = read_attempt(thought_number);

    cout << "Right!! The imaginary number was: " << thought_number << endl << "Attempts: " << number_attempts << endl;

    return 0;
}