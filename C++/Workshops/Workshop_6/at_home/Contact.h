/*
OOP244 Workshop 6: Contact
File: Contact.h
Version 1.0
Date: 27/06/2017
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
    long long* m_tempPh; //created for the += operator
    int m_noOfNumbers;

  public:

    //Members
    Contact(); //Default constructot
    Contact(const char* name, const long long* phoneNumber, int noOfDigits);
    Contact(const Contact& c1); // Copy constructor
    Contact& operator=(const Contact& Asgd);
    Contact& operator+=(const long long phoneNumber);
    ~Contact(); //deconstructor


    // Functions
    bool isEmpty() const;
    void setEmpty();
    void display() const;

    //Correction(for in_lab) these belong to public
    bool validNumber(const long long phone_number);

    long long getAreaCode(const long long phone_number);
    long long getCountryCode(const long long phone_number);
    long long getNumber(const long long phone_number);

  };

}

#endif // !_ICT_CONTACT_H
