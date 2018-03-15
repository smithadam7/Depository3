#include "stdafx.h"
// Adam Smith
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std; //function prototypes
int hold;

int main()
{
	char last[10];
	cout << "Enter a 9 character name " << endl;
	cin.getline(last, 10);
	cout << last;
	cout << " is your name" << endl;
	cin >> hold;
	return 0;
}

//Excercise 2: The program exits when I type newmanouskous
// Excercise 3: The program exits when I type newmanouskous