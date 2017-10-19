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

#ifndef SICT_GENERAL_H__
#define SICT_GENERAL_H__

namespace sict {

#define TAX 0.13             //The tax value for the NFI items.
#define MAX_SKU_LEN 7        //The maximum size of a SKU.
#define DISPLAY_LINES 10     //Product lines to display before each pause.
#define MIN_YEAR 2000        //The min and max for year to be used for date validation.
#define MAX_YEAR 2030        //
#define MAX_NO_RECS 2000     //The maximum number of records in the data file.

}

#endif