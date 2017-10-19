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

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include"Product.h"

namespace sict {

  // default constructor, set to safe emptysate.

  Product::Product() {

    setEmpty();

  }

  // Five argument Constructor, stores the values in the corresponding private member

  Product::Product(const char* P_sku, const char* P_name, bool P_taxed, double P_price, int P_qtyNeeded) {

    if (P_name != nullptr && P_name[0] != '\0') {

      sku(P_sku);
      name(P_name);
      taxed(P_taxed);
      price(P_price);
      qtyNeeded(P_qtyNeeded);
      quantity(0);

    }
    else {

      setEmpty();

    }
  }

  // virtual destructor

  Product::~Product() {

    delete[] name_;

  }

  // Copy Constructor

  Product::Product(const Product& P) {

    sku(P.sku_);
    taxed(P.taxed_);
    price(P.price_);
    quantity(P.quantity_);
    qtyNeeded(P.qtyNeeded_);

    if (P.name_ != nullptr) {

      name(P.name_);

    }
    else {

      name_ = nullptr;

    }
  }

  // Copy assignment operator:

  Product& Product::operator=(const Product& P) {

    if (this != &P) {

      sku(P.sku_);
      taxed(P.taxed_);
      price(P.price_);
      quantity(P.quantity_);
      qtyNeeded(P.qtyNeeded_);

      delete[] name_;

      if (P.name_ != nullptr) {

        name(P.name_);

      }
      else {

        name_ = nullptr;

      }
    }

    return *this;

  }

  // Accessors:

  // Setters:

  // set to safe empty sate
  void Product::setEmpty() {

    name_ = nullptr;

  }

  // set the sku_ of Product
  void Product::sku(const char* sku) {

    strcpy(sku_, sku);

  }

  // set the price_ of Product
  void Product::price(double price) {

    price_ = price;

  }

  // set the name_ of Product
  void Product::name(const char* name) {

    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);

  }

  // set the taxed_ of Product
  void Product::taxed(bool taxed) {

    taxed_ = taxed;

  }

  // set the quantity_ of Product
  void Product::quantity(int quantity) {

    quantity_ = quantity;

  }

  // set the qtyNeeded_ of Product
  void Product::qtyNeeded(int qtyNeeded) {

    qtyNeeded_ = qtyNeeded;
    
  }

  // Getters (Queries):

  // return the sku_ of the Product
  const char* Product::sku() const {

    return sku_;

  }
  
  // return the price_ of the Product
  double Product::price() const {

    return price_;

  }

  // return the name_ of the Product
  const char* Product::name() const {

    return name_;

  }

  // return the taxed_ of the Product
  bool Product::taxed() const {

    return taxed_;

  }

  // return the quantity_ of the Product
  int Product::quantity() const {

    return quantity_;

  }

  // return the qtyNeeded_ of the Product
  int Product::qtyNeeded() const {

    return qtyNeeded_;

  }

  // return the cost of the Product after TAX
  double Product::cost() const {

    if (taxed_ == true) {


      return price_+(price_ * TAX);

    }
    else {

      return price_;

    }
  }

  // check is product is in safe empty sate
  bool Product::isEmpty() const {

    if (name_ == nullptr) {

      return true;

    }
    else {

      return false;

    }
  }

  // Operator overloads funcions:

  // receives a constant character pointer and returns a Boolean
  bool Product::operator == (const char* sku) {

    if (strcmp(this->sku_, sku) == 0) {

      return true;

    }
    else {

      return false;

    }
  }

  // receives an integer and returns quantity after adding integer
  int Product::operator += (int quantity) {

    quantity_ += quantity;
    return quantity_;

  }

  // receives an integer and returns quantity after substracting integer
  int Product::operator -= (int quantity) {

    quantity_ -= quantity;
    return quantity_;

  }

  // Non-Member operator overload:

  // receives a double reference value and return after adding it in the
  // product price and quantity of Product.
  double operator+=(double& val, const Product& P) {

    val += P.cost() * P.quantity();
    return val;

  }

  // Non-member IO operator overloads:

  // overload the operator << for output stream 
  std::ostream& operator << (std::ostream& ostr, const Product& P) {

    P.write(ostr, 1);
    return ostr;

  }

  // overload the operator >> for input stream 
  std::istream& operator >> (std::istream& istr, Product& P) {

    P.read(istr);
    return istr;

  }
}
