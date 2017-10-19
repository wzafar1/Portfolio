/*
OOP244 Workshop 5: Fraction
File: Fraction.cpp
Version 1.0
Date: 15/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#include<iostream>
#include"Fraction.h"

namespace sict {

  using namespace std;

  Fraction::Fraction() {

    setEmpty();

  };

  Fraction::Fraction(int num, int denom) {

    if (num > 0 && denom > 0) {

      f_num = num;
      f_denom = denom;
      reduce();

    }
    else {

      setEmpty();

    }
  };

  void Fraction::setEmpty() {

    f_denom = -1;

  };

  int Fraction::max() const {

    return (f_num >= f_denom) ? f_num : f_denom;

  };

  int Fraction::min() const {

    return (f_num >= f_denom) ? f_denom : f_num;

  }

  void Fraction::reduce() {

    int temp = gcd();
    f_num = f_num / temp;
    f_denom = f_denom / temp;

  };

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
  };

  bool Fraction::isEmpty() const {

    if (f_denom == -1) {

      return true;

    }
    else {

      return false;

    }

  };

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

  };

  Fraction Fraction::operator+(const Fraction& c1)  {

    Fraction temp = Fraction();

    if (!isEmpty() && !c1.isEmpty()) {

      temp.f_num = (f_num * c1.f_denom) + (f_denom * c1.f_num);
      temp.f_denom = f_denom * c1.f_denom;

    }
    temp.reduce();
    return temp;

  };

}
