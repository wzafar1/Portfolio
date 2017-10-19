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

#ifndef ICT_AMA_PERISHABLE_H
#define ICT_AMA_PERISHABLE_H
#include "AmaProduct.h"
#include "Date.h"

namespace sict {

  class AmaPerishable : public AmaProduct {

  private:

    Date expiry_;

  public:

    AmaPerishable();

    // Public member functions:

    // Public Accessors (setters and getters)

    const Date& expiry()const;
    void expiry(const Date &value);

    // Virtual method implementations:

    std::fstream& store(std::fstream& file, bool addNewLine = true) const;   // Store comma separated values in a file.
    std::fstream& load(std::fstream& file);                                  // Reads comma separated values in a file.
    std::ostream& write(std::ostream& ostr, bool linear) const;              // Display result on screen, which is product details.
    std::istream& read(std::istream& istr);                                  // Accepts user input for product details.

  };
}

#endif // !ICT_AMA_PERISHABLE_H
