#ifndef guess_h
#define guess_h
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Guess {
private:
	vector<int> randomVector; // will contain n random numbers
	vector<int> foundVector; // create it with n numbers = 0 for not found
public:
	Guess();
	Guess(vector<int> irandomVector, vector<int> ifoundVector);
	void startGuess(vector<int> &irandomVector, int &numOfRandNums, vector<int> &ifoundVector);
	int numOfRandNums ;
	void createRandomNumber(vector<int> &irandomVector,int &numOfRandNums, vector<int> &ifoundVector);
};
#endif 