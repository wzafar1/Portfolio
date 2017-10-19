/*
OOP244 Workshop 6: Contact
File: Contact.cpp
Version 1.0
Date: 24/06/2017
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

  //Constructor with three parameters.used for storing data
  Contact::Contact(const char* name, const long long* phoneNumber, int noOfNumbers) {

    if (name != nullptr && name[0] != '\0') {

      strncpy(m_name, name,19);
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

        if (decomposeNumber(phoneNumber[i]) == true) {

          count++;

        }
      }

      m_noOfNumbers = count;
      m_Phnumber = new long long [m_noOfNumbers];

      for (i = 0; i < noOfNumbers; i++) {

        if (decomposeNumber(phoneNumber[i]) == true) {

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

  bool Contact::decomposeNumber(const long long phone_number) {

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