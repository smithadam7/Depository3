// Adam Smith
// Final Project
// Last Modified 03-20-17
// Built and ran successfully on Visual Studio
#include <iostream>
#include <string>
#include "BSTree.h"
#include "menu.h"
#include <stdlib.h>
using namespace std;//standard, just like my life

int main()
{
	mainMenu();//Initiates the main menu and reads the file

	string hold;
	cout << "Press enter to continue";
	getline(cin, hold);
	getline(cin, hold);
	return 0;//like everything I strive for
}
//6 .cpp
// sort class and search class
/*
Notes:
depth first goes to maximum level, left right
breadth first goes minimum level

Graphs:
set of vertices and edges
*/