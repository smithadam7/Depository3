#include "stdafx.h"

// This program will read in the qunatity of a particular item and its price. 
// It will then print out the total price. // The input will come from a data file and the output will go to
// an output file.
// Adam Smith
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
	ifstream dataIn; // defines an input stream for a data file
	ofstream dataOut; // defines an output stream for an output file
	int quantity;	  // contains the amount of items purchased
	float itemPrice; // contains the price of each item
	float totalBill; // contains the total bill.  The price of all items
		dataIn.open("transaction.dat");  // This opens the file. 
		dataOut.open("bill.out");
										 // Fill in the appropriate code in the blank below
		dataOut << setprecision(2) << fixed << showpoint;  // formatted output
		dataIn >> quantity >> itemPrice;
			// Fill in the input statement that brings in the // quantity and price of the item.
		totalBill = itemPrice * quantity;
			// Fill in the assignment statement that determines the totalbill.
		dataOut << "The total bill is $"<< totalBill;
		 // Fill in the output statement that prints the total bill, with a label, // to an output.
		//system("pause");
		
		return 0;
}