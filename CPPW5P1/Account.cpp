// Workshop 5: Lab
// Date: 2/18/21
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
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
	   return (m_number == 0);
   }

   Account& Account::operator=(int accNum) {
	   if (accNum >= 10000) {
		   m_number = accNum;
	   } else {
		   m_number = -1;
	   }
	   return *this;
   }

   Account& Account::operator=(Account& acc) {
	   int tempNumber;
	   double tempBalance;
	   if (*this || acc) {
		   // Move Account Number
		   tempNumber = m_number;
		   m_number = acc.m_number;
		   acc.m_number = tempNumber;

		   // Move Balance
		   tempBalance = m_balance;
		   m_balance = acc.m_balance;
		   acc.m_balance = tempBalance;
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
	   double temp = 0;
	   if (*this && bal > 0) {
		   temp = (double)*this - bal;
		   if (temp > 0) {
			   m_balance = temp;
		   }
	   }
	   return *this;
   }

   Account& Account::operator<<(Account& rightAcc) {
	   if (*this && rightAcc) {
		   if (m_number != rightAcc.m_number) {
			   m_balance += rightAcc.m_balance;
			   rightAcc.m_balance = 0;
		   }
	   }
	   return *this;
   }

   Account& Account::operator>>(Account& rightAcc) {
	   if (*this && rightAcc) {
		   rightAcc.m_balance += m_balance;
		   m_balance = 0;
	   }
	   return *this;
   }

   double operator+(const Account& leftAcc, const Account& rightAcc) {
	   return (double)leftAcc + (double)rightAcc;
   }

   double operator+=(double& bal, const Account& acc) {
	   return bal += (double)acc;
   }
}