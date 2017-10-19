/*
OOP244 Workshop 3: Classes and Privacy
File: CRA_Account.h
Version 1.0
Date: 01/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef _SICT_CRA_Account_H_
#define _SICT_CRA_Account_H_

namespace sict {

  const int MAX_NAME_LENGTH = 41;
  const int MIN_SIN = 100000000;
  const int MAX_SIN = 999999999; 

  class CRA_Account {
  
  private:

    char m_FamilyName[MAX_NAME_LENGTH+1];
    char m_GivenName[MAX_NAME_LENGTH+1];
    int m_Sin; //Social insurance number

  public:

    void set(const char* familyName,const char* givenName, int sin);
    bool isValid() const;
    void display() const;



  };


}


#endif