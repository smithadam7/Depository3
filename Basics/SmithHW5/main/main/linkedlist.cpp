// Adam Smith
#include "linkedlist.h"
#include <string>

LinkedList::LinkedList()
{
	headPtr = nullptr;
	listLength = 0;
}

LinkedList::~LinkedList()
{
	/*Node *deletedNode = headPtr->nextPtr;

	headPtr->nextPtr = headPtr->nextPtr->nextPtr;
	delete deletedNode;*/

	/*Node* deletedNode = headPtr;
	while (headPtr != nullptr) {
		headPtr = headPtr->nextPtr;
		//Returns node to system memory
		deletedNode->nextPtr = nullptr;
		delete deletedNode;
		deletedNode = headPtr;
	}*/
	/*Node* temp=headPtr;
	while (headPtr != nullptr)
	{
		temp = headPtr->nextPtr;
		delete headPtr;
		headPtr = temp;
	}*/

	/*Node *current = this->headPtr;
	Node *next1;
	while (current != 0) {
		next1 = current->nextPtr;
		delete current;
		current = next1;
	}*/
	//listLength = 0;
}

bool LinkedList::insertAtFront()
{
	Node* newNode1 = new Node();
	char temp;
	cout << "Enter a char\n";//guiding users 
	cin >> temp;
	newNode1->data = temp;// reads in the chars
	newNode1->nextPtr = headPtr;// a new link
	headPtr = newNode1;
	listLength++;
	return true;//The Method is always successful
}

bool LinkedList::insertBeforePosition(int index)
{
	Node* newNode = new Node();
	Node* linker = headPtr;
	char temp;
	cout << "Enter char: ";//telling user what to do
	cin >> temp;//reading in char from user
	newNode->data = temp;//setting the char from user into the node
	if (index <= 0 || index > listLength )//in case the user is dumb
	{
		cout << "Error: Position not in list\n";
		return false;
	}
	if (index == 1) {//if the index is at the front
		newNode->nextPtr = headPtr;
		headPtr = newNode;
		listLength++;
		return true;
	}
	if (index == listLength) {//if the index is at the back
		Node* ptr = headPtr;
		while (ptr->nextPtr != nullptr)
			ptr = ptr->nextPtr;//goes to end of linked list
		ptr->nextPtr = newNode;
		listLength++;
		return true;
	}
	Node* temp2 = headPtr;
	for (int i = 0; i < index -2; i++)//finds the exact index
		temp2 = temp2->nextPtr;//inserts new data
	newNode->nextPtr = temp2->nextPtr;
	temp2->nextPtr = newNode;
    listLength++;//increases size of linkedlist
	return true;
}

bool LinkedList::insertAtBack()
{
	if (listLength == 0) {//wont add if there is no back
		cout << "List is empty\n";
		return false;
	}
	char temp;
	Node* ptr = headPtr;
	cout << "Enter a char to put at the end: ";//telling user what to do
	cin >> temp;
	Node* newNode = new Node();
	newNode->data = temp;//sets data at node equal to user input
	while (ptr->nextPtr != nullptr)
		ptr = ptr->nextPtr;//goes to end of linked list
	ptr->nextPtr = newNode;
	listLength++;
	return true;
}

bool LinkedList::deleteAtFront()
{
	if (headPtr != nullptr) {//goes until end of list
		Node* temp = headPtr->nextPtr;
		delete headPtr;
		headPtr = temp;
		listLength--;
		return true;
	}
	else//when the list is dysfunctional
		return false;
}

bool LinkedList::deleteBeforePosition(int index)
{
	Node* temp1 = headPtr;
	if (index <= 0 || index > listLength)
	{
		cout << "Error: Position not in list\n";//in case of user error
		return false;
	}
	if (index == 1) {//when index is at beginning
		headPtr=temp1->nextPtr;
		free(temp1);
		listLength--;//decrements the list length
		return true;
	}
	for (int i = 0; i < index - 2; i++)
		temp1 = temp1->nextPtr;//locates node at index
	Node* temp2 = temp1->nextPtr;//this is the node at index
	temp1->nextPtr = temp2->nextPtr;//the new node in index
	delete temp2;
	listLength--;
	return true;
}

