/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #5 p1

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////
*/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_

namespace seneca
{
   const int ACCT_MAXLEN_USER = 16; // Max Length of user name

   const double CHECKING_TRANSACTION_FEE = 1.25;
   const double SAVING_TRANSACTION_FEE = 3.50;

   const double CHECKING_INTEREST_RATE = 0.5;
   const double SAVING_INTEREST_RATE = 2.5;

   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char m_userName[ACCT_MAXLEN_USER];
      double m_funds;
      bool m_checking;
      int m_monthlyTransactions;

      bool isOpen() const;

   public:
      bankAccount(const char *name = nullptr, bool checking = false);
      bool setup(const char *name, bool checking);

      void display() const;

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      // ...

      operator bool() const;
      operator double() const;

      bankAccount &operator++();
      bankAccount &operator--();

      bool operator+=(double);
      bool operator-=(double);

      bool operator==(const bankAccount &) const;
      bool operator>(double) const;
      bool operator<=(double) const;

      bool operator<<(bankAccount &);
   };

   // ADD: Global helpers
   // ...
   bool operator>(double lhs, const bankAccount &rhs);
   bool operator<=(double lhs, const bankAccount &rhs);

}

#endif