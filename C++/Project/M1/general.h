// Final Project Milestone 1
//
// Version 1.0
// Date: 07/07/2017
// Author: Wahab Zafar
// Email: wzafar1@myseneca.ca
// Description:
// The Date class encapsulates a date value in three integers for year, month and day, 
// and is readable by istreams and printable by ostream using the following format for 
// both reading and writing
// Revision History
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