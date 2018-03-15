// Uses time for the seed of a random number
#include <iostream>
#include "stdafx.h"
#include <chrono>
#include <stdlib.h>// for rand
#include <ctime>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::steady_clock;
int main()
{
	for (int i = 1; i < 10; i++) {
		_sleep(1000);
		//time_t result = time(nullptr);
		/*cout << "This is the seed based off of seconds: " << result << endl;
		int randNum1,randNum2;
		srand(time(NULL));
		randNum1 = rand() % 6;
		cout << "This is the random number made from the seed: " << randNum1 << endl;
		srand(rand());
		randNum2 = rand();// % 1000;
		cout << "This is the random number made from a random seed: " << randNum2 << endl;*/
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		cout << high_resolution_clock::now() << endl;
		//auto start = std::chrono::high_resolution_clock::time_point();
	}

	int hold,pause;
	cin >> hold;
    return 0;
}

