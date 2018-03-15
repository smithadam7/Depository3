// Adam Smith
// HW2 Array Bag
// Built and ran succeessfully on visual studios
// Last Modified on 1-28-17
#include "stdafx.h"
//#include <iostream>
#include "ArrayBag.h"
#include "SetFunctions.h"
using namespace std;

int main()
{
	ArrayBag bag1,bag2,bagSum,bagDiff;
	int hold;
	readIn(bag1, bag2);
	printArray(bag1,bag2);
	bagSum = bag1 + bag2;
	printBag3(bagSum);
	bagDiff = bag2 - bag1;
	printBag4(bagDiff);
	cin >> hold;
    return 0;
}

// on final
/*
container class properties
create an empty container(via constructor)
insert a new object into the container pushback
remove an object from the container popback
report the number of objects currently in the container .size
empty the container of all objects .clear
provide access to stored objects []
sort the elements(optional)


*/