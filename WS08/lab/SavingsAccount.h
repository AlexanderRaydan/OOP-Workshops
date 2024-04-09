/***********************************************************************
// OOP244 Workshop #8:
//
// Version: 1.0
// Author:  Alexander Raydan
//
***********************************************************************/
#ifndef SENECA_SAVINGS_ACCOUNT_H_
#define SENECA_SAVINGS_ACCOUNT_H_
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca
{
	class SavingsAccount : public Account
	{
		double m_interest;

	public:
		SavingsAccount(double initialBalance, double interest);
		void monthEnd();
		void display(std::ostream &ostr) const;
	};
}
#endif
