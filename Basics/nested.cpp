#include "stdafx.h"

// This program finds the average time spent programming by a student 
// each day over a three day period.
// Adam Smith
#include <iostream>
using namespace std;
int main() {
	int numStudents;
	float numHours, total, average, total2, average2, bioHours;
	int student, day = 0;     // these are the counters for the loops
	cout << "This program will find the average number of hours a day" << " that a student spent programming over a long weekend\n\n";
	cout << "How many students are there ?" << endl << endl;
	cin >> numStudents; 
	for (student = 1; student <= numStudents; student++) {
		total = 0, total2 = 0; for (day = 1; day <= 3; day++) {
			cout << "Please enter the number of hours spent programming by student " << student << " on day " << day << "." << endl;
			cin >> numHours;  
			cout << "Please enter the number of hours spent studying biology by student " << student << " on day " << day << "." << endl;
			cin >> bioHours;
			total = total + numHours;
			total2 = total2 + bioHours;
		}         average = total / 3;
		average2 = total2 / 3;
		
		cout << endl;
		cout << "The average number of hours per day spent programming by " << "student " << student << " is " << average
			<< endl << endl << endl;
		if (average < average2)
			cout << "The student spent more time studying biology than programming. \n";
		else
			cout << "The student spent more time programming than studying biology. \n";
	}
	system("pause");
	return 0;
}
