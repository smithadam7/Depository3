//Adam Smith
#include "SetFunctions.h"
#include "ArrayBag.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
void readIn(ArrayBag &bag1, ArrayBag &bag2) {
	ifstream infile("setInput.txt");//opens the file that contains integers
	int tempInt;
	stringstream ss;
	stringstream dd;
	string instring;
	string instring2;
	getline(infile, instring);
	ss << instring;
	while (!ss.eof()) //Until end of stream
		{
			ss >> tempInt; //Read in an int from ss into tempInt 
			if (ss.fail()) { //If it fails to to read an int data type 
				cout << "Input contains non-integer data\n";
				ss.clear();
			}bag1.add(tempInt);// add to array
	}
	getline(infile, instring2);
	dd << instring2;
	//cout << instring2; testing
	while (!dd.eof()) //Until end of stream
	{
		dd >> tempInt; //Read in an int from dd into tempInt 
		if (dd.fail()) { //If it fails to to read an int data type 
			cout << "Input contains non-integer data\n";
			dd.clear();
		}bag2.add(tempInt);// add to array
	}
	infile.close();// closes file
};

// Prints out bag1 and bag2
void printArray(ArrayBag &bag1, ArrayBag &bag2) {
	//for (int i = (bag1.getCurrentSize()) - 1; i >= 0; i--)
	cout << "These are the contents of bag 1: ";
	int i = bag1.getCurrentSize();
		bag1.getIndexOut(i);
		cout << endl <<"These are the contents of bag 2: ";
  int k = bag2.getCurrentSize();
		bag2.getIndexOut(k);
		cout << endl;
};

//Prints the Union 
void printBag3(ArrayBag &bag3) {
	cout << "This is the Union of bag 1 and 2: ";
	int i = bag3.getCurrentSize();
	bag3.getIndexOut(i);
	cout << endl;
};

//Prints the Difference
void printBag4(ArrayBag &bag4) {
	cout << "This is the Difference of bag 1 and 2: ";
	int i = bag4.getCurrentSize();
	bag4.getIndexOut(i);
};