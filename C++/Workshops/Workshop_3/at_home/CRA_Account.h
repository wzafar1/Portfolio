/*
OOP244 Workshop 3: Classes and Privacy
File: CRA_Account.h
Version 1.0
Date: 01/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
Description:
This workshop demonstrates classes in C++ and
how member variables are defined privately, but
accessed through public member functions.
*/

#ifndef _SICT_CRA_Account_H_
#define _SICT_CRA_Account_H_

namespace sict {

  const int MAX_NAME_LENGTH = 41;
  const int MIN_SIN = 100000000;
  const int MAX_SIN = 999999999; 
  const int MAX_YRS = 4;

  class CRA_Account {
  
  private:

    char m_FamilyName[MAX_NAME_LENGTH];
    char m_GivenName[MAX_NAME_LENGTH];
    int m_Sin; //Social insurance number
    int m_year[MAX_YRS];
    double m_balance[MAX_YRS];
    int m_years;

  public:

    void set(const char* familyName,const char* givenName, int sin);
    bool isValid() const;
    void display() const;
    void set(int year, double balance);

  };


}


#endif