// Adam Smith
#include "stdafx.h"
#include <iostream>
using namespace std;
int tempNum,i;
float sum = 0;
float avg;
typedef int temp[50];
temp name;
int main()
{
	cout << "Please input the number of temperatures to be used\n";
	cin >> tempNum;
	for (i = 1; i < tempNum +1; i++)// Fills the array with user input
	{
		cout << "Input temperature " << i << ": \n";
		cin >> name[i];
	}

	for (int pos = 0; pos < tempNum+1; pos++)// Calculates average temp
		{
			sum = sum + name[pos];
			avg = sum / tempNum;
		}
	cout << "The average temperature is " << avg << endl;

	int Hvalue = name[0];// calc highest value in array
	for (int j = 1; j < tempNum + 1; j++)
	{
		if (name[j] > Hvalue)
			Hvalue = name[j];
	}
	cout << "The highest temperature is " << Hvalue << endl;

	int lvalue = name[1];//calc lowest value in array
	for (int k = 1; k < tempNum + 1; k++)
	{
		if (name[k] < lvalue)
			lvalue = name[k];
	}
	cout << "The lowest temperature is " << lvalue << endl;
	system("pause");
    return 0;
}

