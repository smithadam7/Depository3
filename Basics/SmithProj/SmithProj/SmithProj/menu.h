//Adam Smith
#ifndef menu_
#define menu_
#include <iostream>
#include <vector>
#include "BSTree.h"
#include "functions.h"
#include "data.h"
using namespace std;

//Menu functions
void mainMenu();//Implement While loops and sub menus within
void addRecord(Data *database);
void deleteRecord(Data *database);
void searchforRecord();
void modifyRecord();
void outputRecord();
void outfile(string filename);


#endif