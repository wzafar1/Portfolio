/*
OOP244 Workshop 2: Dynamic Memory
File w2_in_lab.cpp
Version 1.0
Date 25/05/2017
Author wzafar1
Seneca Emial
wzafar1@myseneca.ca
*/

#include<iostream>
#include"Kingdom.h"

namespace sict {

  void display( const Kingdom &k) {

    cout << k.m_name << ", population " << k.m_population << endl;

  }

}