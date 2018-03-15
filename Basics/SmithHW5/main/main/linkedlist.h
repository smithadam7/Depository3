//Adam Smith
#ifndef LinkedList_
#define LinkedList_
#include <iostream>
#include <fstream>
#include "Node.h"
using namespace std;

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	bool insertAtFront();
	bool insertBeforePosition(int index);
	bool insertAtBack(); 
	bool deleteAtFront();
	bool deleteBeforePosition(int index);
	bool deleteAtBack();
	void display();
	bool insertFromFileL1();
	bool insertFromFileL2();
	//friend LinkedList operator + (const LinkedList lhs, const LinkedList rhs);
	//friend LinkedList operator - (const LinkedList& lhs, const LinkedList& rhs);
	LinkedList operator +(const LinkedList&headA);
	LinkedList operator -(const LinkedList&headA);
private:
	Node *headPtr;
	int listLength;
};

#endif