/*
OOP244 Workshop 6: Contact
File: Contact.h
Version 1.0
Date: 24/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#ifndef _ICT_CONTACT_H
#define _ICT_CONTACT_H

namespace sict {

  class Contact {

  private:

    char m_name[20];
    long long* m_Phnumber;
    int m_noOfNumbers;

    bool decomposeNumber(const long long phone_number);

    long long getAreaCode(const long long phone_number);
    long long getCountryCode(const long long phone_number);
    long long getNumber(const long long phone_number);

  public:

    //Members
    Contact(); //Default constructot
    Contact(const char* name, const long long* phoneNumber, int noOfDigits);

    // Functions
    bool isEmpty() const;
    void display() const;

    void setEmpty();
    ~Contact(); //deconstructor
  };

}

#endif // !_ICT_CONTACT_H
