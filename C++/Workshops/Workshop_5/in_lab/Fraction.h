/*
OOP244 Workshop 5: Fraction
File: Fraction.h
Version 1.0
Date: 15/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef _ICT_FRACTION_H
#define _ICT_FRACTION_H
namespace sict {

  class Fraction {

    int f_num;
    int f_denom;

    int gcd() const; // returns the greatest common divisor of num and denom
    int max() const; // returns the maximum of num and denom
    int min() const; // returns the minimum of num and denom
    void reduce();   // simplifies a Fraction by dividing the 
                     // numerator and denominator to their greatest common divisor 
  public:
    // TODO: declare the member functions

    Fraction();
    Fraction(int num, int denom);

    bool isEmpty() const;
    void display() const;

    void setEmpty();

    Fraction operator+(const Fraction&);

    // TODO: declare the + operator overload

  };

}

#endif 