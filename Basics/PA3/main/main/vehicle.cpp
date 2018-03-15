#include "vehicle.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
Dealer::Dealer() {
	DealerName = "";
	DealerAddress = "";
}
Dealer::Dealer(string iName,string iAddress) {
	DealerName = iName;
	DealerAddress = iAddress;
}
void Dealer::setName(string iName) {
	DealerName = iName;
}
void Dealer::setAddress(string iAddress) {
	DealerAddress = iAddress;
}
string Dealer::getName() {
	return DealerName;
}
string Dealer::getAddress() {
	return DealerAddress;
}
Vehicle::Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice)
{
	VIN = iVIN;
	make = iMake;
	model = iModel;
	year = iYear;
	price = iPrice;
}
Vehicle::Vehicle() {
	VIN = "";
	make = "";
	model = "";
	year = 0;
	price = 0.0;
	Dealer * DealerPtr = nullptr;
}
string Vehicle::getVIN() {
	return VIN;
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
double Vehicle::getPrice() {
	return price;
}
void Vehicle::setVIN(string iVIN) {
	VIN = iVIN;
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
void Vehicle::setPrice(double iPrice) {
	price = iPrice;
}
ostream& operator<<(ostream& out, Vehicle car1) {
	return out;
}
//incorporate the dealer pointer for the dealer class