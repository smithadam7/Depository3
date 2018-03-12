// This program will determine the batting average of a player. 
// The number of hits and at bats are set internally in the program.
// Adam Smith
#include <iostream>
//#include "stdafx.h"
#include <iomanip>
using namespace std;
const int AT_BAT = 421;
const int HITS = 123;
int main() {
	float batAvg;
	batAvg = static_cast<float>(HITS) / AT_BAT;
	//an assignment statement
		cout << "The batting average is " << batAvg << endl;   //output the result 
		//system("pause");
		return 0;
}
//Excercise 1: The result is 0
//Excercise 2: The result is 0
