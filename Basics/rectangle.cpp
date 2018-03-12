// This program will output the rectangle area and perimeter 
// Adam Smith
#include <iostream> 
#include "stdafx.h"
#include <string>
#include <cmath>
using namespace std;
const int length = 8;
const int width = 3;
int main()
{
	float area;	// definition of area of rectangle
	float perimeter;   // definition of perimeter of rectangle

	area = length * width; // computes area
	perimeter = length + length + width + width; // computes perimeter
	cout << "The area of the rectangle is " << area << endl;
	cout << "The perimeter of the rectangle is " << perimeter << endl;
	system("pause");
	return 0;
}
