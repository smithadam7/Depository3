#include "stdafx.h"
// This program demonstrates the use of pointer variables 
// It finds the area of a rectangle given length and width 
// It prints the length and width in ascending order
// Adam Smith
#include <iostream>
using namespace std;
int main() {
	int length; 
	// holds length    
	int width; 
	// holds width    
	int area; 
	// holds area    
	int *lengthPtr; 
	// int pointer which will be set to point to length    
	int *widthPtr;   
	// int pointer which will be set to point to width
	cout << "Please input the length of the rectangle" << endl;
	cin >> length; 
	cout << "Please input the width of the rectangle" << endl;
	cin >> width;
	// Fill in code to make lengthPtr point to length (hold its address) 
	lengthPtr = &length;
	// Fill in code to make widthPtr point to width (hold its address)  
	widthPtr = &width;
	area = *widthPtr * *lengthPtr;// Fill in code to find the area by using only the pointer variables 
		cout << "The area is " << area << endl;
		if (// Fill in the condition of length > width by using only the pointer variables
			*lengthPtr > *widthPtr
			)     
			cout << "The length is greater than the width" << endl;
		else if (// Fill in the condition of width > length by using only the pointer// variables
			*widthPtr > *lengthPtr
			)
			cout << "The width is greater than the length" << endl;
		else     cout << "The width and length are the same" << endl;
		system("pause");
		return 0;
}
//Excercise2: The output was area = 150 and width is greater than length
