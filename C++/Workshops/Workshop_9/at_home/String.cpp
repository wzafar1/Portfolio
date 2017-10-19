/*
OOP244 Workshop 9: String
File: String.cpp
Version 1.0
Date: 01/08/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict {


  //////////////////////////////////////////////////////
  //
  // Default Constructor
  // String::String(int capacity);
  //
  // initialize the string with an internal buffer capacity of 
  // "capacity." 
  // default capacity is 1 (minimum needed for an empty string)
  //
  // 
  String::String(int capacity) {

    m_pString = new char[capacity];
    strcpy(m_pString, "");
    m_pString[1] = '\0';
    m_capacity = capacity;

  }

  //////////////////////////////////////////////////////
  //
  // String::String(const char* p, int capacity);
  //
  // Construct a String from a char array
  // Should initialize the internal buffer to at least 
  // the length of the string need to hold pSource, 
  // or capacity, whichever is greater.
  //
  // 
  String::String(const char* pSource, int capacity) {

    int lenght = strlen(pSource);

    if (capacity > lenght) {

      m_capacity = capacity;

    }
    else {

      m_capacity = lenght + 1;

    }

    m_pString = new char[m_capacity];
    strcpy(m_pString, pSource);

  }

  //////////////////////////////////////////////////////
  //
  // String::String(const String &s, int capacity);
  //
  // Copy constructor
  //
  // Construct a String from another String
  //
  // 
  String::String(const String& other, int capacity)
  {

    m_pString = new char[capacity];
    strcpy(m_pString, other.m_pString);

  }



  //////////////////////////////////////////////////////
  //
  // String::resize(int newsize)
  //
  // resize the internal buffer to the value given
  // do NOT shrink the string buffer smaller than 
  // that needed to hold the existing string!
  // (length + 1);
  //    
  void String::resize(int newsize)
  {

    int length = strlen(m_pString) + 1;

    if (newsize > length) {

      char* temp = new char[newsize];
      m_capacity = newsize;
      strcpy(temp, m_pString);
      m_pString = new char[newsize];
      strcpy(m_pString, temp);
      delete[] temp;

    }

  }


  //////////////////////////////////////////////////////
  //
  // String::operator=(const String& other)
  // 
  // Assignment operator
  // copy string "other" to this object
  //   
  // 
  String& String::operator=(const String& other)
  {
    if (strcmp(m_pString, other.m_pString)) {

      resize(strlen(other.m_pString));
      strcpy(m_pString, other.m_pString);

    }

    return *this;

  }


  //////////////////////////////////////////////////////
  //
  // String::~String
  // 
  // destructor
  // 
  // clean up the internal string buffer  
  // 
  String::~String()
  {

    m_pString[0] = '\0';  
  // delete[] m_pString;                          // program crashes upon using delete [] for deallocation


  }

  //////////////////////////////////////////////////////
  //
  // String::length()
  // 
  // return the length of the string
  // 
  // 
  int String::length() const
  {

    return strlen(m_pString);

  }


  //////////////////////////////////////////////////////
  //
  // String::operator const char*() const
  // 
  // convert the String to a char*
  // 
  // 
  String::operator const char *() const
  {

    return m_pString;

  }


  //////////////////////////////////////////////////////
  //
  // String::empty()
  // 
  // 
  // returns true if the string is empty
  // i.e. either the first char is \0, or 
  // length is 0.
  bool String::empty() const
  {

    return (length() == 0);

  }

  //////////////////////////////////////////////////////
  //
  // String::operator bool()
  // 
  // same as empty(), just wrapped in an operator
  // 
  //     
  String::operator bool() const
  {

    return !empty();

  }


  //////////////////////////////////////////////////////
  //
  // String::operator==(const String& s2) const
  // 
  // returns true if *this == s2.
  // You can use the strcmp function to check if 
  // two strings are equal, or write your own
  // treating the string as a char-array
  //      
  bool String::operator==(const String& s2) const
  {

    return (strcmp(this->m_pString, s2.m_pString) == 0);

  }


  //////////////////////////////////////////////////////
  //
  // String::operator+=(const String& s2)
  // 
  // Concatenates s2 to the end of *this
  //
  // implements *this = (*this + s2)
  // return *this
  // 
  // 
  String& String::operator+=(const String& s2)
  {
    
    *this = *this + s2;
    return *this;

  }



  //////////////////////////////////////////////////////
  //
  // String::operator+(const String& s2) const
  // 
  // implements the operator (*this + s2)
  // returns the expression
  // DOES NOT MODIFY *this
  // 
  // 
  String String::operator+(const String& s2) const
  {

    char* temp = new char[length() + s2.length()];
    temp[0] = '\0';
    strcpy(temp, m_pString);
    strcat(temp, s2.m_pString);
    return temp;

  }

  //////////////////////////////////////////////////////
  //
  // String::operator+=(char c)
  // 
  // Adds a single char c to the end of the string in *this
  // Grows the string buffer if necessary.
  //  
  String& String::operator+= (char c)
  {

    resize(strlen(m_pString) + 1);
    char temp[2];
    temp[0] = c;
    temp[1] = '\0';
    strcat(m_pString, temp);
    return *this;

  }



  //////////////////////////////////////////////////////
  //
  // String::substr
  // 
  // Returns a substring of the current string. In case of error
  // return an empty String() object instead.
  // 
  // return the string slice starting at index, at most len characters
  // 
  // both index and len have to lie inside the string. If they do not, then 
  // that is an error
  // 
  String String::substr(int index, int len) const
  {
    char* temp = new char[m_capacity];
    if ((index > m_capacity) && (len > m_capacity)) {

      m_pString[0] = '\0';
      empty();

    }
    else {

      for (int i = index; i < len + 1; i++) {

        temp[i] = m_pString[i];

      }
    }

    return temp;

  }

  //////////////////////////////////////////////////////
  //
  // operator<<
  // 
  // Print the string to the output stream
  // 
  // clean up the internal string buffer  
  // 
  std::ostream& operator<<(std::ostream& ostream, const String &s)
  {

    ostream << (const char*)s;
    return ostream;

  }

  //////////////////////////////////////////////////////
  //
  // operator>>
  // 
  // Input a string from an input stream into the String s
  // 
  // Note: the input can be ANY length in character. You will need to 
  // read it one char at a time. 
  // 
  std::istream& operator >> (std::istream& istream, String &s)
  {
    s = "";
    char tempC = 0;
    do
    {
      tempC = istream.get();
      if (tempC != '\n')
      {
        s += tempC;
      }
      else
        break;
    } while (1);
    return istream;
  }


}
