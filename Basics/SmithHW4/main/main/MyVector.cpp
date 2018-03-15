// Adam Smith
// My Vector HW4
#include <iostream>
#include <string>
#include "MyVector.h"
using namespace std;
using namespace HW4;
HW4::MyVector::MyVector()//Default Constructor
{
}

T HW4::MyVector::operator[](int index)
{
	return vec[index];
}

void HW4::MyVector::pop_back()//function erases last item in vector
{
	T* temp;
	temp = new T[vsize - 1];
	int i;
	for (i = 0; i < vsize; i++) {
		temp[i] = vec[i];
	}
	delete[]vec;//deletes the new object since were are done with it
	vec = temp;
	vsize--;//decreases size by 1 because 1 item was removed from vector
}

void HW4::MyVector::push_back(T value)
{
	T* temp;// = vec;
	if (empty()) {//When there is nothing in the vector
		vec = new T[1];//creates a new object
		vec[0] = value;
	}
	else {//when there is something in the vector
		temp = new T[vsize + 1];
		int i;
		for (i = 0; i < vsize; i++) {
			temp[i] = vec[i];
		}
		temp[i] = value;
		delete[]vec;//deletes since done using
		vec = temp;
	}
	vsize++;//increases size by one because one thing was added
}

int HW4::MyVector::size()
{
	return vsize;//number of items in the vector
}

bool HW4::MyVector::empty()
{
	if (vec != nullptr)//when vec is equal to something
		return false;//vector is not empty
	else//when vec is equal to nullptr
		return true;//vector is empty
}

int HW4::MyVector::search(T Value)
{
	for (int i = 0; i < vsize; i++) {
		if (vec[i] == Value) {
			cout << Value << " was found at position "<< i+1<<endl;
		}
		/*else if (vec[i] != Value)
			//cout << Value << " was not found at position "<< i+1<<endl;*/
	}
	return 0;
}

void HW4::MyVector::display()
{
	for (int i = 0; i < vsize; i++)
		cout << vec[i];//Displays contents of vector
}
