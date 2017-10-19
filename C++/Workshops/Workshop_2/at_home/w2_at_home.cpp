/*
OOP244 Workshop 2: Dynamic Memory
File w2_at_home.cpp
Version 1.0
Date 25/05/2017
Author wzafar1
Seneca Emial
wzafar1@myseneca.ca
*/


#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    int i;

    Kingdom* pKingdom = nullptr;
    Kingdom* temp = nullptr;

    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    if (count < 1) return 1;

    pKingdom = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;

        read(pKingdom[i]);
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // expanding the array of Kingdoms by 1 element

    temp = new Kingdom[count + 1];
    for (i = 0; i < count; i++) {

      temp[i] = pKingdom[i];

    }

    delete[] pKingdom;
    
    pKingdom = temp;
    
    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Kingdom #" << count + 1 << ": " << endl;
   
    read(pKingdom[count]);
    count++;
    cout << "==========\n" << endl;

    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;

    delete[] pKingdom;

    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

    cout << "Enter the name of the kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
