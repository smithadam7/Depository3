// Adam Smith
#ifndef recursion_h
#define recursion_h
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Vehicle
{
public:
	Vehicle( string iMake, string iModel, int iYear);
	Vehicle();
	string getMake();
	string getModel();
	int getYear();
	void setMake(string);
	void setModel(string);
	void setYear(int);
	friend ostream& operator << (ostream& out, Vehicle car1);
	// Member Functions used in main to operate on the data
	void invRead(vector <Vehicle> &Vehicles);
	void invDisplay(vector <Vehicle> &Vehicles);
	void iterSortYear(vector<Vehicle> &Vehicles);
	void iterSortMake(vector<Vehicle> &Vehicles);
	void iterSortModel(vector<Vehicle> &Vehicles);
	int recurSearchYear(vector<Vehicle> &Vehicles, int first, int last, int search);
	int recurSearchMake(vector<Vehicle> &Vehicles, int first, int last, string ssearch);
	int recurSearchModel(vector<Vehicle> &Vehicles, int first, int last,string ssearch);
	void iterSearchYear(vector<Vehicle> &Vehicles,int search);
	void iterSearchMake(vector<Vehicle> &Vehicles,string ssearch);
	void iterSearchModel(vector<Vehicle> &Vehicles,string ssearch);
private:
	string make;
	string model;
	int year;
};


# endif