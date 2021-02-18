#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
	  m_number = -1;
	  m_balance = 0.0;
   }
   // New account
   Account::Account() {  
	  m_number = 0;
	  m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
	  setEmpty();
	  if (number >= 10000 && number <= 99999
		 && balance > 0) {
		 m_number = number;
		 m_balance = balance;
	  }
   }
   std::ostream& Account::display() const{
	  if (*this) {  
		 cout << " ";
		 cout << m_number;
		 cout << " | ";
		 cout.width(12);
		 cout.precision(2);
		 cout.setf(ios::right);
		 cout.setf(ios::fixed);
		 cout << m_balance;
		 cout.unsetf(ios::right);
		 cout << " ";
	  }
	  else if(~*this) {
		 cout << "  NEW  |         0.00 ";
	  }
	  else {
		 cout << "  BAD  |    ACCOUNT   ";
	  }
	  return cout;
   }

   Account::operator bool() const {
	   return (m_number >= 10000 || m_balance != 0);
   }

   Account::operator int() const {
	   return m_number;
   }

   Account::operator double() const {
	   return m_balance;
   }

   bool Account::operator~() const {
	   return (m_number < 10000 || m_balance == 0);
   }

   Account& Account::operator=(int accNum) {
	   if (accNum >= 10000) {
		   m_number = accNum;
	   } else {
		   m_number = -1;
	   }
	   return *this;
   }

   Account& Account::operator=(Account acc) {
	   if (*this || acc) {
		   // Move Account Number
		   m_number = acc.m_number;
		   acc.m_number = 0;

		   // Move Balance
		   m_balance = acc.m_balance;
		   acc.m_balance = 0;
	   }
	   return *this;
   }

   Account& Account::operator+=(double bal) {
	   if (*this) {
		   if (bal > 0) {
			   m_balance += bal;
		   }
	   }
	   return *this;
   }

   Account& Account::operator-=(double bal) {
	   if (*this) {
		   if (bal > 0) {
			   m_balance -= bal;
		   }
	   }
	   return *this;
   }

   Account& Account::operator<<(Account rightAcc) {
	   if (*this || rightAcc) {
		   if (m_number != rightAcc.m_number) {
			   m_balance += rightAcc.m_balance;
			   rightAcc.m_balance = 0;
		   }
	   }
	   return *this;
   }

   Account& Account::operator>>(Account rightAcc) {
	   if (*this || rightAcc) {
		   rightAcc.m_balance += m_balance;
		   m_balance = 0;
	   }
	   return *this;
   }

   double Account::operator+(const Account& acc) {
	   return m_balance + acc.m_balance;
   }

   double& Account::operator+=(const Account& acc) {
	   if (*this || acc) {
		   return m_balance += acc.m_balance;
	   } else {
		   return m_balance += 0;
	   }
   }

}