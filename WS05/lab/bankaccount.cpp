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
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char *name, bool checking)
	{
		m_userName[0] = '\0'; // Empty string implies is account is not open
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char *name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	void bankAccount::display() const
	{
		if (isOpen())
		{
			cout << "Display Account -> User:"
				 << setw(16) << setfill('-') << m_userName << " | "
				 << (m_checking ? "Checking" : " Savings")
				 << " | Balance: $ " << setw(7) << setfill(' ') << m_funds
				 << " | Transactions:"
				 << fixed << setw(3) << setfill('0') << m_monthlyTransactions << endl;
		}
		else
		{
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const
	{
		return this->isOpen();
	}

	bankAccount::operator double() const
	{
		return m_funds;
	}

	bankAccount &bankAccount::operator++()
	{

		if (!(this->isOpen() && m_funds > 0))
		{
			return *this;
		}

		if (m_checking)
		{
			m_funds += ((CHECKING_INTEREST_RATE * m_funds) / 100);
		}
		else
		{
			m_funds += ((SAVING_INTEREST_RATE * m_funds) / 100);
		}

		return *this;
	}

	bankAccount &bankAccount::operator--()
	{

		if (!(this->isOpen()))
		{
			return *this;
		}

		if (m_checking)
		{
			m_funds -= (CHECKING_TRANSACTION_FEE * m_monthlyTransactions);
		}
		else
		{
			m_funds -= (SAVING_TRANSACTION_FEE * m_monthlyTransactions);
		}

		return *this;
	}

	bool bankAccount::operator+=(double rightOpr)
	{

		if (!(this->isOpen()))
		{
			return false;
		}

		if (rightOpr >= 0)
		{
			cout << "Deposit $" << fixed << setprecision(2) << rightOpr << " for " << m_userName << endl;
		}
		else
		{
			cout << "Withdraw $" << fixed << setprecision(2) << rightOpr * -1 << " for " << m_userName << endl;
		}

		m_funds += rightOpr;
		m_monthlyTransactions++;

		return true;
	}

	bool bankAccount::operator-=(double rightOpr)
	{

		return *this += (rightOpr * -1);
	}

	bool bankAccount::operator==(const bankAccount &rightOpr) const
	{

		return (m_checking == rightOpr.m_checking &&
				strcmp(m_userName, rightOpr.m_userName) == 0 &&
				m_funds == rightOpr.m_funds);
	}

	bool bankAccount::operator>(double rightOpr) const
	{
		if (!(this->isOpen()))
		{
			return false;
		}

		return m_funds > rightOpr;
	}

	bool bankAccount::operator<=(double rightOpr) const
	{
		if (!(this->isOpen()))
		{
			return false;
		}

		return !(*this > rightOpr);
	}

	bool bankAccount::operator<<(bankAccount &rightOpr)
	{

		if (!(this->isOpen() && rightOpr.isOpen() && (rightOpr > 0.0)))
		{
			return false;
		}

		cout << "Transfer $" << fixed << setprecision(2) << rightOpr.m_funds << " from " << rightOpr.m_userName << " to " << this->m_userName << endl;

		*this += rightOpr.m_funds;
		rightOpr -= rightOpr.m_funds;

		return true;
	}

	// ADD: Global Helper Functions

	bool operator>(double lhs, const bankAccount &rhs)
	{

		if (!((bool)rhs))
		{
			return false;
		}

		return lhs > (double)rhs;
	}

	bool operator<=(double lhs, const bankAccount &rhs)
	{
		return !(lhs > rhs);
	}
}
