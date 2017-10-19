/*
OOP244 Workshop 6: Contact
File: Contact.cpp
Version 1.0
Date: 27/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS_GLOBALS / Had to include it before becasue of visual studio
#include<iostream>
#include<cstring>
#include"Contact.h"


namespace sict {

  using namespace std;

  //Default constructor
  Contact::Contact() {

    setEmpty();

  }

  //Copy Constructor
  Contact::Contact(const Contact& c1) {

    m_noOfNumbers = c1.m_noOfNumbers;
    strncpy(m_name, c1.m_name, 19);
    m_name[20] = '\0';

    if (c1.m_Phnumber != nullptr) {

      m_Phnumber = new long long[m_noOfNumbers];

      for (int i = 0; i < m_noOfNumbers; i++)

        m_Phnumber[i] = c1.m_Phnumber[i];
    }
    else {

      m_Phnumber = nullptr;

    }
  }

  //Constructor with three parameters.used for storing data
  Contact::Contact(const char* name, const long long* phoneNumber, int noOfNumbers) {

    if (name != nullptr && name[0] != '\0') {

      strncpy(m_name, name, 19);
      m_name[20] = '\0';

    }
    else {

      setEmpty();

    }

    if (phoneNumber != nullptr && phoneNumber[0] != '\0' && noOfNumbers > 0) {

      int count = 0;
      int i;
      int j = 0;

      for (i = 0; i < noOfNumbers; i++) {

        if (validNumber(phoneNumber[i]) == true) {

          count++;

        }
      }

      m_noOfNumbers = count;
      m_Phnumber = new long long[m_noOfNumbers];

      for (i = 0; i < noOfNumbers; i++) {

        if (validNumber(phoneNumber[i]) == true) {

          m_Phnumber[j] = phoneNumber[i];
          j++;
        }
      }
    }
    else {

      m_noOfNumbers = 0;
      m_Phnumber = nullptr;

    }
  }

  //= copies that object into the current object 
  Contact& Contact::operator=(const Contact& Asgd) {

    if (this != &Asgd) {

      delete[] m_Phnumber;
      m_Phnumber = new long long[m_noOfNumbers = Asgd.m_noOfNumbers];

      int i;

      for (i = 0; i < m_noOfNumbers; i++) {

        m_Phnumber[i] = Asgd.m_Phnumber[i];

      }
    }
    return *this;
  }

  //resizes the phone number list to hold all of the existing numbers plus new one
  Contact& Contact::operator+=(const long long phoneNumber) {

    if (validNumber(phoneNumber) == true) {

      int i;
      int tempNo = m_noOfNumbers;
      m_noOfNumbers += 1;
      m_tempPh = new long long[tempNo];

      for (i = 0; i < tempNo; i++) {

        m_tempPh[i] = m_Phnumber[i];

      }

      delete[] m_Phnumber;
      m_Phnumber = new long long[m_noOfNumbers];

      for (i = 0; i < tempNo; i++) {

        m_Phnumber[i] = m_tempPh[i];

      }

      m_Phnumber[tempNo] = phoneNumber;
      delete[] m_tempPh;

    }

    return *this;

  }

  //deconstructor
  Contact::~Contact() {

    delete[] m_Phnumber;

  }


  bool Contact::isEmpty() const {

    bool val = 0;

    if (m_Phnumber == nullptr && m_noOfNumbers == 0) {

      if (m_name == nullptr || m_name[0] == '\0') {

        val = 1;;

      }
    }

    return val;
  
  }

  void Contact::display() const{

    if (isEmpty() == 0) {

      cout << m_name << endl;

      if (m_noOfNumbers != 0) {

        int i;
        for (i = 0; i < m_noOfNumbers; i++) {

          cout << "(+" <<
            m_Phnumber[i] / 10000000000 << ") " << (m_Phnumber[i] % 10000000000) / 10000000 << " " <<
            (m_Phnumber[i] % 10000000) / 10000 << "-" << m_Phnumber[i] % 10000 << endl;

        }
      }
    }
    else {

      cout << "Empty contact!" << endl;

    }
  }

  void Contact::setEmpty() {

    m_name[0] = '\0';
    m_Phnumber = nullptr;
    m_noOfNumbers = 0;

  }

  bool Contact::validNumber(const long long phone_number) {

    long long countryCode = getCountryCode(phone_number);
    long long areaCode = getAreaCode(phone_number);
    long long number = getNumber(phone_number);

    if (countryCode > 0 && countryCode <= 99 && areaCode >= 100 && areaCode <= 999 && number >= 1000000 && number <= 9999999) {

          return true;

    }
    else {

      return false;

    }

  }

  long long Contact::getAreaCode(const long long phone_number) {

    return (phone_number % 10000000000) / 10000000;

  }

  long long Contact::getCountryCode(const long long phone_number) {

    return phone_number / 10000000000;

  }

  long long Contact::getNumber(const long long phone_number) {

    return phone_number % 10000000;

  }



}