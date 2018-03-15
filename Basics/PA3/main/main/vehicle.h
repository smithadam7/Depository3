#ifndef vehicle_h
#define vehicle_h
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Dealer
{
private:
	string DealerName;
	string DealerAddress;
public:
	void setName(string);
	void setAddress(string);
	string getName();
	string getAddress();
	Dealer();
	Dealer(string iName,string iAddress);
};
class Vehicle
{
public:
	Dealer* DealerPtr;
	Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice);
	Vehicle();
	string getVIN();
	string getMake();
	string getModel();
	int getYear();
	double getPrice();
	void setVIN(string );
	void setMake(string );
	void setModel(string );
	void setYear(int);
	void setPrice(double price);
	friend ostream& operator << (ostream& out,Vehicle car1);
private:
	string VIN;
	string make;
	string model;
	int year;
	double price;
};
# endif
