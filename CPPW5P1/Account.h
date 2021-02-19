// Workshop 5: Lab
// Date: 2/18/21
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#pragma once
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // Type conversion operators
      operator bool()const;
      operator int()const;
      operator double()const;

      // Unary member operator
      bool operator ~ ()const;

      // Assign Account Number
      Account& operator = (int accNum);

      // Move Account
      Account& operator = (Account& acc);

      // Deposit
      Account& operator += (double bal);

      // Withdraw
      Account& operator -= (double bal);

      // Move Funds
      Account& operator << (Account& rightAcc);

      // Move Funds
      Account& operator >> (Account& rightAcc);
   };

   // Get Sum
   double operator + (const Account& leftAcc, const Account& rightAcc);

   // Get sum and store
   double operator += (double& bal, const Account& acc);
   
}
#endif // SDDS_ACCOUNT_H_