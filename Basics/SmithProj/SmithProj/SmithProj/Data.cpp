//Adam Smith
//Contains the functions that sort the vector by specification
#include "data.h"
void Data::sortID(vector<Node*>& nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;
		do
		{
			swap = false;
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->ID > nodePtrs[count + 1]->entry->ID)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
	
}
//use iterative sort method to sort each vector low to high/a-z
//pass in the corresponding vectors
void Data::sortFirstName(vector<Node*>&firstName)
{
	cout << "Sorting...\n";
	if (firstName.size() < 1) {
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp ;
		do
		{
			swap = false;
			for (int count = 0; count < firstName.size() - 1; count++)
			{
				if (firstName[count]->entry->firstName > firstName[count + 1]->entry->firstName)
				{
					temp = firstName[count];
					firstName[count] = firstName[count + 1];
					firstName[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortMiddleName(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;
		do
		{
			swap = false;
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->middleName > nodePtrs[count + 1]->entry->middleName)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortLastName(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->lastName > nodePtrs[count + 1]->entry->lastName)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortCompanyName(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->companyName > nodePtrs[count + 1]->entry->companyName)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortHomePhone(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->homePhone > nodePtrs[count + 1]->entry->homePhone)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortOfficePhone(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->officePhone > nodePtrs[count + 1]->entry->officePhone)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortEmail(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->email > nodePtrs[count + 1]->entry->email)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortMobilePhone(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->mobilePhone > nodePtrs[count + 1]->entry->mobilePhone)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortAddress(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->address > nodePtrs[count + 1]->entry->address)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortCity(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->city > nodePtrs[count + 1]->entry->city)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortState(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->state > nodePtrs[count + 1]->entry->state)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortZip(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->zip > nodePtrs[count + 1]->entry->zip)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}

void Data::sortCountry(vector<Node*>&nodePtrs)
{
	cout << "Sorting...\n";
	if (nodePtrs.size() < 1) {//if the vector is empty
		cout << "No records found." << endl;
	}
	else {
		bool swap;
		Node* temp;//temporary node for swapping
		do
		{//Swap method
			swap = false;
			//Steps through vector and rearranges nodes
			for (int count = 0; count < nodePtrs.size() - 1; count++)
			{
				if (nodePtrs[count]->entry->country > nodePtrs[count + 1]->entry->country)
				{
					temp = nodePtrs[count];
					nodePtrs[count] = nodePtrs[count + 1];
					nodePtrs[count + 1] = temp;
					swap = true;
				}
			}
		} while (swap);
		cout << "Sort Complete\n";
	}
}