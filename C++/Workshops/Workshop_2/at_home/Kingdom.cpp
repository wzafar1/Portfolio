/*
OOP244 Workshop 2: Dynamic Memory
File kingdom.cpp
Version 1.0
Date 25/05/2017
Author wzafar1
Seneca Emial
wzafar1@myseneca.ca
*/

#include<iostream>
#include"Kingdom.h"

using namespace std;

namespace sict {

  void display( const Kingdom &k) {

    cout << k.m_name << ", population " << k.m_population << endl;

  }

  void display(const Kingdom k[], int count) {

    int i;
    int t_population = 0;

    cout << "------------------------------" << endl
        << "Kingdoms of SICT" << endl
        << "------------------------------" << endl;

    for (i = 0; i < count; i++) {

      cout << i + 1 << ". ";
      display(k[i]);
      t_population = t_population + k[i].m_population;

    }

    cout << "------------------------------" << endl
        << "Total population of SICT: " << t_population << endl
        << "------------------------------" << endl;

  }

}