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

#ifndef ICT_AID_APP_H
#define ICT_AID_APP_H

#include"AmaPerishable.h"

namespace sict {

  class AidApp {

  private:

    char filename_[256];                                       // Holds the name of the text file.
    Product* product_[MAX_NO_RECS];                            // An array of Product pointers, MAX_NO_RECS long.
    std::fstream datafile_;                                    // An fstream instance used to create and access a file.
    int noOfProducts_;                                         // Stores Number of Products.

    // Constructor
    AidApp(const AidApp& filename) = delete;                   // Copy operator.
    AidApp& operator =  (const AidApp& filename) = delete;     // copy assignment operator.

    // Queries

    void pause() const;                                        // Waits for the user to hit enter, others keys are ignored.
    void listProducts() const;                                 // Display the products currently in Product* .
    int SearchProducts(const char* sku)const;                  // Loops through the product_ up to noOfProducts_ and display product if
                                                               // found else display not found.

    // Functions

    int menu();                                                // Displays the menu and waits for the user to select an option.
    void loadRecs();                                           // Opens the data file for reading, if not found create one.
    void saveRecs();                                           // Opens the data file for writing.
    void addQty(const char* sku);                              // Updates the quantity on hand for a Product.
    void addProduct(bool isPerishable);                        // Create a Product and get the values from the user.

  public:

    AidApp(const char* filename);                              // Default constructor.
    int run();                                                 // Display the menu, receive the user’s selection, and do the action 
                                                               // requested.

  };

}

#endif // !ICT_AID_APP_H
