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
