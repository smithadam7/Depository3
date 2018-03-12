// This program will output the circumference and area 
// of the circle with a given radius.
// Adam Smith

#include <iostream> 
//#include "stdafx.h"
#include <string>
#include <cmath>
using namespace std;
const float PI = 3.14;
const float RADIUS = 5.4;
int main()
{
	// definition of area of circle float circumference; 
	float area;
	// definition of circumference circumference = 2 * PI * RADIUS; 
	float circumference;
	// computes circumference area =  ; 
	circumference = 2 * PI * RADIUS;
	// computes area 
	area = PI * pow(RADIUS,2);
	// Fill in the code for the cout statement that will output (with description)
	// the circumference
	cout << "The circumference of the circle is " << circumference << endl;
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
	cout << "The area of the circle is " << area << endl;
	//system("pause");
	return 0;

	/* when changing it to int the answer becomes
	The Circumference of the circle is : 30
	The area of the circle is : 75

	*/
}