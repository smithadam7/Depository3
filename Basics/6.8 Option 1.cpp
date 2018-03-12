// Adam Smith Lab6.2, 6.8 Option 1
#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;

void convertTomiles(float kilometers);
void convertToKilometers(float miles);
int userOption;
int main()
{
	float miles;
	float kilometers;
	
	do
	{
		cout << "Please input\n" << "	1 Convert miles to kilometers\n" << "	2 Convert kilometers to miles\n" << "	3 Quit\n";
		cin >> userOption;
		if (userOption == 1)
		{
			cout << " Please input miles to convert\n";
			cin >> miles;
			convertToKilometers(miles);
		}
		else if (userOption == 2)
		{
			cout << " Please input kilometers to convert\n";
			cin >> kilometers;
			convertTomiles(kilometers);
		}
		else {
			cout << "Bye\n";
		}

	} while (userOption != 3);
	system("pause");
    return 0;
}

void convertTomiles(float kilometers)
{
	cout << fixed << showpoint << setprecision(3);
	cout << endl << kilometers << " kilometers = ";
	kilometers = kilometers * .621;
	cout << kilometers << " miles\n";
}
void convertToKilometers(float miles)
{
	cout << fixed << showpoint << setprecision(1);
	cout << endl << miles << " miles = ";
	miles = miles * 1.61;
	cout << miles << " kilometers\n";
	
}