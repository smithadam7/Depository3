/* Adam Smith
	Last Modified 9-19-16
	Assignment: PA1 Magic Number
	Magic Number Program takes a 3 digit number and ends up with the number 1089
	Compiled and ran successfully on Visual Studio
	Met all requirements
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string name;
string class1;
char userOption;
int userNum,t, reverseNum = 0;
int newNum1,t2, rev2 = 0;
int finalNum;


int main()
{
	// Welcome Menu
	cout << "Welcome!\nWhat is your first name?" << endl;
	cin >> name;
	cout << endl << "What is your class?" << endl;
	cin >> class1;
	cout << name << ", Welcome to your Magic Number program. I hope it helps with your " <<
		class1 << " class!" << endl;


	// Menu
	do // Starts the do-while loop used for the menu because we are not sure how many times to loop it
	{
		cout << "Please select an option:\n a: Display an example\n b :Try it yourself! \n c: Exit \n";

		cin >> userOption;//Takes in the character that the user inputs
		if (userOption == 'a' || userOption == 'A')// Do this is user chooses a
		{
			cout << "Example:\n Take a 3 digit number with each digit greater than the last\n ";
			cout <<	"such as 765, 843, or 901.\n " 
				"Lets take the number 901. Then reverse the digits to get 109. Subtract the reversal \n"
				"number from the original number. 901 - 109 = 792 \n"
				"Now reverse 792 to get 297. Lastly add these two numbers. 792 + 297 = 1089. \n" 
				"It should always equal 1089 regardless of the first number."<< endl << endl << endl;
		}
		else if (userOption == 'b' || userOption == 'B')//Do this is user chooses b
		{
			cout << "Choose a 3 digit number with each digit greater than the last.\n";
			cin >> userNum;
			cout << "The number you entered is: " << userNum << endl;
			t = userNum;//reassigning the variable to different name so it can be used later on
			for (; t != 0;)//For loop to reverse the number
			{
				reverseNum = reverseNum * 10;//Algorithm to reverse digits first multiply by 10
				reverseNum = reverseNum + t % 10;// Uses mod function to get the remainder after the division
				t = t / 10;//Last divide by 10
			}
			cout << "The reversal of the input is: " << reverseNum << endl;
			newNum1 = userNum - reverseNum;
			cout << "Subtraction of reversal of the original number is " << newNum1 << endl;//198
			
			t2 = newNum1;
			for (; t2!= 0;)//I used the same for loop for the second reversal just with different variables
			{
				rev2 = rev2 * 10;
				rev2 = rev2 + t2 % 10;//Used the mod function to get the remainder after the division
				t2 = t2 / 10;
			}
			cout << "Reversal of the resulting number is: " << rev2 << endl;//891
			finalNum = rev2 + newNum1;
			cout << "Addition of the number to the un-reversed form is: " << finalNum << endl;
			cout << "The final outcome is: " << finalNum << ", which is our Magic Number" << endl << endl;
			
		}
		else if (userOption == 'c' || userOption == 'C')// Do this if user chooses c
		{
			cout << "Goodbye" << endl;
			break;// Ends the program
		}
		else// If the user inputs anything other than a,A,b,B,C or c
		{
			cout << "Invalid Option" << endl;
		}
	} while (true);// The while is at the end for the do-while statements


	system("pause");
	return 0;
}



