#include "stdafx.h"
//  This program has the user input a number n and then finds the 
//  mean of the first n positive integers
// Adam Smith
#include <iostream>
using namespace std;
int main() {
	int value;       // value is some positive number n
	int endValue; // This is the ending value to compute the mean in between n and m
	int total = 0;   // total holds the sum of the first n positive numbers    
	int number;      // the amount of numbers   
	float mean;      // the average of the first n positive numbers
	cout << "Please enter a positive starting integer" << endl;
	cin >> value;
	if (value > 0) {
		for (number = 1; number <= value; number++) 
		{ total = total + number; } 
		// curly braces are optional since there is only one statement
		mean = static_cast <float>(total) / value;         // note the use of the typecast    
											 // operator here
		cout << "The mean average of the first " << value << " positive integers is " << mean << endl;
	}
	else         cout << "Invalid input - integer must be positive" << endl;
	system("pause");
	return 0;
}
// Excercise 1: When the code was removed it didnt change the program because mean needs to be defined
//Excercise 2: When I input 2.99 it gave the mean of 1.5 because it rounded from 2.99 to 2
