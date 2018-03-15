//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <iostream>
using namespace std;
ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains



std::vector<ItemType> ArrayBag::toVector() const
{
    std::vector<ItemType> ArrayBagContents;
	for (int i = 0; i < itemCount; i++)
                ArrayBagContents.push_back(items[i]);
   return ArrayBagContents;
}  // end toVector

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

ArrayBag operator+ (const ArrayBag& lhs, const ArrayBag& rhs) //add two arrays
{
	ArrayBag temp;
	for (int i = 0; i < lhs.getCurrentSize(); i++)
	{
		int r = lhs.items[i];
		temp.add(r);
	}
	for (int i = 0; i < rhs.getCurrentSize(); i++)
	{
		int r = rhs.items[i];
		temp.add(r);
	}
	return temp;
}
ArrayBag operator- (const ArrayBag& lhs,const ArrayBag& rhs) //subtrct a from b or bag1 from bag2 b2-b1
{
	ArrayBag temp;
	for (int i = 0; i < lhs.getCurrentSize(); i++)
	{
		int r = lhs.items[i];
		int isame = 0;
		//temp.add(r);
		for (int j = 0; j < rhs.getCurrentSize(); j++) {
			if (lhs.items[i] == rhs.items[j]) {
				isame = 1;
				break;
			}
		}
		if (!isame)
			temp.add(r);
	}
	return temp;
}

void ArrayBag::getIndexOut(const ItemType& target) //Prints out items in a bag
{
	for (int i = 0; i < itemCount; i++)
		cout << items[i];
}
