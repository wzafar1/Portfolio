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
			// TODO: Write a prototype for constructor which initializes balance
        Account(double balance);
			// TODDO: Write a function prototype for the virtual function credit 
        virtual void credit(double add);
			// TODO: Write a function prototype for the virtual function debit
        virtual bool debit(double subtract);
			// TODO: Write a function prototype for the virtual function display
        virtual void display(ostream& cout) = 0;
   };
};
#endif
