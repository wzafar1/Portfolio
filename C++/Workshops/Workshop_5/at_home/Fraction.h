/*
OOP244 Workshop 5: Fraction
File: Fraction.h
Version 1.0
Date: 20/06/2017
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
    //Member Functions

    Fraction();
    Fraction(int num, int denom);
    
    // Functions
    bool isEmpty() const;
    void display() const;

    //To reduce code redundancy
    void setEmpty();

    //Operators

    Fraction operator+(const Fraction& FC) const;
    Fraction operator*(const Fraction& FC);
    bool operator==(const Fraction& FC) const;
    bool operator!=(const Fraction& FC) const;
    Fraction& operator+=(const Fraction& FC);


    

  };

}

#endif 