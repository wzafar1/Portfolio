/*
OOP244 Workshop 8: Account
File: CheckingAccount.h
Version 1.0
Date: 20/07/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// CheckingAccount class member functions

  void CheckingAccount::chargeFee(double transactionFee) {

    setBalance(getBalance() - transactionFee);

  }

  // constructor initializes balance and transaction fee 
  CheckingAccount::CheckingAccount(double balance, double transactionFee) : Account(balance) {

    if (transactionFee >= 0) {

      m_transactionFee = transactionFee;

    }
    else {

      m_transactionFee = 0;

    }

  }

  // function prototype to override credit function
  void CheckingAccount::credit(double val) {

    Account::credit(val);
    chargeFee(m_transactionFee);

  }

  // function prototype to override debit function
  bool CheckingAccount::debit(double val) {

    bool flag = Account::debit(val);

    if (flag == true) {

      chargeFee(m_transactionFee);
      return true;

    }
    else {

      return false;

    }

  }

  // function prototype to  override display function
  void CheckingAccount::display(ostream& cout) {

    cout << "Account type: Checking" << endl;
    cout.precision(2);
    cout << "Balance: $ " << fixed << getBalance() << endl;
    cout << "Transaction Fee: " << fixed << m_transactionFee << endl;

  }

}