//Adam Smith
#ifndef data_
#define data_
#include <iostream>
#include <vector>
#include "BSTree.h"
using namespace std;

//This class is for containing and sorting the data 
class Data {
private:
//Nothing is private
public:
	BSTree * tree1 = new BSTree();//Tree is made by ID number
	vector<Node*>nodePtrVec;
	
	//These functions sort their coresponding vector to search later
	void sortID(vector<Node*>&nodePtrs);
	void sortFirstName(vector<Node*>&nodePtrs);
	void sortMiddleName(vector<Node*>&nodePtrs);
	void sortLastName(vector<Node*>&nodePtrs);
	void sortCompanyName(vector<Node*>&nodePtrs);
	void sortHomePhone(vector<Node*>&nodePtrs);
	void sortOfficePhone(vector<Node*>&nodePtrs);
	void sortEmail(vector<Node*>&nodePtrs);
	void sortMobilePhone(vector<Node*>&nodePtrs);
	void sortAddress(vector<Node*>&nodePtrs);
	void sortCity(vector<Node*>&nodePtrs);
	void sortState(vector<Node*>&nodePtrs);
	void sortZip(vector<Node*>&nodePtrs);
	void sortCountry(vector<Node*>&nodePtrs);
};
#endif