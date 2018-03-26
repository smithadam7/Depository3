//Adam Smith

#ifndef functions_
#define functions_
#include <iostream>
#include <vector>
#include <fstream>
#include "BSTree.h"
#include "data.h"

using namespace std;

//Error detection
class FileIOException
{
	//  Nothing inside, just a class type to handle exception
};

//Read in from file Function
void readFile(Data *database);

//Search Functions
void searchID(Data *database);//search the tree
//The search functions to the corresponding vector using exact search word
void searchFirstName(Data *database);
void searchMiddleName(Data *database);
void searchLastName(Data *database);
void searchCompanyName(Data *database);
void searchHomePhone(Data *database);
void searchOfficePhone(Data *database);
void searchEmail(Data *database);
void searchMobilePhone(Data *database);
void searchAddress(Data *database);
void searchCity(Data *database);
void searchState(Data *database);
void searchZip(Data *database);
void searchCountry(Data *database);
void searchAfil(Data *database);

//These search funtions search for results that contain the search word,
void csearchID(Data*database);
void csearchFirstName(Data *database);
void csearchMiddleName(Data *database);
void csearchLastName(Data *database);
void csearchCompanyName(Data *database);
void csearchHomePhone(Data *database);
void csearchOfficePhone(Data *database);
void csearchEmail(Data *database);
void csearchMobilePhone(Data *database);
void csearchAddress(Data *database);
void csearchCity(Data *database);
void csearchState(Data *database);
void csearchZip(Data *database);
void csearchCountry(Data *database);
void csearchAfil(Data *database);

#endif