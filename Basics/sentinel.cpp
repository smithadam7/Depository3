// This program illustrates the use of a sentinel in a while loop. 
// The user is asked for monthly rainfall totals until a sentinel 
// value of -1 is entered. Then the total rainfall is displayed
// Adam Smith
#include <iostream>
#include "stdafx.h"
using namespace std;
int main() {
	// Fill in the code to define and initialize to 1 the variable month 
	float month = 1;
	float total = 0, rain;
	cout << "Enter the total rainfall for month " << month << endl;
	cout << "Enter -1 when you are finished" << endl; 
	// Fill in the code to read in the value for rain
	cin >> rain;
	// Fill in the code to start a while loop that iterates 
	// while rain does not equal -1 
	while (rain != -1)
	{ 
	// Fill in the code to update total by adding it to rain
		total = total + rain;
// Fill in the code to increment month by one
		month += 1;
	cout << "Enter the total rainfall in inches for month " << month << endl;
	cout << "Enter -1 when you are finished" << endl;
	// Fill in the code to read in the value for rain
	cin >> rain;
}
if (month == 1) 
cout << "No data has been entered" << endl;
// The purpose of this is to cout when the user doesn't input data
else cout << "The total rainfall for the " << month - 1 << " months is " << total << " inches." << endl;
system("pause");
return 0;
}
//Excercise 5: My results are correct. When you input -1 the program it says no data has been entered.
// Negative data numbers should not be input
//Excercise 6: The purpose of the code is to tell the user when they did not enter data when the month is 1.