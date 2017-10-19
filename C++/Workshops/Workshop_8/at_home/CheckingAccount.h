/*
OOP244 Workshop 8: Account
File: CheckingAccount.h
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double m_transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
      void chargeFee(double transactionFee);
		
		public:

			// constructor initializes balance and transaction fee 
      CheckingAccount(double balance, double transactionFee);
			// function prototype to override credit function
      void credit(double val);
			// function prototype to override debit function
      bool debit(double val);
			// function prototype to  override display function
      void display(ostream& cout);

	};
};
#endif
