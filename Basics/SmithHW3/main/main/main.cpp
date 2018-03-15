// Adam Smith
// HW3
// Recursion
// Last Modified 02-4-17
// Built and ran successfully on Visual Studio
#include "recursion.h"
using namespace std;

int main()
{
	/////Change the search method with comments/////
	cout << "Change the search method with comments.\n\n";
	vector<Vehicle> Vehicles;//vector of class vehicle
	int search;
	string ssearch;
	Vehicle().invRead(Vehicles);//class member function to read from file and into vector
	Vehicle().invDisplay(Vehicles);//function displays contents of the vector
	
	// First Sort By Year:
	Vehicle().iterSortYear(Vehicles);
	Vehicle().invDisplay(Vehicles);
	cout << "Input the year to search for: ";
	cin >> search;
	// Search Method:
	Vehicle().recurSearchYear(Vehicles, 0, Vehicles.size()-1, search);
	//Vehicle().iterSearchYear(Vehicles, search);

	// Sort By Make:
	Vehicle().iterSortMake(Vehicles);
	Vehicle().invDisplay(Vehicles);
	cout << "Input the make to search for: ";
	cin.ignore();
	getline(cin, ssearch);//in case of spaces in term
	// Search Method:
	Vehicle().recurSearchMake(Vehicles, 0, Vehicles.size() - 1, ssearch);
	//Vehicle().iterSearchMake(Vehicles, ssearch);

	// Sort By Model:
	Vehicle().iterSortModel(Vehicles);
	Vehicle().invDisplay(Vehicles);
	cout << "Input the model to search for: ";
	getline(cin, ssearch);//in case of spaces in term
	// Search Method:
	Vehicle().recurSearchModel(Vehicles, 0, Vehicles.size() - 1, ssearch);
	//Vehicle().iterSearchModel(Vehicles, ssearch);


	string hold;
	cout << "Goodbye!";// Lets user know its over
	cin >> hold;
    return 0;
}

