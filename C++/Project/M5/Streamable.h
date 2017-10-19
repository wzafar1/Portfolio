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

#ifndef ICT_STREAMABLE_H
#define ICT_STREAMABLE_H

#include <fstream>

namespace sict {


  class Streamable {

  public:

    virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;

    virtual std::fstream& load(std::fstream& file) = 0;

    virtual std::ostream& write(std::ostream& os, bool linear)const = 0;

    virtual std::istream& read(std::istream& is) = 0;

  };

}

#endif // !ICT_STREAMABLE_H
