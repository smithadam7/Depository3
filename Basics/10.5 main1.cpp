// Adam Smith
// Lab 10.5 Main
// Palindromes
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main()
{
	char last[25];
	int length, count = 0;
	char first[25];
	int hold;

	cout << "Enter name\n";
	cin.getline(last, 25);
	cout << "Enter second name\n";
	cin.getline(first, 25);
	cout << "The names in alphabetical order are ";
	if (strcmp(last, first) == -1) {
		cout << last <<endl << first<< endl;
	}
	else if (strcmp(last, first) == 1) {
		cout << first <<endl << last<< endl;
	}
	else {
		cout << first <<endl << last<< endl;
	}
	cin >> hold;
	return 0;

}
