// Adam Smith
// PA2
// Bookstore Managing
// Last Modified 10-22-16
// Built and ran successfully on Visual Studio
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>// for writing and reading information to and from a file 
#include "smith.h"
using namespace std;

int main()
{
	const int MAX_SIZE = 100;
	int size = 0;
	struct Books booksArray[MAX_SIZE];

	do//This will be the menu for the bookstore management
	{
		cout << "Please Choose an Option\n"
			<< endl << "1: Read inventory from file\n2: Add an entry\n3: Delete an entry\n4: Update an entry\n5: Sort inventory\n6: Write inventory to file and exit\n";
		cin >> userOption;
		if (userOption == 1)// Reads the inventory from the inventory.txt file
		{
			invRead(booksArray,size);
		}
		else if (userOption == 2)//adds an entry
		{
			
			invAdd(booksArray, size, MAX_SIZE);
			// cin from the user ISBN, Title, Author, Publisher, Quantity, and price into a struct
			// check to see if it can hold one more entry
			// else cout error message
		}
		else if (userOption == 3)// Delete an entry
		{
			invDelete(booksArray,size);
			//rearanges indexes to be higher than the one to be deleted and decrement size by one
		}
		else if (userOption == 4)// update inventory
		{
			invUpdate(booksArray,size);
			// change quantity by incrementing or decrementing
			//cin new number of books
		}
		else if (userOption == 5)// to sort by title: compare first and second array if second
			//is greater, then swap. Do this for the 3rd and so on until there are no more
		{
			invSort(booksArray,size);
		}
		else if (userOption == 6)//Write inventory out to inventory.txt
		{
			invWrite(booksArray,size);
			break;// exits the program
		}
		else
		{
			cout << userOption << " is not a valid option\n";// if the user puts a different number
		}
	} while (true);// For the menu

	system("pause");
    return 0;
}
