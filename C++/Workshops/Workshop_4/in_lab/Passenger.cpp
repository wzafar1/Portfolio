/*
OOP244 Workshop 4: Passenger database
File: Passenger.cpp
Version 1.0
Date: 08/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include<iostream>
#include <cstring>
#include"Passenger.h"

namespace sict {

  using namespace std;
  //Default Constructor Implementaion

  Passenger::Passenger() {

    setEmpty();

  };

  //Constructor with 2 parameters Implementaion

  Passenger::Passenger(const char* name, const char* address) {

    if (name == nullptr || name[0] == '\0' || address == nullptr || address[0] == '\0') {

      setEmpty();

    }
    else {

      strncpy(m_PassangerName, name, Max_NameLength);
      strncpy(m_Destination, address, Max_NameLength);

    }

  };

  //Functions isEmpty query Implementations

  bool Passenger::isEmpty() const {

    bool check;

    if (m_PassangerName[1] == '\0' || m_Destination[1] == '\0') {

      check = true;

    }
    else {

      check = false;

    }

    return check;

  };

 //Functions display query Implementations

  void Passenger::display() const {

    cout << m_PassangerName << " - " << m_Destination << endl;

  }

  void Passenger::setEmpty() {

    m_PassangerName[1] = '\0';
    m_Destination[1] = '\0';

  }

}