//  Adam Smith
#include <iostream> 
#include <iomanip> 
//#include "stdafx.h"
#include <string>
using namespace std;
int main()
{
	int   quantity; // contains the amount of items purchased
	float itemPrice; // contains the price of each item 
	float totalBill; // contains the total bill.
	string item1; // Name of the item being purchased by the user
	cout << setprecision(2) << fixed << showpoint;  //formatted output

	cout << "Please input the name of the item \n";
	cin >> item1;
	cout << "Please input the number of items bought" << endl;   
	//input statement to bring in the quantity. 
	cin >> quantity;
	// prompt to ask for the price. 
	cout << "Please input the price of the item" << endl;
	// input statement to bring in the price of each item. 
	cin >> itemPrice;
	//determines the total bill. 
	totalBill = quantity * itemPrice;
	// output statement to print total bill, with a label to the screen. 
	cout << "The item you bought is" << item1 << endl << "Your total bill is " << totalBill << endl;

	//system("pause");
	return 0;
}

//Excercise 2: The result does not include a decimal . I think the fixed attribute is for if you want a decimal.
//Excercise 3: There are now 4 0's after the answer. The setprecision is how many decimal places you want

