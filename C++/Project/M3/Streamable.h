// Final Project Milestone 3
// Version 1.0
// Date: 11/07/2017
// Author: Wahab Zafar
// Email: wzafar1@myseneca.ca
// Description:
// The Streamable class is provided to enforce inherited classes 
// to implement functions to work with 
// fstream and iostream objects.
// -----------------------------------------------------------
// Name               Date                 Reason

#ifndef ICT_STREAMABLE_H
#define ICT_STREAMABLE_H

#include <fstream>

namespace sict {


  class Streamable {

  public:

    // Pure virtual member functions :

    // Is a constant member function and return the references of std::fstream. (does not modify the owner)
    virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;

    // Receives and returns references of std::fstream.
    virtual std::fstream& load(std::fstream& file) = 0;

    // Is a constant member function and returns a reference of std::ostream.
    virtual std::ostream& write(std::ostream& os, bool linear)const = 0;

    // Returns and receives references of std::istream.
    virtual std::istream& read(std::istream& is) = 0;

  };

}

#endif // !ICT_STREAMABLE_H
