// Adam Smith
// PA1 Game of Life
// Build and ran successfully on visual studios
// Last Modified 2/1/17
#include <string>
#include <iostream>
#include "GameOfLife.h"
using namespace std;
using namespace csci2312;
int main()
{
	/*
	This game was designed to run based off of a seed number from the text file
	The game will only change when the seed is changed
	*/
	int numberOfIterations;
	char myArray[32][32];
	cout << "Welcome to the game of life, enter the number of iterations: ";
	//Amount of games states that will be shown
	cin >> numberOfIterations;
	//Runs the game
	GameOfLife().run(numberOfIterations,myArray);
	//Used for testing
	/*int myarray[30][30];
	int n = 0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++) {
			//n=1;
			myarray[i][j] =0;
			cout << myarray[i][j] << " ";
		}*/
	cout << "Press enter key to continue";
	cin.ignore();
	string hold;
	getline(cin, hold);
    return 0;
}

/* Notes:
Declare:
int * intPtr = NULL; use nullptr in c++11 instead OF null
int value =0;
Using:
intPtr is a pointer
* intPtr is a value
value is a value
&value is a reference(implemented as a pointer)
Dereference
*(intPtr).thing1 if not you are dereferening the entire statement
intPtr->thing1 usual way of writing
in c++11 use nullptr
never set pointer to 0
*/