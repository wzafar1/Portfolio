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
#include "Date.h"
#include "general.h"

namespace sict{

  //Returns the a unique integer number based on the date.
  int Date::value()const {

    return year_ * 372 + mon_ * 31 + day_;

  }

  //Sets the readErrorCode_ member-variable to as mentioned in general.h
  void Date::errCode(int errorCode) {

    switch (errorCode) {

    case 1:

      readErrorCode_ = CIN_FAILED;
      break;

    case 2:

      readErrorCode_ = YEAR_ERROR;
      break;

    case 3:

      readErrorCode_ = MON_ERROR;
      break;

    case 4:

      readErrorCode_ = DAY_ERROR;
      break;

    default:

      readErrorCode_ = NO_ERROR;
      break;

    }

  }

  //Default Constructor.
  Date::Date() {

    setEmpty();  //sets to safe empty state

  }

  //Three argument constructor,set the values of year_, mon_ and day_ .
  Date::Date(int year, int mon, int day) {

    year_ = year;
    mon_ = mon;
    day_ = day;
    readErrorCode_ = NO_ERROR;

  }

  //The following Operators return the comparison of the return value of the value() function of both right and left operand.
  bool Date::operator == (const Date& D)const {

    return this->value() == D.value();

  }

  bool Date::operator != (const Date& D)const {

    return this->value() != D.value();

  }

  bool Date::operator < (const Date& D)const {

    return this->value() < D.value();

  }

  bool Date::operator > (const Date& D)const {

    return this->value() > D.value();

  }

  bool Date::operator <= (const Date& D)const {

    return this->value() <= D.value();

  }

  bool Date::operator >= (const Date& D)const {

    return this->value() >= D.value();

  }

  //Returns the number of days in a month.
  int Date::mdays()const {

    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;     //changed from int mon to mon since it is redefinition of formal parameter 'mon'
    mon--;
    return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));

  }

  //Returns the readErrorCode_ value.
  int Date::errCode()const {

    return readErrorCode_;

  }

  //Returns true if readErrorCode_ is not equal to zero.
  bool Date::bad()const {

    return readErrorCode_ != 0;

  }

  //Reads the date in the following format: YYYY?MM?DD, then return the istr.
  std::istream& Date::read(std::istream& istr) {

    istr >> year_;
    istr.get();
    istr >> mon_;
    istr.get();
    istr >> day_;

    if (istr.fail() == true) {    //checks the status, if istr fails set read error code to 1.

      errCode(1);

    }
    else {

      int valid = 1;

      if (year_<MIN_YEAR || year_>MAX_YEAR) {

        errCode(2);
        valid = 0;

      }

      if ((mon_ < 1 && mon_ > 12) && valid != 0) {

        errCode(3);
        valid = 0;

      }

      if ((day_ > mdays() && day_ < 0 ) && valid != 0) {

        errCode(4);

      }
    }
    
    return istr;

  }

  //Writes the data in the following format: YYYY/MM/DD, then return the ostr.
  std::ostream& Date::write(std::ostream& ostr)const {

    ostr << std::right << year_ << "/";        // Since we want to right fill not left, we use right in ostr. Also since it is in std
                                               // we use std::right to set ostr to right.
    ostr.width(2);
    ostr.fill('0');
    ostr << mon_ << "/";
    ostr.width(2);   
    ostr.fill('0');  
    ostr << day_;

    return ostr;

  }

  //overload the operator << to work with cout to print a date.
  std::ostream& operator << (std::ostream& ostr, const Date& D1) {

    return D1.write(ostr);

  }

  //overload the operator >> to work with cin to read a date.
  std::istream& operator >> (std::istream& istr, Date& D1) {

    return D1.read(istr);

  }

  //Set to safe empty state
  void Date::setEmpty() {

    year_ = 0;
    mon_ = 0;
    day_ = 0;
    readErrorCode_ = NO_ERROR;

  }

}
