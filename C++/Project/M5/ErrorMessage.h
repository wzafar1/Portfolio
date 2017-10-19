// Final Project Milestone 5
// Version 1.0
// Date: 26/07/2017
// Author: Wahab Zafar
// Email: wzafar1@myseneca.ca
// Description:
// This project is to prepare an application that manages the 
// list of goods needed to be shipped to the area. The application 
// is able to keep track of the quantity of items needed, the 
// quantity on hand, and store them in a file for future use.
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef ICT_ERROR_MESSAGE_H
#define ICT_ERROR_MESSAGE_H

namespace sict {

  class ErrorMessage {

  private:

    char* message_;  // Store the Error message

  public:

    //Constructors:

    ErrorMessage();                                 // Default constructor.Sets the message_ member variable to nullptr.
    ErrorMessage(const char* errorMessage);         // Sets the message_ member variable to nullptr and set the error message to the 
                                                    // errorMessage argument by using message() function.
    ErrorMessage(const ErrorMessage& em) = delete;  // A deleted copy constructor to prevent an ErrorMessage object to be copied.

    //Public member functions 

    virtual ~ErrorMessage();          // De-allocates the memory which is pointed by message_.
    void clear();                     // De-allocates the memory and set message_ to nullptr
    bool isClear()const;              // Check if message_ is nullptr, if yes return true.
    void message(const char* value);  // Sets the message_ to a new value.
    const char* message()const;       // Returns the address kept in message_.

    //operator overloads

    ErrorMessage& operator=(const ErrorMessage& em) = delete;  // To prevent an ErrorMessage object to be assigned to another.  
    ErrorMessage& operator=(const char* errorMessage);         // Sets the message_ to the errorMessage argument and returns the current 
                                                               // object. 

    // Output member functions

    std::ostream& displayError(std::ostream& ostr)const;  //Writes the Error Message, then return the ostr.

  };

  std::ostream& operator << (std::ostream& ostr, const ErrorMessage& E) ; // Prints Error message if isclear return false.

}


#endif // !ICT_ERROR_MESSAGE_H
