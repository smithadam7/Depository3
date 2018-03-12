#include "stdafx.h"
// Adam Smith
#include <iostream>
using namespace std;
int main() {
	int numTellers;
	float days, total, average, total2, average2, bioHours;
	int teller, year = 0;     // these are the counters for the loops
	cout << "How many tellers worked at Nation's Bank during each of the last three years?\n\n";
	
	cin >> numTellers;
	for (teller = 1; teller <= 2; teller++) {
		total = 0; for (year = 1; year <= 3; year++) {
			cout << "How many days was teller " << teller << " out sick during year " << year << "?" << endl;
			cin >> days;
			
			total = total + days;
		}        
	}
	cout << endl;
	cout << "The 2 tellers were out sick for a total of " << total << " days during the last 3 years " <<
		endl << endl << endl;

	system("pause");
	return 0;
}