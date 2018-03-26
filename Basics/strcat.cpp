// strcat.cpp 
// Adam Smith

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int hold;
	char string1[25] = "Total Eclipse ";
	char string2[11] = "of the Sun";
	cout << string1 << endl;
	cout << string2 << endl;
	strcat(string1, string2);
	cout << string1 << endl;
	cin >> hold;
    return 0;
}
//Excercise 2: When I changed string 1 to hold 20 instead of 25, 
//my computer froze when I tried to run it
