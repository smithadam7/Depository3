#include "stdafx.h"
// This program will read in prices and store them into a two-dimensional array 
// It will print those prices in a table form.
// Adam Smith
#include <iostream>
#include <iomanip> 
using namespace std;
int const  MAXROWS = 10;
int const  MAXCOLS = 10;
typedef float PriceType[MAXROWS][MAXCOLS];    // creates a new data type   // of a 2D array of floats
void   getPrices(PriceType, int&, int&);   // gets the prices into the array void   
void printPrices(PriceType, int, int);      // prints data as a table
int main()
{
	int rowsUsed;                               // holds the number of rows used     
	int colsUsed;                               // holds the number of columns used 
	PriceType priceTable;                       // a 2D array holding the prices
	getPrices(priceTable, rowsUsed, colsUsed);  // calls getPrices to fill the array 
	printPrices(priceTable, rowsUsed, colsUsed);// calls printPrices to display array
	system("pause");
	return 0;
}
//****************************************************************************** *** //                           getPrices // //  task:     This procedure asks the user to input the number of rows and //            columns. It then asks the user to input (rows * columns) number //            of prices where x = rows * columns.  The data is placed in the array. //  data in:  none //  data out: an array filled with numbers and the number of rows //            and columns used. // //****************************************************************************** **
void   getPrices(PriceType table, int& numOfRows, int& numOfCols)
{
	cout << "Please input the number of rows from 1 to " << MAXROWS << endl;

	cin >> numOfRows;
	cout << "Please input the number of columns from 1 to " << MAXCOLS << endl;
	cin >> numOfCols;
	cout << "Please input the price of an item with 2 decimal places\n";
	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
			// Fill in the code to read and store the next value in the array
			cin >> table[row][col];
	}
}
//*************************************************************************** 
//                           printPrices // 
//  task:     This procedure prints the table of prices 
//  data in:  an array of floating point numbers and the number of rows 
//   and columns used. //  data out: none // 
//****************************************************************************
void   printPrices(PriceType table, int numOfRows, int numOfCols)
{
	cout << fixed << showpoint << setprecision(2);
	for (int row = 0; row < numOfRows; row++)
	{
		for (int col = 0; col < numOfCols; col++)
			// Fill in the code to print the table
			cout << table[row][col] << " ";
	}
	}
// Excercise 2: getPrices has the parameters passed by reference because it modifies the value
// printPrices has the parameters passed by value because it just uses a copy of the argument
// Excercise 5: the result was: 1.45  2.56  12.98
//								37.68  102.34  67.89