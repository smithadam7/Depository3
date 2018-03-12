// Adam Smith
#include "stdafx.h"
#include <iostream> 
#include <iomanip> 
using namespace std;
//Function prototypes 
void printDescription();
void computeMPH(float, int, float&);
int hold;
int main()
{
	float miles; float hours; float milesperHour;
	cout << setprecision(2) << fixed;
	cout << "Welcome to the MPH Program" << endl;
	printDescription(); //Call to Description function
	cout << "Please input the miles traveled" << endl;
	cin >> miles;
	cout << "Please input the hours traveled" << endl;
	cin >> hours;
	cout << endl << endl;
	computeMPH(miles, hours, milesperHour);
	//  Fill in the code to output grosspay 
	milesperHour = miles / hours;
	
	cout << "Your speed is " << milesperHour << " miles per hour" << endl;

	cin >> hold;
	return 0;
}

	void printDescription() //The function heading 
	{

		cout << "************************************************" << endl << endl;
		cout << "This program takes two numbers (miles & hours)" << endl;
		cout << "and  finds MPH" << endl;
		cout << "************************************************" << endl << endl;
	}
	void computeMPH(float rate, int time, float& gross) {
		//  Fill in the code to find grosspay and net pay

	}