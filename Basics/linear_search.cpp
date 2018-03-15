#include "stdafx.h"
// This program performs a linear search on a character array
// Adam Smith
#include<iostream>
using namespace std;
int searchList(int[], int, int); // function prototype
const int SIZE = 8;
int main() {
	int nums[SIZE] = {3, 6, -19, 5,5,0,-2,99};
	int found;
	int ch;
	do {
		cout << "Enter a number to search for: and -1 to stop" << endl;
		cin >> ch;
		found = searchList(nums, SIZE, ch);
		if (found == -1)
			cout << "The number " << ch << " was not found in the list" << endl;
		else
			cout << "The letter " << ch << " is in the " << found + 1 << " position of the list" << endl;
		
	} while (ch != -1);
	return 0;
}
//******************************************************************* 
//                      searchList 
// // task:       This searches an array for a particular value
// data in:       List of values in an array, the number of 
//                elements in the array, and the value searched for 
//                in the array 
// data returned: Position in the array of the value or -1 if value 
//                not found //
//*******************************************************************
int searchList(int List[], int numElems, int value)
{
	for (int count = 0; count <= numElems; count++) 
	{
		if (List[count] == value)
			// each array entry is checked to see if it contains
			// the desired value.
			return count;
		// if the desired value is found, the array subscript
		// count is returned to indicate the location in the array
	}
	return -1;      // if the value is not found, -1 is returned
}
// Excercise 1: entering 5 results in it saying it found it in position 4
// Excercise 2: I used a post test loop for it to loop until -1 is input