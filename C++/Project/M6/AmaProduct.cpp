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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AmaProduct.h"

using namespace std;

namespace sict {

  //Constructor:

  // Default and also one argument constructor, If no argument is provided fileTag_ is set to 'N' as declared in prototype.
  AmaProduct::AmaProduct(char ch) {

    fileTag_ = ch;

  }

  // Public member functions:

  // Returns a constant pointer to the unit_ member variable.
  const char* AmaProduct::unit()const {

    return unit_;

  }

  // Setter member function for unit_, set unit_ to incoming value.
  void AmaProduct::unit(const char* value) {

    strncpy(unit_, value, 10);
    unit_[11] = '\0';

  }

  // Virtual method implementations:

  // Store comma separated values in a file.
  std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const {

    file << fileTag_ << "," << sku()      << "," 
         << name()   << "," << price()    << "," 
         << taxed()  << "," << quantity() << "," 
         << unit_    << "," << qtyNeeded();

    if (addNewLine == true) {

      file << endl;

    }

    return file;

  }

  // Reads comma separated values in a file.
  std::fstream& AmaProduct::load(std::fstream& file) {

    char tempBuf_s[40];
    int tempBuf_i;
    double tempBuf_d;

    file.getline(tempBuf_s, MAX_SKU_LEN, ','); // Reads sku up to MAX_SKU_LEN ,store in tempBuf_s variable and ignores the delimiter.
    sku(tempBuf_s);	                           // Sets sku, by passing tempBuf_s into sku() setter function.

    file.getline(tempBuf_s, 20, ',');          // Reads name,store in tempBuf_s variable and ignores the delimiter, which is ','.
    name(tempBuf_s);		                       // Sets name, by passing tempBuf_s into name() setter function.

    file >> tempBuf_d;		                     // Reads price into into tempBuf_d.
    price(tempBuf_d);		                       // Sets price, by passing tempBuf_d into price() setter function.
    file.ignore(1);		                         // Ignores the delimiter, which is ','.

    file >> tempBuf_i;		                     // Reads taxed value	into tempBuf_i.
    taxed(tempBuf_i);		                       // Sets taxed, by passing tempBuf_i into taxed() setter function.
    file.ignore(1);		                         // Ignores the delimiter, which is ','.

    file >> tempBuf_i;		                     // Reads quantity on hand into tempBuf_i.
    quantity(tempBuf_i);	                   	 // Sets the quantity, by passing tempBuf_i into quantity() setter function.
    file.ignore(1);		                         // Ignores the delimiter, which is ','.

    file.getline(tempBuf_s, 10, ',');          // Reads unit of quantity into tempBuf_s.
    unit(tempBuf_s);			                     // Sets unit_, by passing tempBuf_s into price() setter function.

    file >> tempBuf_i;		                     // Reads quantity needed into tempBuf_i.
    qtyNeeded(tempBuf_i);	                     // Sets quantity needed, by passing tempBuf_i into qtyNeeded() setter function.

    return file;

  }

  // Display result on screen, which is product details.
  std::ostream& AmaProduct::write(std::ostream& ostr, bool linear)const {

    if (!err_.isClear() == true) {
      ostr << err_;
    }
    else {
      switch (linear) {

      case true:

        ostr.setf(ios::fixed);
        ostr.fill(' ');

        ostr.width(MAX_SKU_LEN);
        ostr.setf(ios::left);
        ostr << sku() << "|";

        ostr.width(20);
        ostr.setf(ios::left);
        ostr << name() << "|";

        ostr.width(7);
        ostr.setf(ios::right);
        ostr.precision(2);
        ostr << cost() << "|";

        ostr.width(4);
        ostr.setf(ios::right);
        ostr << quantity() << "|";
        ostr.unsetf(ios::right);

        ostr.width(10);
        ostr.setf(ios::left);
        ostr << unit_ << "|";

        ostr.width(4);
        ostr.setf(ios::right);
        ostr << qtyNeeded() << "|";
        ostr.unsetf(ios::right);
        break;

      case false:

        ostr << "Sku: "   << sku()   << endl;
        ostr << "Name: "  << name()  << endl;
        ostr << "Price: " << price() << endl;
        
        if (taxed() == false) {
          ostr << "Price after tax: N/A" << endl;
        }
        else {
          ostr << "Price after tax: " << cost() << endl;
        }

        ostr << "Quantity On Hand: " << quantity() << " " << unit() << endl;
        ostr << "Quantity Needed: "  << qtyNeeded();
        break;

      }
    }

    return ostr;

  }

  // Accepts user input for product details.
  std::istream& AmaProduct::read(std::istream& istr) {

    char tempBuf_s[40];
    char tempBuf_c;
    int tempBuf_i;
    double tempBuf_d;

    cout << "Sku: ";
    istr >> tempBuf_s;                     // Reads sku into tempBuf_s.
    sku(tempBuf_s);	                       // Sets sku, by passing tempBuf_s into sku() setter function.

    istr.clear();                          // Clearing input buffer as a safe gaurd.
    istr.ignore();                         //

    cout << "Name: ";
    istr.getline(tempBuf_s, 20, '\n');     // Reads name into tempBuf_s till new line.
    name(tempBuf_s);		                   // Sets name, by passing tempBuf_s into name() setter function.

    cout << "Unit: ";
    istr.getline(tempBuf_s, 10, '\n');     // Reads unit of quantity into tempBuf_s till new line.
    unit(tempBuf_s);			                 // Sets unit_, by passing tempBuf_s into price() setter function.

    cout << "Taxed? (y/n): ";
    istr >> tempBuf_c;		                 // Reads taxed value	into tempBuf_i.

    if (tempBuf_c == 'Y' || tempBuf_c == 'y' || tempBuf_c == 'N' || tempBuf_c == 'n') {
      err_.clear();

      if (tempBuf_c == 'Y' || tempBuf_c == 'y') {
        taxed(true);                       // Sets taxed, by calling taxed() setter function.
      }
      else {
        taxed(false);                      // Sets taxed, by calling taxed() setter function.
      }

      cout << "Price: ";
      istr >> tempBuf_d;		               // Reads price into into tempBuf_d.

      if (istr.fail()) {
        err_.message("Invalid Price Entry");
      }
      else {
        price(tempBuf_d);		                // Sets price, by passing tempBuf_d into price() setter function.
        cout << "Quantity On hand: ";
        istr >> tempBuf_i;		              // Reads quantity on hand into tempBuf_i.

        if (istr.fail()) {
          err_.message("Invalid Quantity Entry");
        }
        else {
          quantity(tempBuf_i);	             // Sets the quantity, by passing tempBuf_i into quantity() setter function.
          cout << "Quantity Needed: ";
          istr >> tempBuf_i;		             // Reads quantity needed into tempBuf_i.

          if (istr.fail()) {
            err_.message("Invalid Quantity Needed Entry");
          }
          else {
            qtyNeeded(tempBuf_i);	            // Sets quantity needed, by passing tempBuf_i into qtyNeeded() setter function.
          }
        }
      }
    }
    else {
      err_.message("Only (Y)es or (N)o are acceptable");		//if user presses other than yes or no, related error message is set
      istr.setstate(ios::failbit);
    }

    return istr;

  }
}