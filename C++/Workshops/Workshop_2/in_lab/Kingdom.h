/*
OOP244 Workshop 2: Dynamic Memory
File w2_in_lab.cpp
Version 1.0
Date 25/05/2017
Author wzafar1
Seneca Emial
wzafar1@myseneca.ca
*/

#ifndef ICT_KINGDOM_H
#define ICT_KINGDOM_H

using namespace std;

namespace sict {

  struct Kingdom{

    char m_name[32];
    int m_population;

  };

  void display( const Kingdom &k);


}


#endif 

