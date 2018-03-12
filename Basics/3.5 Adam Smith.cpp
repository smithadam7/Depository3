// 3.5 Adam Smith
// Option 1

//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip> // This is for using setprecicion in order to set
//the answer to only 2 numbers past the decimal
using namespace std;
// Defined Variables
float grade1;
float grade2;
float grade3;
float gradeAvg;


int main()
{
	cout << "Please input the first grade\n"; // Asks the user for first grade
	cin >> grade1; // User inputs first number
	cout << "Please input the second grade\n";
	cin >> grade2;// User inputs second number
	cout << "Please input the third grade\n";
	cin >> grade3;// User inputs the third number
	cout << setprecision(2) << fixed << showpoint; // Makes the answer have 2 numbers past the decimal
	gradeAvg = (grade1 + grade2 + grade3) / 3;// This calcualtes the average of the 3 numbers
	cout << "The average of the three grades is " << gradeAvg << endl;
	//system("pause");
    return 0;
}

