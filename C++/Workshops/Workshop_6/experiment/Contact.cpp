#include<iostream>
#include<cstring>
#include"Contact.h"

#define _CRT_SECURE_NO_WARNINGS

namespace sict {

  using namespace std;

  //Default constructor
  Contact::Contact() {

    setEmpty();

  }

  //Constructor with three parameters.used for storing data
  Contact::Contact(const char* name, const long long* phoneNumber, int noOfNumbers) {

    int count = 0;
    int i;

    if (name != nullptr && name[0] != '\0') {

      strncpy(m_name, name, 19); // _TRUNCATE if i enter the size here it cause Lbuffer too small && 0 error
      m_name[20] = '\0';

    }
    else {

      setEmpty();

    }

    if (phoneNumber != nullptr && noOfNumbers > 0) {


      for (i = 0; i < noOfNumbers; i++) {

        if (decomposeNumber(phoneNumber[i]) == true) {

          count++;

        }

      }
      
      m_noOfNumbers = count;
      m_Pnumber = new long long[m_noOfNumbers];

      int j;
      int cpun = 0;

      for (j = 0; j < noOfNumbers; j++) {

        if (decomposeNumber(phoneNumber[j]) == true) {

          m_Pnumber[cpun] = phoneNumber[j];
          cpun++;

        }

      }

    }
  }

  //deconstructor
  Contact::~Contact() {

    delete[] m_Pnumber;

  }


  bool Contact::isEmpty() const {

    if ( m_Pnumber!=nullptr || m_name[0] != '\0') {

      return false;

    }
    else {

      return true;

    }

  }

  void Contact::display() const {

    if (!isEmpty() == true) {

      cout << m_name << endl;

      if (m_noOfNumbers != 0) {

        int i;
        for (i = 0; i < m_noOfNumbers; i++) {

          cout << "(+" <<
            m_Pnumber[i] / 10000000000 << ") " << (m_Pnumber[i] % 10000000000) / 10000000 << " " <<
            (m_Pnumber[i] % 10000000) / 10000 << "-" << m_Pnumber[i] % 10000 << endl;

        }

      }

    }
    else {

      cout << "Empty contact!" << endl;

    }



  }

  void Contact::setEmpty() {

    m_name[0] = '\0';
    m_Pnumber = nullptr;
    m_noOfNumbers = 0;

  }

  bool Contact::decomposeNumber(const long long phone_number) {

    long long country;
    long long area;
    long long rNumber;

    country = getCountryCode(phone_number);
      area = getAreaCode(phone_number);
      rNumber = getNumber(phone_number);

    if (country > 0 && country <= 99 && area >= 100 && area <= 999 && rNumber >= 1000000 && rNumber <= 9999999) {

          return true;

    }
    else {

      return false;

    }

  }

  long long Contact::getAreaCode(const long long phone_number) {

    long long area;
    area = phone_number % 10000000000;
    area = area / 10000000;
    return area;

  }

  long long Contact::getCountryCode(const long long phone_number) {

    long long country;
    country = phone_number / 10000000000;
    return country;

  }

  long long Contact::getNumber(const long long phone_number) {

    long long num = phone_number % 10000000;
    return num;

  }

}