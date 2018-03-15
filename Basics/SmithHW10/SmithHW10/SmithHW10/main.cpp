// Adam Smith
// HW10
// Last Modified 04-19-17
// Built and ran successfully on Visual Studio and csegrid
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cctype>
#include <locale>
using namespace std;

//The string hasher
hash<string>hashStr;
//The dict array
list<string> dicArray[1373];
//Functions to read the file and perform hash
void openFile(string filename);
void openDict(string filename);
//Keeps track of number of words in the dictionary
int numOfWordsInDictionary=0;
//Keeps track of number of words in the file to spell check
int wordCount = 0;

int main()
{
	//Reads in the dictionary
	openDict("dict.dat");
	string filename;
	cout << "Enter filename to check: " << endl;
	cin >> filename;
	//Spell checks user file
	openFile(filename);


	string hold;
	cout << "Press enter to continue";
	getline(cin, hold);
	getline(cin, hold);
	return 0;
}

void openFile(string filename)
{
	ifstream infile;
	string p;
	int g = 0;//spelled correct
	int wrong = 0;//spelled wrong
	int hashnum;
	infile.open(filename);
	if (infile.fail())cout << "File doesn't exist.\n";
	while (!infile.eof()) {
		infile >> p;
		string word;
		for (unsigned int i = 0; i < p.size(); i++) {
			if (isalnum(p[i]) != 0) {
				word.push_back(tolower(p[i], std::locale()));
			}
		}
		hashnum = hashStr(word) %1373;
		bool found = false;
		//Iterator to traverse each linked list
			std::list<std::string>::iterator iter = dicArray[hashnum].begin();
			while (iter != dicArray[hashnum].end())
			{
				//If word matches
					if (*iter == word) {
						g++;
						found = true;
					}
					iter++;
			}
			//When word is not found in the dictionary
			if (found == false) {
				wrong++;
				cout << "Possibly Mispelled: " << word<<endl;
			}
			wordCount++;
	}
	//Neat way to read out
	//cout << "Total words in dictionary: " << numOfWordsInDictionary << endl;
	//cout << "Total words in file: " << wordCount << endl;
	//cout << "Total Mispelled: " << wrong << endl;

	//Wanted read out style
	cout << numOfWordsInDictionary << " dictionary words, " << wordCount << " words in file, " << wrong << " mispelled\n";

}
void openDict(string filename)
{
	ifstream infile;
	string p;//temporary string for reading in
	int hashnum;
	infile.open(filename);//opens file
	if (infile.fail())cout << "File doesn't exist.\n";
	while (!infile.eof()) {
		getline(infile, p);
		hashnum = hashStr(p) % 1373;//performs the hash and places in a bucket in the array
		dicArray[hashnum].push_back(p);
		numOfWordsInDictionary++;
	}
	cout << "Dictionary Read from File containing: " << numOfWordsInDictionary << " words.\n";
}
