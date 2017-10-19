/*
OOP244 Workshop 8: Account
File: Account.h
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account{
		private:
			double m_balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:

			// constructor which initializes balance
        Account(double balance);
			// virtual function credit 
        virtual void credit(double add);
			// virtual function debit
        virtual bool debit(double subtract);
			// Pure virtual function display
        virtual void display(ostream& cout) = 0;
   };
};
#endif
