#include "guess.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
Guess::Guess(vector<int> irandomVector,vector<int> ifoundVector)
{
	vector<int> randomVector = irandomVector;
	vector<int> foundVector = ifoundVector;
}
Guess::Guess() {
	vector<int>randomVector = randomVector;
	int numOfRandNums = 0;
}
void Guess::startGuess(vector<int> &irandomVector, int &numOfRandNums, vector<int> &ifoundVector) {
	vector<int> RandomNums;
	char hold;
	char play = 'y';
	int range, guesses;
	int guessNum = 0;
	int correct = 0;
	do {
		createRandomNumber(randomVector,numOfRandNums,foundVector);
		do {
			foundVector.clear();
			correct = 0;
			guessNum += 1;
			cout << "Try guess the numbers that were produced. \n";
			for (int i = 0; i < numOfRandNums; i++) {
				cin >> guesses;
				foundVector.push_back(guesses);
			}
			for (int j = 0; j < numOfRandNums; j++) {
				cout << randomVector[j] << endl;
				for (int p = 0; p < numOfRandNums; p++) {
					if (randomVector[j] == foundVector[p]) {
						correct += 1;
					}
				}
			}
			cout << correct << " of your guesses were correct.\n";
		} while ((correct != numOfRandNums) && (guessNum < 3));
		if(correct == numOfRandNums)
			cout << "You are correct!\n";
		else {
			cout << "You lost\n These were the correct numbers: ";
			for (int g = 0; g < numOfRandNums; g++)
				cout << randomVector[g]<< " ";
		}
		randomVector.clear();// Resets the vector in case the user plays again
		foundVector.clear();
		guessNum = 0;
		cout << "\nPlay again ? y or n\n";
		cin >> play;
	} while ((play == 'Y') || (play == 'y'));
	cout << "Goodbye!\n";
}
void Guess::createRandomNumber(vector<int> &irandomVector, int &numOfRandNums, vector<int> &foundVector) {
	int range,k,hold2;
	srand(time(NULL));//sets the rand seed based on time
	cout << "How many random numbers would you like? ";
	cin >> numOfRandNums;
	cout << endl << "What is the desired range? 1 to ";
	cin >> range ;
	cout << endl;
	for (int i = 0; i < numOfRandNums; i++) {
		irandomVector.push_back(rand()%range+1);
		cout << irandomVector[i];
	}
}