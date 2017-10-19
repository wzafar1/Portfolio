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

#include<iostream>
#include<cstring>
#include"AidApp.h"

using namespace std;  

namespace sict {

  // Constructor

  // Default constructor.
  AidApp::AidApp(const char* filename) {

    strcpy(filename_, filename);
    product_[0] = nullptr;
    noOfProducts_ = 0;

    loadRecs();

  }


  // Queries

  // Waits for the user to hit enter, others keys are ignored.
  void AidApp::pause() const {
    
    
    cout << endl;
    cout << "Press Enter to continue...";
    cin.get();
    cin.clear();
    cin.ignore(2000,'\n');
    cout << endl;

  }

  // Display the products currently in Product* .
  void AidApp::listProducts() const {

    double total = 0;

    cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl
         << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

    for (int i = 0; i < noOfProducts_; i++) {

      cout.fill(' ');
      cout.width(4);
      cout.setf(ios::right);
      cout << i+1;
      cout.unsetf(ios::right);
      cout << " | " << *product_[i] << endl;

      total += *product_[i];

      if (i % 10 == 0 && i > 0) {

        pause();

      }

    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Total cost of support: $";
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total << endl;

  }

  // Loops through the product_ up to noOfProducts_ and display product if
  // found else display not found.
  int AidApp::SearchProducts(const char* sku)const {

    int found = -1;

    for (int i = 0; i < noOfProducts_; i++) {

      if ((*product_[i]) == sku) {

        found = i;

      }

    }

    return found;

  }

  // Functions

  // Displays the menu and waits for the user to select an option.
  int AidApp::menu() {

    int n = 0;

    cout << "Disaster Aid Supply Management Program"   << endl
         << "1- List products"                         << endl
         << "2- Display product"                       << endl
         << "3- Add non-perishable product"            << endl
         << "4- Add perishable product"                << endl
         << "5- Add to quantity of purchased products" << endl
         << "0- Exit program"                          << endl
         << "> ";

    cin.clear();
    cin >> n;
    cout << endl;


    if (cin.fail()) {

      cin.clear();
      cin.ignore();
      n = -1;

    }

    return n < 6 ? n : -1;

  }

  // Opens the data file for reading, if not found create one.
  void AidApp::loadRecs() {

    int readIndex = 0;

    datafile_.open(filename_, ios::in);

    if (datafile_.fail()) {

      datafile_.clear();
      datafile_.close();

      datafile_.open(filename_, ios::out);

    }
    else {

      char c;

      while (datafile_.good()) {

        c = 'd';
        datafile_ >> c;
        datafile_.ignore(1);

        if (c == 'N') {

          product_[readIndex] = new AmaProduct();
          product_[readIndex]->load(datafile_);
          readIndex++;

        }
        else if (c == 'P') {

          product_[readIndex] = new AmaPerishable();
          product_[readIndex]->load(datafile_);
          readIndex++;

        }
      }
    }

    noOfProducts_ = readIndex;
    datafile_.close();

  }

  // Opens the data file for writing.
  void AidApp::saveRecs() {


    datafile_.open(filename_, ios::out);

    if (!datafile_.fail()) {

      for (int i = 0; i < noOfProducts_; i++) {

        product_[i]->store(datafile_);

      }

      datafile_.close();

    }
  }

  // Updates the quantity on hand for a Product.
  void AidApp::addQty(const char* sku) {

    int found;
    int qty;
    int rm;

    found = SearchProducts(sku);

    if (found != -1) {

      product_[found]->write(cout, false);
      cout << endl << endl;
      cout << "Please enter the number of purchased items: ";
      cin >> qty;

      if (cin.fail()) {

        cout << endl;
        cout << "Invalid quantity value! " << endl << endl;
        cin.clear();
        cin.ignore(1);

      }
      else {

        rm = product_[found]->qtyNeeded() - product_[found]->quantity();

        if (qty <= rm) {

          *product_[found] += qty;

        }
        else {

          *product_[found] += rm;

          cout << "Too many items; only " << rm << " is needed, please return the extra " << (qty - rm) << " items. " << endl;

        }

        saveRecs();
        cout << endl;
        cout << "Updated!" << endl << endl;

      }
    }
    else {

      cout << "Not found!" << endl;

    }
  }

  // Create a Product and get the values from the user.
  void AidApp::addProduct(bool isPerishable) {

    if (isPerishable == true) {

      product_[noOfProducts_] = new AmaPerishable();

    }
    else {

      product_[noOfProducts_] = new AmaProduct();

    }

    cin >> *product_[noOfProducts_];

    if (cin.fail()) {

      product_[noOfProducts_]->write(cout, false);

    }
    else {

      datafile_.open(filename_, ios::out | ios::app);
      product_[noOfProducts_]->store(datafile_);
      datafile_.close();
      cout << endl;
      cout << "Product added" << endl;
      cout << endl;

    }
  }

  // Display the menu, receive the user’s selection, and do the action 
  // requested.
  int AidApp::run() {

    int selected;
    int found;
    char sku[MAX_SKU_LEN];

    while ((selected = menu()) != 0) {

      switch (selected)
      {

      case 1:

        listProducts();
        pause();
        break;

      case 2:

        cout << "Please enter the SKU: ";
        cin >> sku;
        found = SearchProducts(sku);
        cout << endl;
        if (found == -1) {

          cout << "Not found!" << endl << endl;

        }
        else {

          product_[found]->write(cout, false);
          cout << endl;
          pause();

        }
        break;

      case 3:

        addProduct(false);
        loadRecs();
        break;

      case 4:

        addProduct(true);
        loadRecs();
        break;

      case 5:

        cout << "Please enter the SKU: ";
        cin >> sku;
        cout << endl;
        addQty(sku);
        break;

      default:

        cout << "===Invalid Selection, try again.===";
        pause();

      }
    }

    cout << "Goodbye!!" << endl;

    return 0;
  }
}