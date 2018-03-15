// Adam Smith
// HW5
// Last Modified 02-18-17
// Built and ran successfully on Visual Studio
#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

int main()
{
	LinkedList myList1;//Creates First linked list
	LinkedList myList2;//Creates Second linked list
	LinkedList myList3; //Sum list
	LinkedList myList4; //difference list

	int index;
	int userOption;
	cout << "List 1 and list 2 were read from a file.\n";
	myList1.insertFromFileL1();
	myList2.insertFromFileL2();
	do//This will be the menu for the linked list
	{
		cout << "Please Choose an Option\n"
			<< endl << "1: Display Lists\n2: Add to front\n3: Add at position\n4: Add at back\n5: Delete front\n6: Delete at position\n7: Delete end\n8: Union the lists\n9: Subtract the lists\n10: Exit\n";
		cin >> userOption;
		if (userOption == 1)// Display Lists
		{
			cout << "This is list 1: ";
			myList1.display();
			cout << "\nThis is list 2: ";
			myList2.display();
			cout << "\nThis is list 3: ";
			myList3.display();
			cout << "\nThis is list 4: ";
			myList4.display();
			cout << endl;
		}
		else if (userOption == 2)//Add to front
		{
			myList1.insertAtFront();
		}
		else if (userOption == 3)// Add at position
		{
			cout << "\nEnter an index to insert a char before: ";
			cin >> index;
			myList1.insertBeforePosition(index);
		}
		else if (userOption == 4)// Add at back
		{
			myList1.insertAtBack();
		}
		else if (userOption == 5)// Delete front
		{
			myList1.deleteAtFront();
		}
		else if (userOption == 6)//Delete at position
		{
			cout << "\nEnter an index to delete: ";
			cin >> index;
			myList1.deleteBeforePosition(index);
		}
		else if (userOption == 7)//Delete end
		{
			myList1.deleteAtBack();
		}
		else if (userOption == 8)//Union the lists
		{
			myList3 = myList1 + myList2;
			cout << "List 3 is the union\n";
		}
		else if (userOption == 9)//Subtract the lists
		{
			myList4 = myList1 - myList2;
			cout << "List 4 is the difference\n";
		}
		else if (userOption == 10)//Exit
		{
			break;// exits the program
		}
		else
		{
			cout << userOption << " is not a valid option\n";// if the user puts a different number
		}
	} while (true);// For the menu

	cout << "\nPress enter key to continue\n";
	cin.ignore();
	string hold;
	getline(cin, hold);
    return 0;
}

/*
Notes:
Array or dynamic array: continuous block of memory
Linked Lists: allocate memory for each element seperately and only when necessary
Pointers:
left hand sign of pointer is a pointer to data,
right hand side is new of equivelent data type

memory leak = bad;
cant do pointer math in linked list
array disadvantages: size is fixed and expensive to insert element in middle
Linked Lists: good for when number of elements is unpredicatable
:dynamic
:each node does not necessarily follow the previous one in physical memory
:can be maintained in sorted order by inserting or deleting at point in list
Node is for data and pointers, use struct cuz is better
node headPtr = nullptr;
 currentPtr = new Node;
 dereference the pointer with ->
 currentPtr -> Data;
 default contructor starts pointers at nullPtr
 headPtr = nullptr;
 just pass headPtr in functions
 dont move headPtr
 cannot replace headPtr

 Traversing:
 Node *currentPtr;
 int count = 0;
 cout << "list contains\n";
 for(currentPtr=headPtr;currentPtr!=nullPtr;currentPtr = currentPtr->next)
 {count++;
 cout << currentPtr->data<<endl;}
 
 Creating headPtr:
 in contructor say Node * headPtr = nullPtr;
 outside default constructor say nextPtr = new something

 Searching for a node in linked list:
 currentPtr = headPtr;
 while (currentPtr != nullPtr && currentPtr->data !=target)
 {currentPtr = currentPtr->nextPtr;}

 if(currentPtr != nullptr) found = 1;
 else found =0;

 insertion:
 tmp = new Node;
 tmp->data = x;
 tmp->next = currentPtr->next;
 currentPtr->next =tmp;
OR simply(if Node has a constructor initializing its members)
current->next= new Node(x,current->next);
dont delete yet

 create temp node
 fill temp node
 attach temp node ptr to where it goes and then move currentPtr to temp

 deletion:
 Node *deletedNode =curerntPtr->next;
 current->next= current->next->next;
 delete deletedNode;
*/