bool LinkedList::deleteAtBack()
{
	if (listLength == 0){//if list is empty
		cout << "List is empty\n";
		return false;
}
	if (headPtr->nextPtr == nullptr) {//when list has 1 node
		delete headPtr;
		headPtr = nullptr;
	}
	else {
		Node* beforend = headPtr;
		Node* endPtr = headPtr->nextPtr;
		while (endPtr->nextPtr != nullptr) {//goes until end of list
			beforend = endPtr;//sets new endptr
			endPtr = endPtr->nextPtr;
		}
		delete endPtr;//deletes last node
		beforend->nextPtr = nullptr;
	}
	listLength--;
	return true;
}

void LinkedList::display()
{
	Node* temp = headPtr;
	while (temp != nullptr) {//goes until end of list
		cout << temp->data;
		if (temp->nextPtr != nullptr)
			cout << " ";
		temp = temp->nextPtr;//goes to next node
	}
	//delete temp;
	//free(temp); other way of writing
}

bool LinkedList::insertFromFileL1()
{
	ifstream infile;
	char temp;
	string mm;
	infile.open("input.txt");// opens the file
	while (!infile.eof()) {
		getline(infile, mm);
		for (int i = mm.size()-1; i > -1; i--) {
			Node* newNode1 = new Node();//creates node for each char
			temp = mm[i];
			newNode1->data = temp;// reads in the chars
			newNode1->nextPtr = headPtr;
			headPtr = newNode1;
			listLength++;
		}
		getline(infile, mm);//ignore the second row
	}
	infile.close();
	return true;//The Method is always successful
}

bool LinkedList::insertFromFileL2()
{
	ifstream infile;
	char temp;
	string mm;
	infile.open("input.txt");// opens the file
	while (!infile.eof()) {
		getline(infile, mm);//ignore the first row
		getline(infile, mm);
		for (int i = mm.size()-1; i > -1; i--) {
			Node* newNode1 = new Node();//creates node for each char
			temp = mm[i];
			newNode1->data = temp;// reads in the chars
			newNode1->nextPtr = headPtr;
			headPtr = newNode1;
			listLength++;
		}
	}
	infile.close();
	return true;//The Method is always successful
}

LinkedList LinkedList::operator+(const LinkedList & headA)
{
	LinkedList templist;//this is the result list
	Node * temp = headPtr;//first list
	while (temp != nullptr) {//goes until end of list
		Node* next1 = new Node();//creates node for each char
		next1->data = temp->data;
		next1->nextPtr = headPtr;
		templist.headPtr = next1->nextPtr;//puts it in templist
		temp = temp->nextPtr;//goes to next node
		templist.listLength++;
	}
	Node * temp2 = headA.headPtr;//second list
	while (temp2 != nullptr) {//goes until end of list
		Node* next1 = new Node();//creates node for each char
		next1->data = temp2->data;
		next1->nextPtr = templist.headPtr;
		templist.headPtr = next1;
		temp2 = temp2->nextPtr;//goes to next node
		templist.listLength++;
	}
	return templist;
}

LinkedList LinkedList::operator-(const LinkedList & headA)
{
	LinkedList templist;//this is the result list
	Node* temp = headPtr;//start of the first list
	Node* curB = headA.headPtr;// the start of the second list
	int i = 0;
	while (temp != nullptr) {//goes until end of list
		i = 0;
		curB = headA.headPtr;
		while (curB != nullptr) {//goes until end of list
			if (temp->data == curB->data) {
				i++;
			}
			curB = curB->nextPtr;//goes to next in second list
		}
		if (i < 1) {//when the data is not equal
			Node* next1 = new Node();//creates a new node 
			next1->data = temp->data;//matches the data
			next1->nextPtr = templist.headPtr;
			templist.headPtr = next1;//inserts chars
			templist.listLength++;
		}
		temp = temp->nextPtr;//goes to next node
	}
	return templist;
}

