/*
OOP244 Workshop 8: Account
File: Account.cpp
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
  Account::Account(double balance) {

    if (balance >= 0) {

      m_balance = balance;

    }
    else {

      m_balance = 0;

    }

  }

  // credit (add) an amount to the account balance
  void Account::credit(double add) {

    m_balance += add;

  }

  // debit (subtract) an amount from the account balance return bool 

  bool Account::debit(double subtract) {

    if (m_balance >= subtract) {

      m_balance -= subtract;
      return true;

    }
    else {

      return false;

    }

  }

	double Account::getBalance() const
	{
		return m_balance;
	} 

	void Account::setBalance( double newBalance )
	{
		m_balance = newBalance;
	} 
}