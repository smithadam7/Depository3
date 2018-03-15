// Adam Smith
// HW1 Guessing Game
// Built and ran succeessfully on visual studios
// Last Modified on 1-20-17
//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>//for rand
#include "guess.h"
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int main()
{
	char hold;
	vector<int> placeHolderVector;
	vector<int> foundVector;
	int num=0;
	Guess game;
	game.startGuess(placeHolderVector,num,foundVector);
	cin >> hold;
    return 0;
}

/*
$ make clean
$ ls
$ make
$ dos2unix *.cpp
$ dos2unix *.h
$ dos2unix makefile
$ make //looks for makefile in directory and does the config for it
$ ./name // or ./hw1 
$ vi main.cpp // shows what is in main.cpp

*/