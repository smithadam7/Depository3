//Adam Smith
#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Books
{
	int ISBN;
	string Title;
	string Author;
	string Publisher;
	int Quantity;
	double Price;
};
void invRead(struct Books booksArray[], int &size);
void invAdd(struct Books booksArray[], int &size, int MAX_SIZE);
void invDelete(struct Books booksArray[], int &size);
void invUpdate(struct Books booksArray[], int &size);
void invSort(struct Books booksArray[], int &size);
void invWrite(struct Books booksArray[], int &size);
int userOption;


void invRead(struct Books booksArray[], int &size)
{
	ifstream infile;//opens the file to read
	infile.open("inventory.txt");
	int count = 0;
	cout << "Reading from the file:\n";
	while (!infile.eof())//reads until it is the end of the file
	{
		for (count = 0; count < 100 && (!infile.eof()); count++)
		{
			infile >> booksArray[count].ISBN; // read the text from inventory.txt
			infile.ignore();
			getline(infile, booksArray[count].Title);
			getline(infile, booksArray[count].Author);
			getline(infile, booksArray[count].Publisher);
			infile >> booksArray[count].Quantity;
			infile >> booksArray[count].Price;
			cout << booksArray[count].ISBN << endl << booksArray[count].Title << endl << booksArray[count].Author << endl << booksArray[count].Publisher << endl << booksArray[count].Quantity << endl << booksArray[count].Price << endl << endl;
		}
		size = count;
		//cout << size; //testing
	}
	infile.close();// closes the file
}
void invAdd(struct Books booksArray[], int &size, int MAX_SIZE)
{
	//cout << size;//testing pass through of var
	int count = size;
	int i = 0;
	
	/*for (i = 0; i < size; i++)
	{
		cout << booksArray[i].ISBN << endl << booksArray[i].Title << endl << booksArray[i].Author << endl << booksArray[i].Publisher << endl << booksArray[i].Quantity << endl << booksArray[i].Price << endl << endl;

	}*/

	if (size >= MAX_SIZE)
	{
		cout << "Error, only " << MAX_SIZE << " books allowed\n";
	}
	else
	{
			cout << "Please enter ISBN\n";
		cin >> booksArray[count].ISBN;
		cout << "Please enter title\n";
		cin >> booksArray[count].Title;
		cout << "Please enter author\n";
		cin >> booksArray[count].Author;
		cout << "Please enter publisher\n";
		cin >> booksArray[count].Publisher;
		cout << "Please enter quantity\n";
		cin >> booksArray[count].Quantity;
		cout << "Please enter price\n";
		cin >> booksArray[count].Price;
		invSort(booksArray, size);
		size = size + 1;
		/*for (i = 0; i < count + 1; i++)
			cout << booksArray[i].Title;//used to see if new item added to array*/
	}
	/*for (i = 0; i < size; i++)
	{
		cout << booksArray[i].ISBN << endl << booksArray[i].Title << endl << booksArray[i].Author << endl << booksArray[i].Publisher << endl << booksArray[i].Quantity << endl << booksArray[i].Price << endl << endl;

	}*/// testing contents of bookarray
}
void invDelete(struct Books booksArray[], int &size)
{
	int i=0;
	int k;
	int bisbn;
	cout << "Input the ISBN of the book you wish to delete\n";
	cin >> bisbn;
	for (i = 0; i < size-1; i++)
	{
		if (bisbn == booksArray[i].ISBN && i<size-1)
		{
			for (k = i; k < size-1; k++)
			{
				booksArray[k].ISBN = booksArray[k + 1].ISBN;
				booksArray[k].Title = booksArray[k + 1].Title;
				booksArray[k].Author = booksArray[k + 1].Author;
				booksArray[k].Publisher = booksArray[k + 1].Publisher;
				booksArray[k].Quantity = booksArray[k + 1].Quantity;
				booksArray[k].Price = booksArray[k + 1].Price;
			}
			size = size - 1;
		}
		else if ((booksArray[i].ISBN == bisbn) && i == size-1)
		{
			size = size - 1;
		}
	}
	for (i = 0; i < size-1; i++)
	{
		cout << booksArray[i].ISBN << endl << booksArray[i].Title << endl << booksArray[i].Author << endl << booksArray[i].Publisher << endl << booksArray[i].Quantity << endl << booksArray[i].Price << endl << endl;

	}
}
void invUpdate(struct Books booksArray[], int &size)
{
	int bisbn, qtychg,i;
	cout << "Which ISBN would you like to change?\n";
	cin >> bisbn;
	cout << "Would you like to (1)increment or (2)decrement the quantity?";
	cin >> qtychg;
	if (qtychg == 1)
		qtychg = 1;
	else { qtychg = -1; }
	for (i = 0; i < size; i++)
	{
		if (bisbn == booksArray[i].ISBN)
		{
			booksArray[i].Quantity = booksArray[i].Quantity + qtychg;
		}
	}
	/*for (i = 0; i < size; i++)
	{
		cout << booksArray[i].ISBN << endl << booksArray[i].Title << endl << booksArray[i].Author << endl << booksArray[i].Publisher << endl << booksArray[i].Quantity << endl << booksArray[i].Price << endl << endl;

	}*/
}
void invSort(struct Books booksArray[], int &size)
{
	int i;
	bool swap;
	struct Books temp;
	do
	{
		swap = false;
		for (int count = 0; count < size-1; count++)
		{
			if (booksArray[count].Title > booksArray[count + 1].Title)
			{
				temp = booksArray[count];
				booksArray[count] = booksArray[count + 1];
				booksArray[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	/*for (i = 0; i < size; i++)
	{
		cout << booksArray[i].ISBN << endl << booksArray[i].Title << endl << booksArray[i].Author << endl << booksArray[i].Publisher << endl << booksArray[i].Quantity << endl << booksArray[i].Price << endl << endl;

	}*/
}
void invWrite(struct Books booksArray[], int &size)
{
	int i;
	cout << "Writing to file. Goodbye!" << endl;
	ofstream outfile;
	outfile.open("inventory.txt");
	for (i = 0; i < size; i++)
	{
		outfile << booksArray[i].ISBN << endl;
		outfile << booksArray[i].Title << endl;
		outfile << booksArray[i].Author << endl;
		outfile << booksArray[i].Publisher << endl;
		outfile << booksArray[i].Quantity << endl;
		outfile << booksArray[i].Price << endl; 

	}
	outfile.close();
}
