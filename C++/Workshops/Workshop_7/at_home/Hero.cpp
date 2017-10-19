/*
OOP244 Workshop 7: Hero
File: Hero.cpp
Version 1.0
Date: 13/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;

namespace sict {

  //////////////////////////////////////////////
  // Default constructor
  //
  Hero::Hero()
  {

    setEmpty();

  }

  ///////////////////////////////////////////////////
  // Constructor
  // 
  Hero::Hero(const char name[], int maximumHealth, int attack)
  {
    if (name != nullptr && name[0] != '\0') {

      strncpy(m_name, name, 40);
      m_name[41] = '\0';
      m_attack = attack;
      m_maximumHealth = maximumHealth;
      m_health = maximumHealth;

    }
    else {

      setEmpty();

    }

  }

  /////////////////////////////////////////////////////////
  // ostream helper overloaded operator <<
  // 
  std::ostream& operator<<(std::ostream& out, const Hero& h)
  {

    out << h.m_name;
    return out;

  }

  /////////////////////////////////////////////////
  // Hero::isEmpty ()
  // return true if the Hero object is uninitialized
  //
  bool Hero::isEmpty() const
  {

    if (m_name[0] == '\0' || m_maximumHealth < 0) {

      return true;

    }
    else {

      return false;

    }

  }

  /////////////////////////////////////////////////
  // sets the Hero object's health back to full
  //
  void Hero::respawn()
  {

    m_health = m_maximumHealth;

  }

  void Hero::deductHealth(int attack)
  {

    if (m_health != 0) {

      m_health = m_health - attack;

    }

  }

  //////////////////////////////////////////////////////////////////
  // Global helper function
  // compute the damage that A inflicts on B 
  // and of B on A
  //
  void applyDamage(Hero& A, Hero& B)
  {

    A.deductHealth(B.getAttack());
    B.deductHealth(A.getAttack());

  }

  //////////////////////////////////////////////////////////////////
  // Global helper operator
  // rather than type in fight(hercules, theseus), we use an operator
  // so you can type in hercules * theseus
  //
  // returns a reference to the winner object
  // 
  // so that if hercules is stronger, 
  // (hercules * theseus) == hercules
  // will be true.
  // 
  // note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
  //
  const Hero & operator* (const Hero & first, const Hero & second) {
    // Display the names of the people fighting

    cout << "AncientBattle! " << first << " vs " << second << " : ";

    // We want our heroes to exit the battle unharmed, so 
    // we make the input arguments const.
    // So how can we modify the objects during the fight?
    // We make copies of them.
    Hero A = first;
    Hero B = second;
    const Hero *winner = nullptr;

    // Now A will fight B, and winner will point to the winner.    
    // Main fight loop
    unsigned int rounds = 0;
    // loop while both are still alive
    // fight for 100 rounds
    while (A.isAlive() && B.isAlive() && rounds < 100)
    {
      rounds++;
      applyDamage(A, B);
    }

    // if we got here, then one Hero is dead, or if both are alive then it was a draw.
    bool draw;

    if (A.isAlive() && B.isAlive()) { draw = true; }
    else { draw = false; }

    // if it was a draw, then we decide by tossing an unfair coin and always
    // declare that A was the winner. 
    if (draw)
    {
      winner = &first;
    }
    else if (A.isAlive())
    {
      winner = &first;
    }
    else
    {
      winner = &second;
    }

    // print out the winner
    cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

    // return a reference to the winner
    return *winner;
  }

  void Hero::setEmpty() {

    m_name[0] = '\0';
    m_health = 0;
    m_maximumHealth = 0;
    m_attack = 0;

  }


}

