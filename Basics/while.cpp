// Adam Smith
#include <iostream> 
#include "stdafx.h"
using namespace std;
int main() {
	char letter = 'a';
	do 
	{
		cout << "Please enter a letter except for x" << endl;            
		cin >> letter;            
		cout << "The letter you entered is " << letter << endl;
		
	} while (letter != 'x');
	return 0;
}
//Excercise 1: This program is not user friendly because it closes
//if x is entered and it doesn't explain why or what happened
//Excercise 3: The program does the while statement first intead of last
