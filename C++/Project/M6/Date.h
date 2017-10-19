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

#ifndef ICT_DATE_H__
#define ICT_DATE_H__

namespace sict{

#define NO_ERROR   0   //No error the date is valid.
#define CIN_FAILED 1   //istream failed when entering information.
#define YEAR_ERROR 2   //Year value is invalid.
#define MON_ERROR  3   //Month value is invalid.
#define DAY_ERROR  4   //Day value is invalid.

  class Date {

  private:

    //Member data

    int year_;           //Holds year between MIN_YEAR and MAX_YEAR (defined in general.h)
    int mon_;            //Month of the year, between 1 to 12
    int day_;            //Day of the month
    int readErrorCode_;  //Holds the error codewith which the caller program can reference

    //Private Member Function

    int value()const;              //Returns the a unique integer number based on the date
    void errCode(int errorCode);   //Sets the readErrorCode_ member-variable (as mentioned in general.h)

  public:

    //Constructors

    Date();                           //Default Constructor
    Date(int year, int mon, int day); //Three argument constructor,set the values of year_, mon_ and day_ ,
                                      //also readErrorCode to NO_ERROR

    //Set to safe empty state
    void setEmpty();

    //Public Member Function

    bool operator == (const Date& D)const;  //These operators return the comparison result of 
    bool operator != (const Date& D)const;  //the return value of the value() function
    bool operator < (const Date& D)const;   //applied to left and right operands.
    bool operator > (const Date& D)const;   //
    bool operator <= (const Date& D)const;  //
    bool operator >= (const Date& D)const;  //

    int mdays()const; //Returns the number of days in a month.

    //Accessor or getter member functions.

    int errCode()const;   //Returns the readErrorCode_ value.
    bool bad()const;   	  //Returns true if readErrorCode_ is not equal to zero.
    
    //IO member-funtions

    std::istream& read(std::istream& istr);        //Reads the date in the following format: YYYY?MM?, then return the istr.
    std::ostream& write(std::ostream& ostr)const;  //Writes the data in the following format: YYYY/MM/DD, then return the ostr.


  };

  std::ostream& operator << (std::ostream& ostr, const Date& D1);  //overload the operator << to work with cout to print a date.
  std::istream& operator >> (std::istream& istr, Date& D1);  //overload the operator >> to work with cin to read a date.

}
#endif