/*
OOP244 Workshop 5: Fraction
File: Fraction.cpp
Version 1.0
Date: 20/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#include<iostream>
#include"Fraction.h"

namespace sict {

  using namespace std;

  Fraction::Fraction() {

    setEmpty();

  }

  Fraction::Fraction(int num, int denom) {

    if (num > 0 && denom > 0) {

      f_num = num;
      f_denom = denom;
      reduce();

    }
    else {

      setEmpty(); //call setEmpty funcntion to set it to empaty state

    }
  }

  void Fraction::setEmpty() {

    f_denom = -1; //sets to empty state

  }

  int Fraction::max() const {

    return (f_num >= f_denom) ? f_num : f_denom; //returns maximum of numerator and denominator

  }

  int Fraction::min() const {

    return (f_num >= f_denom) ? f_denom : f_num; ////returns mminimum of numerator and denominator

  }

  void Fraction::reduce() {

    int temp = gcd();
    f_num = f_num / temp;
    f_denom = f_denom / temp;

  }

  int Fraction::gcd() const {
    int mn = min();  // min of numerator and denominator
    int mx = max();  // max of numerator and denominator
    int g_c_d = 1;
    bool found = false;

    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
      if (mx % x == 0 && mn % x == 0) {
        found = true;
        g_c_d = x;
      }
    }
    return g_c_d;
  }

  bool Fraction::isEmpty() const {   //checks if in empty state

    if (f_denom == -1) {

      return true;

    }
    else {

      return false;

    }

  }

  void Fraction::display() const {

    if (f_denom == 1) {

      cout << f_num;

    }
    else if (f_denom != -1) {

      cout << f_num << "/" << f_denom;

    }
    else {

      cout << "no fraction stored";

    }

  }

  // + operator overloading
  // some changes made to the + operator for at_home as compared to the one in In_lab.

  Fraction Fraction::operator+(const Fraction& FC) const {  

    Fraction temp = *this;

    if (!isEmpty() && !FC.isEmpty()) {

      temp.f_num = (temp.f_num * FC.f_denom) + (temp.f_denom * FC.f_num);
      temp.f_denom = temp.f_denom * FC.f_denom;

    }

    temp.reduce();
    return temp;

  }

  // * operator overloading

  Fraction Fraction::operator*(const Fraction& FC) {

    Fraction temp = Fraction();

    if (!isEmpty() && !FC.isEmpty()) {

      temp.f_num = f_num * FC.f_num;  //Numerator multiplication
      temp.f_denom = f_denom * FC.f_denom;  //Denominator multiplication

    }

    temp.reduce();  //reduces the fraction
    return temp;

  }

  // == operator overloading

  bool Fraction::operator==(const Fraction& FC) const {

    bool equal = 0;

    if (!isEmpty() && !FC.isEmpty()) {

      if (f_num == FC.f_num && f_denom == FC.f_denom) {

        equal = 1;

      }

    }

    return equal;

  }

  // Checks if two objects are not equal

  bool Fraction::operator!=(const Fraction& FC) const {

    bool unequal = 0;

    if (!isEmpty() && !FC.isEmpty()) {

      if (f_num != FC.f_num || f_denom != FC.f_denom) {

        unequal = 1;

      }

    }

    return unequal;

  }

  // += operator overloading and the result is assigned to current object

  Fraction& Fraction::operator+=(const Fraction& FC) {

    *this = *this + FC;  //calls + operator function to add
    return *this;

  }

}
