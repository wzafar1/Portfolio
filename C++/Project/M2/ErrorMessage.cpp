// Final Project Milestone 2
// Version 1.0
// Date: 10/07/2017
// Author: Wahab Zafar
// Email: wzafar1@myseneca.ca
// Description:
// The ErrorMessage class encapsulates an error message in a 
// dynamic C - style string and also is used as a flag for the error state of other classes.
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include"ErrorMessage.h"

namespace sict {

  //Constructors:

  // Default constructor.
  ErrorMessage::ErrorMessage() {

    message_ = nullptr;

  }

  // Sets the message_ member variable to nullptr and set the error message to the errorMessage argument by using message() function.
  ErrorMessage::ErrorMessage(const char* errorMessage) {

    message_ = nullptr;
    message(errorMessage);

  }

  // Public member functions:

  // De-allocates the memory pointed by message_.
  ErrorMessage::~ErrorMessage() {

    delete[] message_;

  }

  // De-allocates the memory and set message_ to nullptr.
  void ErrorMessage::clear() {

    delete[] message_;
    message_ = nullptr;

  }

  // Returns true if message_ is nullptr.
  bool ErrorMessage::isClear()const {

    if (message() == nullptr) {

      return true;

    }
    else {

      return false;

    }

  }

  // Sets the message_ to a new value.
  void ErrorMessage::message(const char* value) {

    int count = strlen(value);       // Count the total number of character in value
    clear();                         // deallocate message_
    message_ = new char[count + 1];  // allocate new dynamic memory
    strcpy(message_, value);         // copy value into message_

  }

  // Returns the address kept in message_.
  const char* ErrorMessage::message()const {

    return message_;

  }

  // Oerator overload:

  // Sets the message_ to the  errorMessage argument. 
  ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {

    clear();                // deallocate message_
    message(errorMessage);  // calls message() function and set new value
    return *this;

  }

  std::ostream& ErrorMessage::displayError(std::ostream& ostr)const {

    if (isClear() != true) {

      ostr << message_;

    }

    return ostr;

  }

  // Output stream overload (ostream)

  // Prints Error message if isclear return false.
  std::ostream& operator << (std::ostream& ostr, const ErrorMessage& E) {

    return E.displayError(ostr);

  }

}