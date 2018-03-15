#ifndef functions_h
#define functions_h
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "recursion.h"
using namespace std;

//void invDisplay(vector <Vehicle> &Vehicles);
//void invRead(vector <Vehicle> &Vehicles);
//void iterSortYear(vector<Vehicle> &Vehicles);
//void iterSortMake(vector<Vehicle> &Vehicles);
//void iterSortModel(vector<Vehicle> &Vehicles);
//int recurSearchYear(vector<Vehicle> &Vehicles, int first, int last, int search);
//void recurSearchMake(vector<Vehicle> &Vehicles, int first, int last, int search);
//void recurSearchModel(vector<Vehicle> &Vehicles, int first, int last, int search);


/*void invDisplay(vector <Vehicle> &Vehicles)
{
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		int j = Vehicles.size();
		for (int i = 0; i < j; i++) {
			cout << "Year: " << Vehicles[i].getYear() << endl;
			cout << "Make: " << Vehicles[i].getMake() << endl;
			cout << "Model: " << Vehicles[i].getModel() << endl << endl;
		}
	}
}*/
/*void invRead(vector<Vehicle> &Vehicles)
{
	// read the file and display with ifstream
	ifstream infile;
	infile.open("vehiclein.txt");
	Vehicle car;
	string dummycar;
	int dummyyear;
	while (!infile.eof()) {
		infile >> dummyyear;
		car.setYear(dummyyear);
		infile.ignore();
		getline(infile, dummycar);
		car.setMake(dummycar);
		getline(infile, dummycar);
		car.setModel(dummycar);
		getline(infile, dummycar);//for the | in the input
		Vehicles.push_back(Vehicle(car));
	}
	infile.close();
	cout << "File Read Successfully" << endl;
}*/
/*void iterSortYear(vector<Vehicle> &Vehicles)
{
	//use bubble sort on the vector by VIN
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by year:\n";
		bool swap;
		Vehicle temp;
		do
		{
			swap = false;
			for (int count = 0; count < Vehicles.size() - 1; count++)
			{
				if (Vehicles[count].getYear() > Vehicles[count + 1].getYear())
				{
					temp = Vehicles[count];
					Vehicles[count] = Vehicles[count + 1];
					Vehicles[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}
}*/
/*void iterSortMake(vector<Vehicle> &Vehicles)
{
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by make:\n";
		bool swap;
		Vehicle temp;
		do
		{
			swap = false;
			for (int count = 0; count < Vehicles.size() - 1; count++)
			{
				if (Vehicles[count].getMake() > Vehicles[count + 1].getMake())
				{
					temp = Vehicles[count];
					Vehicles[count] = Vehicles[count + 1];
					Vehicles[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}
}*/
/*void iterSortModel(vector<Vehicle> &Vehicles)
{
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by model:\n";
		bool swap;
		Vehicle temp;
		do
		{
			swap = false;
			for (int count = 0; count < Vehicles.size() - 1; count++)
			{
				if (Vehicles[count].getModel() > Vehicles[count + 1].getModel())
				{
					temp = Vehicles[count];
					Vehicles[count] = Vehicles[count + 1];
					Vehicles[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
	}
}*/
/*int recurSearchYear(vector<Vehicle> &Vehicles, int first, int last, int search) {
	Vehicle temp;
	//first = Vehicles.front;
	//last = Vehicles.back;
	int index = 0;
	if (first <= last) {
		int p = first + (last-first) / 2; //Calculate pivot point
		if (search == Vehicles[p].getYear()) {
			cout << "Year: " << Vehicles[p].getYear() << endl;
			cout << "Make: " << Vehicles[p].getMake() << endl;
			cout << "Model: " << Vehicles[p].getModel() << endl << endl;
			return Vehicles[p].getYear();
		}
		else if (search < Vehicles[p].getYear())
			return recurSearchYear(Vehicles, first, p - 1, search);
		else 
			return recurSearchYear(Vehicles, p + 1, last, search);
	}
	return -(first+1);
}*/
/*int recurSearchMake(vector<Vehicle> &Vehicles, int first, int last, int search) {

}
int recurSearchModel(vector<Vehicle> &Vehicles, int first, int last, int search) {

}*/

# endif