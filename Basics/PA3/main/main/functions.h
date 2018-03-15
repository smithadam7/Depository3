//Adam Smith
//#pragma once
#ifndef functions_h
#define functions_h
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "vehicle.h"
using namespace std;
int userOption;
void invDisplay(vector <Vehicle> &Vehicles);
void addV(vector <Vehicle> &Vehicles);
void updateV(vector <Vehicle> &Vehicles);
void deleteV(vector <Vehicle> &Vehicles);
void invSortVIN(vector <Vehicle> &Vehicles);
void invSortModel(vector <Vehicle> &Vehicles);
void invRead(vector <Vehicle> &Vehicles);
void invWrite(vector <Vehicle> &Vehicles);

void invDisplay(vector <Vehicle> &Vehicles)
{
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		int j = Vehicles.size();
		for (int i = 0; i < j; i++) {
			cout << "Vehicle #" << i + 1 << endl;
			cout << "VIN: " << Vehicles[i].getVIN() << endl;
			cout << "Make: " << Vehicles[i].getMake() << endl;
			cout << "Model: " << Vehicles[i].getModel() << endl;
			cout << "Year: " << Vehicles[i].getYear() << endl;
			cout << "Price: " << Vehicles[i].getPrice() << endl;
			cout << "Dealer Name: " << Vehicles[i].DealerPtr->getName() << endl;
			cout << "Dealer Address: " << Vehicles[i].DealerPtr->getAddress() << endl << endl;
		}
	}
}
void addV(vector<Vehicle> &Vehicles)
{
	// add a vehicle to vector
	Vehicle add;
	string addcar;
	int addyear;
	double addprice;
	//push back to add a vehicle
	cout << "Add a Vehicle" << endl;
	cout << endl << "Input the VIN: ";
	cin >>addcar;
	add.setVIN(addcar);
	cout << "Input the Make: ";
	cin >> addcar;
	add.setMake(addcar);
	cout << "Input the Model: ";
	cin >> addcar;
	add.setModel(addcar);
	cout << "Input the Year: ";
	cin >> addyear;
	add.setYear(addyear);
	cout << "Input the Price: ";
	cin >> addprice;
	add.setPrice(addprice);
	cout << "Input the Dealer Name: ";
	cin >> addcar;
	Dealer *DealerPtr = new Dealer();
	DealerPtr->setName(addcar);
	add.DealerPtr = DealerPtr;
	cout << "Input the Dealer Address: ";
	cin >> addcar;
	DealerPtr->setAddress(addcar);
	add.DealerPtr = DealerPtr;
	Vehicles.push_back(Vehicle(add));
	cout << "Vehicle Added" << endl;
}
void updateV(vector<Vehicle> &Vehicles)
{
	//display vehicles and cin user to input index number
	//then cin which part they want to edit
	//(year, make, model, price, or VIN)
	// cin new info
	// use pushback
	Vehicle update;
	string element;
	string newElem;
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		int i;
		int j = Vehicles.size();
		for (i = 0; i < j; i++) {
			cout << "Vehicle #" << i + 1 << endl;
			cout << "VIN: " << Vehicles[i].getVIN() << endl;
			cout << "Make: " << Vehicles[i].getMake() << endl;
			cout << "Model: " << Vehicles[i].getModel() << endl;
			cout << "Year: " << Vehicles[i].getYear() << endl;
			cout << "Dealer Name: " << Vehicles[i].DealerPtr->getName() << endl;
			cout << "Dealer Address: " << Vehicles[i].DealerPtr->getAddress() << endl << endl;
		}
		cout << "Which vehicle would you like to edit? Input index number: ";
		cin >> i;
		if (i > 0 && i < j + 1)
		{
			cout << "Which element would you like to edit?: ";
			cin >> element;
			update = Vehicles[i-1];
			cout << "What is the new " << element << "?: ";
			cin >> newElem;
			if (element == "year")
			{
				int newyear;
				cout << "Input the year again to confirm: ";
				cin >> newyear;
				update.setYear(newyear);
			}
			else if (element == "VIN")
				update.setVIN(newElem);
			else if (element == "make")
				update.setMake(newElem);
			else if (element == "model")
				update.setModel(newElem);
			else if (element == "price") 
			{
				double newprice;
				cout << "Input the price again to confirm: ";
				cin >> newprice;
				update.setPrice(newprice);
			}
			else
				cout << "Incorrect Element\n";
		}
		else
			cout << "Invalid Index Number\n";
		Vehicles.push_back(Vehicle(update));
		Vehicles.erase(Vehicles.begin()+i-1);
	}
}
void deleteV(vector<Vehicle> &Vehicles)
{
	//display vehicles and cin user index number and .erase to remove
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		int i;
		int j = Vehicles.size();
		for (i = 0; i < j; i++) {
			cout << "Vehicle #" << i + 1 << endl;
			cout << "VIN: " << Vehicles[i].getVIN() << endl;
			cout << "Make: " << Vehicles[i].getMake() << endl;
			cout << "Model: " << Vehicles[i].getModel() << endl;
			cout << "Year: " << Vehicles[i].getYear() << endl;
			cout << "Dealer Name: " << Vehicles[i].DealerPtr->getName() << endl;
			cout << "Dealer Address: " << Vehicles[i].DealerPtr->getAddress() << endl << endl;
		}
		cout << "Which vehicle would you like to erase? Input index number: ";
		cin >> i;
		Vehicles.erase(Vehicles.begin() + i - 1);
		cout << "Vehicle has been deleted\n";
	}
}
void invSortVIN(vector<Vehicle> &Vehicles)
{
	//use bubble sort on the vector by VIN
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		bool swap;
		Vehicle temp;
		do
		{
			swap = false;
			for (int count = 0; count < Vehicles.size() - 1; count++)
			{
				if (Vehicles[count].getVIN() > Vehicles[count + 1].getVIN())
				{
					temp = Vehicles[count];
					Vehicles[count] = Vehicles[count + 1];
					Vehicles[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}
void invSortModel(vector<Vehicle> &Vehicles)
{
	//use bubble sort with model
	if (Vehicles.size() < 1) {
		cout << "No vehicles found." << endl;
	}
	else {
		string search;
		cout << "What model do you want to search for?: ";
		cin >> search;
		Vehicle temp;
		//temp.setModel(search);
		//Vehicles.push_back(Vehicle(temp));
		for (int count = 0; count < Vehicles.size(); count++)
		{
			if (Vehicles[count].getModel() == search)
			{
				cout << "Vehicle #" << count + 1 << endl;
				cout << "VIN: " << Vehicles[count].getVIN() << endl;
				cout << "Make: " << Vehicles[count].getMake() << endl;
				cout << "Model: " << Vehicles[count].getModel() << endl;
				cout << "Year: " << Vehicles[count].getYear() << endl;
				cout << "Price: " << Vehicles[count].getPrice() << endl;
				cout << "Dealer Name: " << Vehicles[count].DealerPtr->getName() << endl;
				cout << "Dealer Address: " << Vehicles[count].DealerPtr->getAddress() << endl << endl;
			}
		}
	}
}
void invRead(vector<Vehicle> &Vehicles)
{
	// read the file and display with ifstream
	ifstream infile;
	infile.open("inventory.txt");
	Vehicle car;
	string dummycar;
	int dummyyear;
	double dummyprice;
	while (!infile.eof()) {
		getline(infile, dummycar);
		car.setVIN(dummycar);
		getline(infile, dummycar);
		car.setMake(dummycar);
		getline(infile, dummycar);
		car.setModel(dummycar);
		infile >> dummyyear;
		car.setYear(dummyyear);
		infile >> dummyprice;
		car.setPrice(dummyprice);
		infile.ignore();
		getline(infile, dummycar);
		Dealer *DealerPtr = new Dealer();//Use for pointers to the Dealer
		DealerPtr->setName(dummycar);
		car.DealerPtr = DealerPtr;
		getline(infile, dummycar);
		DealerPtr->setAddress(dummycar);
		Vehicles.push_back(Vehicle(car));
	}
	infile.close();
	cout << "File Read Successfully" << endl;
}
void invWrite(vector<Vehicle> &Vehicles)
{
	// write to the inventory.out file with ofstream
	int i;
	ofstream outfile;
	outfile.open("inventory.out");
	for (i = 0; i < Vehicles.size(); i++)
	{
		outfile <<  Vehicles[i].getVIN() << endl;
		outfile <<  Vehicles[i].getMake() << endl;
		outfile <<  Vehicles[i].getModel() << endl;
		outfile <<  Vehicles[i].getYear() << endl;
		outfile <<  Vehicles[i].getPrice() << endl;
		outfile <<  Vehicles[i].DealerPtr->getName() << endl;
		outfile <<  Vehicles[i].DealerPtr->getAddress() << endl;

	}
	outfile.close();
	cout << "File Saved! Goodbye\n";
	//delete DealerPtr;
}
#endif
//dealer pointer should have in constructor start at nullptr,
//when inserting dealer use dynamic variable new.
//Dealer *DealerPtr = new Dealer(); do this before before useing it. 
//delete DealerPtr;
//dealerPtr->setname();