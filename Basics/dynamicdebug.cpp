#include "stdafx.h"
// This program demonstrates the use of dynamic variables with debugging
// Adam Smith
#include <iostream> 
using namespace std;
const int MAXNAME = 10;
#define _DEBUGPRINT
#ifdef _DEBUGPRINT
#define _DPRINT(x) cout << x << endl;
#else 
#define _DPRINT(x)
#endif
int main() {
	int pos;
	char * name;
	int *one;
	int *two;
	int *three;
	int result;
	//  Fill in code to allocate the integer variable one here 
	one = new int;
	//  Fill in code to allocate the integer variable two here
	two = new int;
	//  Fill in code to allocate the integer variable three here 
	three = new int;
	//  Fill in code to allocate the character array pointed by name
	name = new char[MAXNAME];
	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
		<< "Blanks at the end do not count." << endl;
	for (pos = 0; pos < MAXNAME; pos++)
		cin >> name[pos];
	// The name pointer is a dynamic array becuase this allows the addresses to change
	cout << "Hi ";
	for (pos = 0; pos < MAXNAME; pos++)
		cout << name[pos];
	cout << endl << "Enter three integer numbers separated by blanks" << endl;
	// Fill in code to input three numbers and store them in the
	cin >> *one;
	cin >> *two;
	cin >> *three;

	_DPRINT(*one);// Value of one
	_DPRINT(one);// addrress of one it is a pointer
	_DPRINT(*two);// Value of two
	_DPRINT(two);// addrress of two
	_DPRINT(*three);// Value of three
	_DPRINT(three);// addrress of three 
	//These were all the same values as those displayed by the debugger tool
	cout << "The three numbers are " << *one << " " << *two << " " << *three << endl;
	result = *one + *two + *three;  
	cout << "The sum of the three values is " << result << endl;
	delete one;
	delete two;
	delete three;
	delete[] name;
	//getchar();this didnt work
	system("pause");
	return 0;
}