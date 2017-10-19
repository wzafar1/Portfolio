/*
OOP244 Workshop 3: Classes and Privacy
File: CRA_Account.cpp
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
#include <cstring>
#include "CRA_Account.h"

namespace sict {

  using namespace std;

  void CRA_Account::set(const char* familyName , const char* givenName, int sin) {

    m_Sin = sin;

   
    if (CRA_Account::isValid()==true) {

      strncpy(m_FamilyName, familyName,MAX_NAME_LENGTH);
      m_FamilyName[MAX_NAME_LENGTH] = 0;
      
      strncpy(m_GivenName, givenName,MAX_NAME_LENGTH);
      m_GivenName[MAX_NAME_LENGTH] = 0;
      
      m_years = 0;



    }
    else {

      m_Sin = 0;

    }

  }
 
  bool CRA_Account::isValid() const {

    int s_number = m_Sin;
    int c_value = m_Sin % 10;
    int sum = 0;

    int count = 0;

    while (count < 9) {

      s_number = s_number / 10;
      sum = sum + (s_number % 10);

      count++;

    }

    sum = sum + c_value;
    
    if ((sum % 10 == 0) && (m_Sin <= MAX_SIN && m_Sin >= MIN_SIN)) {

      return true;

    }
    else {

      return false;

    }

  }
  void CRA_Account::display() const {

    if (m_Sin != 0) {

      cout << "Family Name: " << m_FamilyName << endl;
      cout << "Given Name : " << m_GivenName << endl;
      cout << "CRA Account: " << m_Sin << endl;

      int i;

      for (i = 0; i < m_years; i++) {

        if (m_balance[i] > 2) {

          cout << "Year (" << m_year[i] << ") balance owing: ";
          cout << fixed;
          cout.precision(2); 
          cout << m_balance[i] << endl;

        }
        else if (m_balance[i] < 2 && m_balance[i] > -2) {

          cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;

        }
        else if (m_balance[i] < 0) {

          cout << "Year (" << m_year[i] << ") refund due: ";
          cout << fixed;
          cout.precision(2); 
          cout << -(m_balance[i]) << endl;

        }

      }

    }
    else {

      cout << "Account object is empty!" << endl;

    }

  }

  void CRA_Account::set(int year, double balance) {

    if (m_years < MAX_YRS) {

      m_year[m_years] = year;
      m_balance[m_years] = balance;
      m_years = m_years + 1;

    }
    else {

      cout << "Max Tax years data already stored, Please enter '0' to go to display!!" << endl;

    }
 
  }
  
}