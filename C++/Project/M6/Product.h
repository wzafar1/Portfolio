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

#ifndef ICT_PRODUCT_H
#define ICT_PRODUCT_H
#include <iostream>
#include "Streamable.h"
#include "general.h"

namespace sict {

  class Product :public Streamable {

  private:
      
     // Private Members:

    char sku_[MAX_SKU_LEN + 1];  // Character array holds the SKU (barcode) of the items
    char* name_;                 // Points to a dynamic string that holds the name of the Product
    double price_;               // Holds the Price of the Product
    bool taxed_;                 // True if this Product is taxed ( represents the Product taxed status)
    int quantity_;               // Holds the quantity of the Product available.
    int qtyNeeded_;              // Holds the quantity of the Product required.

  public:

    // Public Members:

    // Constructor:

    Product();  // This constructor sets the Product to a safe recognizable empty state.
    Product(const char* P_sku, const char* P_name, bool P_taxed = true, double P_price = 0, int P_qtyNeeded = 0); // Five argument Constructor, stores the values in
    // the corresponding private member

    // Copy Constructor:

    Product(const Product& P);

    // Copy assignment operator:

    Product& operator = (const Product& P);

    // virtual destructor:

    virtual ~Product();

    // Accessors:

    // Setters:

    void setEmpty();               // set to safe empty sate
    void sku(const char* sku);     // set the sku_ of Product
    void price(double price);      // set the price_ of Product
    void name(const char* name);   // set the name_ of Product
    void taxed(bool taxed);        // set the taxed_ of Product
    void quantity(int quantity);   // set the quantity_ of Product
    void qtyNeeded(int qtyNeeded); // set the qtyNeeded_ of Product

    // Getters (Queries):

    const char* sku() const;      // return the sku_ of the Product
    double price() const;         // return the price_ of the Product
    const char* name() const;     // return the name_ of the Product
    bool taxed() const;           // return the taxed_ of the Product
    int quantity() const;         // return the quantity_ of the Product
    int qtyNeeded() const;        // return the qtyNeeded_ of the Product
    double cost() const;          // return the cost of the Product after TAX
    bool isEmpty() const;         // check is product is in safe empty sate


    // Operator overloads funcions:

    bool operator == (const char* sku);   // receives a constant character pointer and returns a Boolean
    int operator += (int quantity);       // receives an integer and returns quantity after adding integer
    int operator -= (int quantity);       // receives an integer and returns quantity after substracting integer

  };

  // Non-Member operator overload:

  double operator+=(double& val, const Product& P);  // receives a double reference value and return after adding it in the
                                                     // product price and quantity of Product.

  // Non-member IO operator overloads:

  std::ostream& operator << (std::ostream& ostr, const Product& P);   // overload the operator << for output stream 
  std::istream& operator >> (std::istream& istr, Product& P);         // overload the operator >> for input stream 

}

#endif // !ICT_PRODUCT_H
