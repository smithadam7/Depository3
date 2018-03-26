// This program demonstrates the use of characters and strings 
// Adam Smith
#include <iostream>
#include <string> 
//#include "stdafx.h"
using namespace std;
// Definition of constants 
const string FAVORITESODA = "Dr. Dolittle"; 
const char BESTRATING = 'A'; 

int main()
{
		char rating; // 2nd highest product ratingstring favoriteSnack; 
					 // most preferred snackint numberOfPeople; 
					 // the number of people in the surveyint topChoiceTotal; 
					 // the number of people who prefer the top choice
					 // Fill in the code to do the following:
					 // Assign the value of "crackers" to favoriteSnack
					 // Assign a grade of 'B' to rating
					 // Assign the number 250 to the numberOfPeople
					 // Assign the number 148 to the topChoiceTotal
			
					 // Fill in the blanks of the following:
		string favoriteSnack;
		int numberOfPeople;
		int topChoiceTotal;

		favoriteSnack = "crackers";
		numberOfPeople = 250;
		topChoiceTotal = 148;
		rating = 'B';

		
		cout << "The preferred soda is " << FAVORITESODA << endl;
		cout << "The preferred snack is " << favoriteSnack  << endl;
		cout << "Out of " << numberOfPeople << " people " <<  topChoiceTotal << " chose these items!" << endl;
		cout << "Each of these products were given a rating of " << BESTRATING;
		cout << " from our expert tasters" << endl;
		cout << "The other products were rated no higher than a " << rating << endl;
		//system("pause");
	return 0;

	// You cannot change the choice of favorite soda inside main because it is a constant variable
	// You can change the choice of favoriteSnack inside main because it is a user created variable
}