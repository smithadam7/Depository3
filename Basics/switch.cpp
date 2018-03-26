
//#include "stdafx.h"

// This program illustrates the use of the Switch statement. 
// Adam Smith
#include <iostream>
using namespace std;
int main() 
{
	char grade;

	cout << "What grade did you earn in Programming I ?" << endl; 
	cin >> grade;
	if (grade == 'A')
		cout << "an A - excellent work !" << endl;
	else if (grade == 'B')
		cout << "you got a B - good job" << endl;
	else if (grade == 'C')
		cout << "earning a C is satisfactory" << endl;
	else if (grade =='D')
		cout << "while  D is passing, there is a problem" << endl;
	else if (grade == 'F')
		cout << "you failed - better luck next time" << endl;
	else 
		cout << "You did not enter an A, B, C, D, or F" << endl;

	//system("pause");
	return 0;
}
//Excercise 1: Removing break makes the program go through all the cases
