#include "stdafx.h"
// This program will allow the user to input from the keyboard 
// whether the last word to the following proverb should be party or country:
// "Now is the time for all good men to come to the aid of their _______" 
// Inputting a 1 will use the word party. Any other number will use the word country.
// Adam Smith
#include <iostream> 
#include <string> 
using namespace std;
// Fill in the prototype of the function writeProverb.
void writeProverb(string);
int main() 
{
	string wordCode;
	cout << "Given the phrase:" << endl;
	cout << "Now is the time for all good men to come to the aid of their ___"<< endl;
	cout << "Please input the word you would like to have finish the proverb " <<endl;
	cin >> wordCode;
	cout << endl;
	writeProverb(wordCode);
	system("pause");
	return 0;
}
// ****************************************************************************** //                            writeProverb //   //   task:      This function prints a proverb. The function takes a number //              from the call. If that number is a 1 it prints "Now is the time //              for all good men to come men to come to the aid of their party." //              Otherwise, it prints "Now is the time for all good men //              to come to the aid of their country" //   data in:   code for ending word of proverb (integer) //   data out:  none // //   *****************************************************************************
void writeProverb(string wordCode)
{   // Fill in the body of the function to accomplish what is described above
	cout << "Now is the time for all good men to come to the aid of their " << wordCode << endl;
}
// Excercise 1: the code will tell the user an error