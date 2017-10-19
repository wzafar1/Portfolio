/*
OOP244 Workshop 3: Classes and Privacy
File: CRA_Account.cpp
Version 1.0
Date: 01/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

namespace sict {

  using namespace std;

  void CRA_Account::set(const char* familyName , const char* givenName, int sin) {

    if (sin <= MAX_SIN && sin >= MIN_SIN) {

      strncpy(m_FamilyName, familyName,MAX_NAME_LENGTH);
      m_FamilyName[MAX_NAME_LENGTH] = 0;
      strncpy(m_GivenName, givenName,MAX_NAME_LENGTH);
      m_GivenName[MAX_NAME_LENGTH] = 0;
      m_Sin = sin;


    }
    else {

      m_Sin = 0;

    }

  }
  bool CRA_Account::isValid() const {


    if (m_Sin <= MAX_SIN && m_Sin >= MIN_SIN) {

      return true;

    }
    else {

      return false;

    }

  }
  void CRA_Account::display() const {

    if (m_Sin > 0) {

      cout << "Family Name: " << m_FamilyName << endl;
      cout << "Given Name : " << m_GivenName << endl;
      cout << "CRA Account: " << m_Sin << endl;

    }
    else {

      cout << "Account object is empty!" << endl;

    }

  }

}