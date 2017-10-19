/*
OOP244 Workshop 8: Account
File: SavingAccount.h
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double m_interestRate; // interest rate (percentage) 
		public:

      SavingsAccount(double balance, double interestRate) : Account(balance) {

        if (interestRate < 0) {

          m_interestRate = 0;

        }
        else {

          m_interestRate = interestRate;

        }

      };

      double calculateInterest();
      void display(ostream& cout);


   };
};
#endif
