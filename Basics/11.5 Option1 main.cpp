#include "stdafx.h"
#include <iostream>
#include <cmath> 
// necessary for pow function 
#include <iomanip>
using namespace std;

struct circle // declares the structure circle 
{  // This structure has 6 members
	float centerX; // x coordinate of center 
	float centerY; // y coordinate of center 
	float radius;
	float area;
	float circumference;
	float distance_from_origin;
};
	const float PI = 3.14159;

int main() {
	int count;
	circle array[6]; // defines 2 circle structure variables
	for (count = 0; count < 5; count++) {
		cout << "Please enter the radius of the " << (count+1)<< " circle: ";
		cin >> array[count].radius;
		cout << endl << "Please enter the x-coordinate of the center: ";
		cin >> array[count].centerX;
		cout << endl << "Please enter the y-coordinate of the center: ";
		cin >> array[count].centerY;
		array[count].area = PI * pow(array[count].radius, 2.0);
		array[count].circumference = 2 * PI * array[count].radius;
		array[count].distance_from_origin = sqrt(pow(array[count].centerX, 2.0) + pow(array[count].centerY, 2.0));
		cout << endl << endl;
		cout << setprecision(2) << fixed << showpoint;
		cout << "The area of the "<<(count + 1)<<" circle is : ";
		cout << array[count].area << endl;
		cout << "The circumference of the" << (count +1) <<" circle is: ";
		cout << array[count].circumference << endl << endl;

		if (array[count].distance_from_origin < array[0].distance_from_origin) 
		{
			array[0].distance_from_origin = array[count].distance_from_origin;
		}
		
	}
	cout << "The closest circle to the origin is circle " << array[0].distance_from_origin << endl;
	// This next section determines which circle's center is // closer to the origin
	int hold;
	cin >> hold;
	return 0;

}