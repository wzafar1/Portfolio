/*
OOP244 Workshop 8: Account
File: SavingAccount.cpp
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include "SavingsAccount.h"

using namespace std;

namespace ict{ 

  SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {

    if (interestRate < 0) {

      m_interestRate = 0;

    }
    else {

      m_interestRate = interestRate;

    }

  };
	
  double SavingsAccount::calculateInterest() {

    return m_interestRate > 0 ? (m_interestRate*getBalance()) : (getBalance());

  }

  void SavingsAccount::display(ostream& cout) {

    cout << "Account type: Saving" << endl;
    cout.precision(2);
    cout << "Balance: $ " << fixed << getBalance() << endl;
    cout << "Interest Rate (%): " << fixed << m_interestRate * 100 << endl;

  }

}