// Adam Smith
#include "recursion.h"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(string iMake, string iModel, int iYear)
{
	make = iMake;
	model = iModel;
	year = iYear;
}
Vehicle::Vehicle() {
	make = "";
	model = "";
	year = 0;
}

string Vehicle::getMake() {
	return make;
}
string Vehicle::getModel() {
	return model;
}
int Vehicle::getYear() {
	return year;
}

void Vehicle::setMake(string iMake) {
	make = iMake;
}
void Vehicle::setModel(string iModel) {
	model = iModel;
}
void Vehicle::setYear(int iYear) {
	year = iYear;
}

ostream& operator<<(ostream& out, Vehicle car1) {
	return out;
}

void Vehicle::invRead(vector<Vehicle> &Vehicles)
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
		infile.ignore();// For spaces in places
		getline(infile, dummycar);
		car.setMake(dummycar);
		getline(infile, dummycar);
		car.setModel(dummycar);
		getline(infile, dummycar);//for the | in the input
		Vehicles.push_back(Vehicle(car));
	}
	infile.close();
	cout << "File Read Successfully" << endl;
}

void Vehicle::invDisplay(vector <Vehicle> &Vehicles)
{// outputs the contents of the vector to the screen
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
}

void Vehicle::iterSortYear(vector<Vehicle> &Vehicles)
{
	//use bubble sort on the vector by year
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by year:\n";
		bool swap;
		Vehicle temp;//for sorting
		do // do loop
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
		} while (swap);//end of do
	}
}

int Vehicle::recurSearchYear(vector<Vehicle> &Vehicles, int first, int last, int search) {
	if (first <= last) {
		int p = first + (last - first) / 2; //Calculate pivot point or mid
		if (search == Vehicles[p].getYear()) {// does this when search is found
			cout << "Year: " << Vehicles[p].getYear() << endl;
			cout << "Make: " << Vehicles[p].getMake() << endl;
			cout << "Model: " << Vehicles[p].getModel() << endl << endl;
			return Vehicles[p].getYear();
		}
		else if (search < Vehicles[p].getYear())
			return recurSearchYear(Vehicles, first, p - 1, search);//calling original function with smaller problem
		else
			return recurSearchYear(Vehicles, p + 1, last, search);//calling original function with smaller problem
	}
	cout << "Nothing matched your search\n";//does this if search not found
	return -(first + 1);
}
int Vehicle::recurSearchMake(vector<Vehicle> &Vehicles, int first, int last, string ssearch) {
	if (first <= last) {
		int p = first + (last - first) / 2; //Calculate pivot point or mid
		if (ssearch == Vehicles[p].getMake()) {
			cout << "Year: " << Vehicles[p].getYear() << endl;
			cout << "Make: " << Vehicles[p].getMake() << endl;
			cout << "Model: " << Vehicles[p].getModel() << endl << endl;
			return Vehicles[p].getYear();
		}
		else if (ssearch < Vehicles[p].getMake())
			return recurSearchMake(Vehicles, first, p - 1, ssearch);//calling original function with smaller problem
		else
			return recurSearchMake(Vehicles, p + 1, last, ssearch);//calling original function with smaller problem
	}
	cout << "Nothing matched your search\n";//does this if search not found
	return -(first + 1);
}
int Vehicle::recurSearchModel(vector<Vehicle> &Vehicles, int first, int last,string ssearch) {
	if (first <= last) {
		int p = first + (last - first) / 2; //Calculate pivot point or mid
		if (ssearch == Vehicles[p].getModel()) {
			cout << "Year: " << Vehicles[p].getYear() << endl;
			cout << "Make: " << Vehicles[p].getMake() << endl;
			cout << "Model: " << Vehicles[p].getModel() << endl << endl;
			return Vehicles[p].getYear();
		}
		else if (ssearch < Vehicles[p].getModel())
			return recurSearchModel(Vehicles, first, p - 1, ssearch);//calling original function with smaller problem
		else
			return recurSearchModel(Vehicles, p + 1, last, ssearch);//calling original function with smaller problem
	}
	cout << "Nothing matched your search\n";//does this if search not found
	return -(first + 1);
}

void Vehicle::iterSearchYear(vector<Vehicle>& Vehicles,int search)
{//use bubble sort with year
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		for (int count = 0; count < Vehicles.size(); count++)
		{//much simpler way to search for something
			if (Vehicles[count].getYear() == search)
			{
				cout << "Year: " << Vehicles[count].getYear() << endl;
				cout << "Make: " << Vehicles[count].getMake() << endl;
				cout << "Model: " << Vehicles[count].getModel() << endl;
			}
		}
	}
}

void Vehicle::iterSearchMake(vector<Vehicle>& Vehicles,string ssearch)
{//use bubble sort with make
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		for (int count = 0; count < Vehicles.size(); count++)
		{//much simpler way to search for something
			if (Vehicles[count].getMake() == ssearch)
			{
				cout << "Year: " << Vehicles[count].getYear() << endl;
				cout << "Make: " << Vehicles[count].getMake() << endl;
				cout << "Model: " << Vehicles[count].getModel() << endl;
			}
		}
	}
}

void Vehicle::iterSearchModel(vector<Vehicle>& Vehicles,string ssearch)
{//use bubble sort with model
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		for (int count = 0; count < Vehicles.size(); count++)
		{//much simpler way to search for something
			if (Vehicles[count].getModel() == ssearch)
			{
				cout << "Year: " << Vehicles[count].getYear() << endl;
				cout << "Make: " << Vehicles[count].getMake() << endl;
				cout << "Model: " << Vehicles[count].getModel() << endl;
			}
		}
	}
}

void Vehicle::iterSortMake(vector<Vehicle> &Vehicles)
{//Simple sort by the make of the car which is a string
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by make:\n";
		bool swap;
		Vehicle temp;//temporary vehicle for swapping
		do // do loop
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
		} while (swap);//end of do
	}
}

void Vehicle::iterSortModel(vector<Vehicle> &Vehicles)
{//sorts the vector by model of car
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		cout << "Iterative sort by model:\n";
		bool swap; 
		Vehicle temp;//temporary vehicle for swapping
		do // do loop
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
		} while (swap);// end of do
	}
}



