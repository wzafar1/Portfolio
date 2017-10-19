// Final Project Milestone 6
// Version 1.0
// Date: 08/08/2017
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

#ifndef ICT_AMA_PRODUCT_H
#define ICT_AMA_PRODUCT_H

#include "Product.h"
#include "ErrorMessage.h"

namespace sict {

  class AmaProduct : public Product {

  private:

    char fileTag_;
    char unit_[11];

  protected:

    ErrorMessage err_;                // Stores the error message, if any occurs.

  public:

    //Constructor

    AmaProduct(char ch = 'N');       // Default and also one argument constructor

    // Public member functions:

    const char* unit()const;         // Returns a constant pointer to the unit_ member variable.
    void unit(const char* value);    // Setter member function for unit_, set unit_ to incoming value.

    // Virtual method implementations

    std::fstream& store(std::fstream& file, bool addNewLine = true) const;   // Store comma separated values in a file.
    std::fstream& load(std::fstream& file);                                  // Reads comma separated values in a file.
    std::ostream& write(std::ostream& ostr, bool linear) const;              // Display result on screen, which is product details.
    std::istream& read(std::istream& istr);                                  // Accepts user input for product details.




  };
}

#endif // !ICT_AMA_PRODUCT_H


