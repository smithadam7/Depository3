// 4.5 Option 1
// Adam Smith

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
float bill1, bill2, bill3, bill4,avg;

int main()
{
	//Getting input from the user for the 4 quarters
	cout << "Please input your water bill for quarter 1: " << endl;
	cin >> bill1;
	cout << "Please input your water bill for quarter 2: " << endl;
	cin >> bill2;
	cout << "Please input your water bill for quarter 3: " << endl;
	cin >> bill3;
	cout << "Please input your water bill for quarter 4: " << endl;
	cin >> bill4; 
	cout << endl;

	//Computing the monthly average with 2 numbers after the decimal
	cout << setprecision(2) << fixed << showpoint;
	avg = (bill1 + bill2 + bill3 + bill4) / 12;
	
	cout << "Your monthly average bill is $" << avg << ". ";

	//If/else  tells what to do when the avg is within a certain range
	if (avg > 75)
		cout << "You are using excessive amounts of water " << endl;
	else if (avg <= 75 && avg >= 25)
		cout << "You are using a typical amount of water\n";
	else if (avg < 25)
		cout << "Thank you for using very little water!\n";



	//system("pause");
    return 0;
}

