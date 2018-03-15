//Adam Smith
#include "dictionary.h"
#include <fstream>

dictionary::dictionary()//Default Constructor
{
}

int dictionary::searchForward(list<DictEntry>& wordList, wordType & findString)
{
	int searches = 1;
	list<DictEntry>::iterator it;
	for (it = wordList.begin(); it != wordList.end(); it++) {
		if (it->getWord() == findString) {
			return searches;
		}
		else
			searches++;
	}
	if (searches > wordList.size()) {
		return -1;
	}
	else {
		return -1;
	}
}

int dictionary::searchBackward(list<DictEntry>& wordList, wordType & findString)
{
	int searches = 1;
	list<DictEntry>::reverse_iterator rit;
	for (rit = wordList.rbegin(); rit != wordList.rend(); rit++) {
		if (rit->getWord() == findString) {
			return searches;
		}
		else
			searches++;
	}
	if (searches > wordList.size()) {
		return -1;
	}
	else {
		return -1;
	}
}

void dictionary::revPrintList(ostream & output, list<DictEntry>& wordList)
{
	int i=0;
	list<DictEntry>::reverse_iterator rIt;//reverse iterator


	for (rIt= wordList.rbegin(); rIt!=wordList.rend(); rIt++)
	{
		output << rIt->getWord() << endl;
	}
}
void dictionary::readList(istream & input, list<DictEntry>& wordList)
{
	wordType word;
	while (!input.eof())
	{
		getline(input, word);
		DictEntry temp;
		temp.setWord(word);
		wordList.push_back(temp);
	}
}
/*Reading in dictionary file...
Sorting list of entries...
Reading in comparison list...
cat: forward search found in 2 searches
cat:backward search found in 4 searches
dog: forward search found in 3 searches
dog:backward search found in 3 searches
lion: not found in forward search
lion: not found in backward search
zebra: forward search found in 5 searches
zebra:backward search found in 1 searches
Printing reverse alphabetic list to file...*/

/*
Queues notes:
first in first out
front->node->rear->null
insert after last item, delete from first item
to access last element, must get through all others

push queue line
stack cashier 1,2,3
wait for cashiers, how much time each transaction takes
for less than queue size
pop queue
push open cashier stack
wait for cashier, note transaction time
pop cashier
queue<string> qs;
nested loops
clock ticking everytime something happens
*/