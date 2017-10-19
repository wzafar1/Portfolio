/*
OOP244 Workshop 3: Classes and Privacy
File: w3_at_home.cpp
Version 1.0
Date: 01/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
Description: 
 This workshop demonstrates classes in C++ and 
 how member variables are defined privately, but 
 accessed through public member functions.
*/


#include <iostream>
#include "CRA_Account.h"
using namespace std;
using namespace sict;

int main() {
	CRA_Account myCRA;
	int sin;
	bool quit = false;
	char familyName[MAX_NAME_LENGTH + 1];
	char givenName[MAX_NAME_LENGTH + 1];

	cout << "Canada Revenue Agency Account App" << endl
	     << "=================================" << endl << endl;
	cout << "Please enter your family name: ";
	cin >> familyName;
	cin.ignore();
	cout << "Please enter your given name: ";
	cin >> givenName;
	cin.ignore();

	do {
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
    if (cin.fail() == true) {

      cin.clear();
      cout << "Clearing cin of errors states" << endl;

    } //In order to avoid infinte loop with no data entry allowed, for value greater than MAX_SIN
		cin.ignore();
		if (sin != 0) {
			myCRA.set(familyName, givenName, sin);
			if (!myCRA.isValid()) {
				cout << "Invalid input! Try again." << endl;
			}
			else {
				int year;
				double balance;
				do {
					cout << "Please enter the year of your tax return (0 to quit): ";
					cin >> year;
					cin.ignore();
					if (year != 0) {
						cout << "Please enter the balance owing on your tax return (0 to quit): ";
						cin >> balance;
						cin.ignore();
						myCRA.set(year, balance);
					}
				} while (year != 0);
				quit = true;
			}
		}
		else {
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;

	return 0;
}
