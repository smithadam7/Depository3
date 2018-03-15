// Adam Smith
// PA3
// Car Dealership
// Last Modified 11-14-16
// Built and ran successfully on Visual Studio
#include "stdafx.h"
#include <iostream>
#include <string>
#include "vehicle.h"
#include "functions.h"
#include <vector>
using namespace std;

int main()
{
	int hold;
	vector<Vehicle> Vehicles;
	do//This will be the menu for the car dealership
	{
		cout << "Please Choose an Option\n"
			<< endl << "1: Display Inventory\n2: Add a vehicle\n3: Update a vehicle\n4: Delete a vehicle\n5: Sort inventory by VIN\n6: Search by model\n7: Read Inventory from file\n8: Write inventory to file and exit\n";
		cin >> userOption;
		if (userOption == 1)// displays the inventory
		{
			invDisplay(Vehicles);
		}
		else if (userOption == 2)//adds a vehicle
		{
			addV(Vehicles);
		}
		else if (userOption == 3)// Updates a vehicle
		{
			updateV(Vehicles);
		}
		else if (userOption == 4)// Delete Vehicle
		{
			deleteV(Vehicles);
		}
		else if (userOption == 5)// to sort by VIN
		{
			invSortVIN(Vehicles);
		}
		else if (userOption == 6)//Search by model
		{
			invSortModel(Vehicles);
		}
		else if (userOption == 7)//read inventory from file inventory.txt
		{
			invRead(Vehicles);
		}
		else if (userOption == 8)//write inventory to file and exit
		{
			invWrite(Vehicles);
			break;// exits the program
		}
		else
		{
			cout << userOption << " is not a valid option\n";// if the user puts a different number
		}
	} while (true);// For the menu

	cin >> hold;
    return 0;
}
