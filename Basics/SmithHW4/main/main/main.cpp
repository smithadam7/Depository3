// Adam Smith
// My Vector HW4
// Last Modified 02-13-17
// Built and ran successfully on Visual Studio
#include <iostream>
#include <string>
#include "MyVector.h"
using namespace std;
using namespace HW4;

int main()
{
	//Creates Vector called vector1
	MyVector vector1;
	//Populates Vector
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(3);
	vector1.push_back(9);
	vector1.push_back(5);
	vector1.push_back(7);
	vector1.push_back(8);
	vector1.push_back(9);
	cout << "This is the contents of the vector: ";
	//Displays contents of vector
	vector1.display();
	cout << endl;
	cout << "This is the contents of the vector after pop_back: ";
	//Deletes last item in vector
	vector1.pop_back();
	vector1.display();
	cout << endl << "Enter a number to search for: ";
	T search;
	cin >> search;
	//Searches vector for the user input
	vector1.search(search);

	cout << "Goodbye! Press enter key to continue";
	cin.ignore();
	string hold;
	getline(cin, hold);
    return 0;
}

