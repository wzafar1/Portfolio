// Final Project Milestone 4
// Version 1.0
// Date: 16/07/2017
// Author: Wahab Zafar
// Email: wzafar1@myseneca.ca
// Revision History
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
