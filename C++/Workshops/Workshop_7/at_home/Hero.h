/*
OOP244 Workshop 7: Hero
File: Hero.h
Version 1.0
Date: 06/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {

  class Hero {
    char m_name[41];
    int  m_attack;
    int  m_maximumHealth;
    int  m_health;

    bool isEmpty() const;

  public:
    // constructors
    Hero();
    Hero(const char name[], int maximumHealth, int attack);

    // member functions
    void respawn();
    void setEmpty(); //Created to avoid code redundancy
    bool isAlive() const { return m_health > 0; }
    int  getAttack() const { return m_attack; }
    void deductHealth(int);

    // friend helper function to insert name into ostream
    friend std::ostream& operator<<(std::ostream&, const Hero&);
  };

  void applyDamage(Hero& A, Hero& B);
  const Hero & operator*(const Hero &, const Hero &);


}

#endif
