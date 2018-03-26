#ifndef NODE_
#define NODE_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//A struct to hold data for affiliates
struct Affiliate {
	string name;
	string phone;
	string email;
	string info;
};
//A struct to hold the data for each record
struct Record {
	string ID;
	string firstName;
	string middleName;
	string lastName;
	string companyName;
	string homePhone;
	string officePhone;
	string email;
	string mobilePhone;
	string address;
	string city;
	string state;
	string zip;
	string country;
	vector<string> affiliates;//vector containing a record's affiliates
};

// A generic tree node class

//Binary Tree Node
class Node {
private:
	string key;
	Node* left;
	Node* right;
	Node* parent;
public:
	Node() { key = ""; left = nullptr; right = nullptr; parent = nullptr; };
	void setKey(string aKey) { key = aKey; };
	void setLeft(Node* aLeft) { left = aLeft; };
	void setRight(Node* aRight) { right = aRight; };
	void setParent(Node* aParent) { parent = aParent; };
	string Key() { return key; };
	Node* Left() { return left; };
	Node* Right() { return right; };
	Node* Parent() { return parent; };

	//Custom Functions
	//void setID(string ID) { ndata.ID = ID; };
	//string getID() { return ndata.ID; };
	Record* entry = new Record();
};



#endif