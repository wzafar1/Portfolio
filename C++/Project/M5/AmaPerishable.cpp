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

#include "AmaPerishable.h"

using namespace std;

namespace sict {

  AmaPerishable::AmaPerishable() : AmaProduct('P') {

    // 

  }

  // Public member functions:

  // Public Accessors (setters and getters)

  const Date& AmaPerishable::expiry()const {

    return expiry_;

  }


  void AmaPerishable::expiry(const Date &value) {

    expiry_ = value;

  }

  // Virtual method implementations:

  // Store comma separated values in a file.
  std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine) const {

    AmaProduct::store(file, false);
    file << "," << expiry_;

    if (addNewLine == true) {
      file << endl;
    }

    return file;

  }

  // Reads comma separated values in a file.
  std::fstream& AmaPerishable::load(std::fstream& file) {

    AmaProduct::load(file);
    file.ignore(1);
    expiry_.read(file);
    return file;

  }

  // Display result on screen, which is product details.
  std::ostream& AmaPerishable::write(std::ostream& ostr, bool linear) const {

    AmaProduct::write(ostr, linear);

    if (err_.isClear()) {

      if (linear == true) {
        expiry_.write(ostr);
      }
      else {
        ostr << endl;
        ostr << "Expiry date: ";
        expiry_.write(ostr);
      }
    }

    return ostr;

  }

  // Accepts user input for product details.
  std::istream& AmaPerishable::read(std::istream& istr) {

    AmaProduct::read(istr);

    if (err_.isClear()) {
      cout << "Expiry date (YYYY/MM/DD): ";
      Date tempDate;
      tempDate.read(istr);
           if (tempDate.errCode() == CIN_FAILED) { err_.message("Invalid Date Entry");
                                                   istr.setstate(ios::failbit); }
      else if (tempDate.errCode() == YEAR_ERROR) { err_.message("Invalid Year in Date Entry");
                                                   istr.setstate(ios::failbit); }
      else if (tempDate.errCode() == MON_ERROR)  { err_.message("Invalid Month in Date Entry"); 
                                                   istr.setstate(ios::failbit); }
      else if (tempDate.errCode() == DAY_ERROR)  { err_.message("Invalid Day in Date Entry");
                                                   istr.setstate(ios::failbit); }
      else { expiry_ = tempDate; }
    }

    return istr;

  }
}