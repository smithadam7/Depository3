#include "stdafx.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
void bubbleSortArray(int[], int);
void displayArray(int[], int);
const int SIZE=8;
int sizefromfile;
int searchNum;
int found;
float mean;
int values[SIZE];
int binarySearch(int[], int, int);
int main()
{
	ifstream dataIn; // defines an input stream for a data file
	dataIn.open("array.txt");
	while (!dataIn.eof())
	{
		dataIn >> sizefromfile;// Reads the const int size
		dataIn >> searchNum;// reads in the number that is to be searched for
		dataIn >> values[0];
		dataIn >> values[1];
		dataIn >> values[2];
		dataIn >> values[3];
		dataIn >> values[4];
		dataIn >> values[5];
		dataIn >> values[6];
		dataIn >> values[7];
	}
	dataIn.close();
	//int values[SIZE] = { 23,0,45,3,78,1,2,9 };// I put these numbers in the file
	cout << "The values before the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);
	bubbleSortArray(values, SIZE);
	cout << "The values after the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);
	//Calc Mean
	mean = 0;
	for (int x = 0; x < SIZE; x++)
	{
		mean += values[x];
	}
	mean = mean /SIZE;
	cout <<endl<<"The mean of the array is "<< mean<<endl;
	//Searches
	cout << "The number you are searching for is " << searchNum << endl;
	found = binarySearch(values, SIZE, searchNum);
	if (found == -1)
		cout << "The value " << searchNum << " is not in the list" << endl;
	else {
		cout << "The value " << searchNum << " is in position number " << found + 1 << " of the list" << endl;
	}
	// Writing array to file
	int i;
	ofstream outfile;
	outfile.open("arrayout.txt");
	for (i = 0; i < SIZE; i++)
	{
		outfile << values[i] << endl;
	}
	outfile.close();
	system("pause");
	return 0;
} //****************************************************************** 
  //                      displayArray 
  // // task: to print the array // data in:       the array to be printed, the array size 
  // data out:      none // 
  //******************************************************************
void displayArray(int array[], int elems)    // function heading 
{
	// displays the array
	for (int count = 0; count < elems; count++) cout << array[count] << "  " << endl;
}
//****************************************************************** 
//                      bubbleSortArray // 
// task: to sort values of an array in ascending order
// data in:       the array, the array size // data out:      the sorted array 
// //******************************************************************
void bubbleSortArray(int array[], int elems)
{
	bool swap;
	int temp;
	int bottom = elems - 1;     // bottom indicates the end part of the                            
								// array where the largest values have                             
								// settled in order
	do {
		swap = false;

		for (int count = 0; count < bottom; count++) {
			if (array[count] < array[count + 1])
			{           // the next three lines do a swap      
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true; // indicates that a swap occurs
							 //for (int count = 0; count < elems; count++) cout << array[count] << "  " << endl; Excercise 2 prints out each step in sort
			}
		}
		bottom--;     // bottom is decremented by 1 since each pass through                     
					  // the array adds one more value that is set in order
	} while (swap != false);
	// loop repeats until a pass through the array with
	// no swaps occur
}
int binarySearch(int array[], int SIZE, int searchNum) //function heading 
{
	int first = 0;
	// First element of list
	int last = SIZE - 1;     // last element of the list
	int middle;
	// variable containing the current
	// middle value of the list
	while (first <= last)
	{
		middle = first + (last - first) / 2;
		if (array[middle] == searchNum)
			return middle;        // if value is in the middle, we aredone
		else if (array[middle]<searchNum)
			last = middle - 1;    // toss out the second remaining half of
								  // the array and search the first
		else
			first = middle + 1;    // toss out the first remaininghalf of
								   // the array and search the second
	}
	return -1;
	// indicates that value is not in the array 
}