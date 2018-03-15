// Adam Smith
// PA1
#include "GameOfLife.h"
#include <iostream>
using namespace std;
using namespace csci2312;

Cell::Cell() :state(false) {};

Cell::Cell(bool iState) {
	state = iState;
}

Cell::~Cell() {

}

bool Cell::getState() const
{
	return state;
} 

void Cell::setState(bool newState) {
	state = newState;
	//face = newState;
}

char Cell::getFace() const
{
	return face;
}

GameOfLife::GameOfLife() : boardSize(MAX_BOARD) {

}

GameOfLife::GameOfLife(size_t iboardSize){
	boardSize = iboardSize;
}

GameOfLife::~GameOfLife(){

}

int GameOfLife::seedBoard(string fileName, char urrentLife[32][32]) {
	int seeds;
	ifstream infile;
	infile.open(fileName);// opens the file 
	while (!infile.eof()) {
		infile >> seeds;// reads in the seed
	}
	infile.close();
	cout << "File Read Successfully" << endl;
	if (seeds == seeds) {
		seedBoard(seeds,urrentLife);
		return 0;
	}
	else {
		cout << "A failure occured.";
		return 1;
	}
}

void GameOfLife::seedBoard(size_t seeds, char urrentLife[32][32]) {
	srand(seeds);
	GameOfLife game;
	Cell *temp = new Cell();
	int n;
	for (int i = 0; i < MAX_BOARD+2 ; i++)
		for (int j = 0; j < MAX_BOARD+2; j++) {
			n = rand() % 2;
			//Cell().setState(n);
			if (n == 1) {
				Cell().setState(1);
				game.currentLife[i][j].setState(1);
				game.currentLife[i][j].face = 'o';
				urrentLife[i][j] = 'o';
			}
			else if (n == 0) {
				Cell().setState(0);
				currentLife[i][j].setState(0);
				currentLife[i][j].face = '-';
				urrentLife[i][j] = '-';
			}
			else
				cout << "failure to read file";
			// These form the halo around the game
			urrentLife[0][j] = '*';
			urrentLife[i][0] = '*';
			urrentLife[i][MAX_BOARD + 1] = '*';
			urrentLife[MAX_BOARD + 1][j] = '*';
		}
}

void GameOfLife::run() {

}

void GameOfLife::run(unsigned int numberOfIterations, char urrentLife[32][32]) {
	string filename;
	//this is the name of the txt file that will be passed into the function to read it
	filename = "SeedPattern.txt";
	GameOfLife().seedBoard(filename,urrentLife);
	for (int q = 0; q < numberOfIterations; q++)
	{
		//creates a game state for each iteration
		live(urrentLife);
		cout << endl;
		
	}
}

void csci2312::GameOfLife::live(char urrentLife[32][32])
{
	unsigned int neighbors;//for counting number of neighbors surrounding any spot
	char temp[MAX_BOARD+2][MAX_BOARD+2];
	Cell anew;
	GameOfLife game;
	for (int m = 0; m < MAX_BOARD + 2; m++) {
		for (int n = 0; n < MAX_BOARD + 2; n++) {
			//outputs current board to screen
			cout << urrentLife[m][n] << " ";
			temp[m][n] = urrentLife[m][n];
		}
		cout << endl;
	}
	for (int m = 0; m < MAX_BOARD+2; m++)
		for (int n = 0; n < MAX_BOARD+2; n++) {
			neighbors = 0;
			//Begin counting number of neighbors:
			if (urrentLife[m - 1][n - 1] == 'o') neighbors += 1;
			if (urrentLife[m - 1][n] == 'o') neighbors += 1;
			if (urrentLife[m - 1][n + 1] == 'o') neighbors += 1;
			if (urrentLife[m][n - 1] == 'o') neighbors += 1;
			if (urrentLife[m][n + 1] == 'o') neighbors += 1;
			if (urrentLife[m + 1][n - 1] == 'o') neighbors += 1;
			if (urrentLife[m + 1][n] == 'o') neighbors += 1;
			if (urrentLife[m + 1][n + 1] == 'o') neighbors += 1;

			//Underpopulation
			if (urrentLife[m][n] == 'o' && neighbors < 2)
				temp[m][n] = '-';
			//Overpopulation
			else if (urrentLife[m][n] == 'o' && neighbors > 3)
				temp[m][n] = '-';
			//Happy Middle
			else if (urrentLife[m][n] == 'o' && (neighbors == 2 || neighbors == 3))
				temp[m][n] = 'o';
			//A new life
			else if (urrentLife[m][n] == '-' && neighbors == 3)
				temp[m][n] = 'o';
		}
	for (int m = 0; m < MAX_BOARD+2; m++)
		for (int n = 0; n < MAX_BOARD+2; n++) {
			urrentLife[m][n] = temp[m][n];
			//Sets the new board
		}
}

bool csci2312::GameOfLife::executeRules(unsigned int countAlive, bool currentState)
{
	return false;
}

ostream & csci2312::operator<<(ostream & out, const GameOfLife & board)
{
	/*for (int i = 0; i < GameOfLife().MAX_BOARD; i++)
		for (int j = 0; j < GameOfLife().MAX_BOARD; j++) {
			out << GameOfLife().currentLife[i][j] << " ";
		}*/
	return out;
}

istream & csci2312::operator >> (istream & in, const GameOfLife & board)
{
	return in;
}

ostream & csci2312::operator<<(ostream & out, const Cell & cell)
{
	return out;
}
