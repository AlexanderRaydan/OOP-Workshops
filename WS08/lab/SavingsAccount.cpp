/***********************************************************************
// OOP244 Workshop #8:
//
// Version: 1.0
// Author:  Alexander Raydan
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;
namespace seneca
{
	SavingsAccount::SavingsAccount(double initialBalance, double interest) : Account(initialBalance)
	{
		interest > 0 ? m_interest = interest : m_interest = 0.0;
	}
	void SavingsAccount::monthEnd()
	{
		double currentBalance = balance();
		if (currentBalance > 0.0)
		{
			double interestEarned = currentBalance * m_interest;
			credit(interestEarned);
		}
	}
	void SavingsAccount::display(std::ostream &ostr) const
	{
		ostr << "Account type: Savings" << endl;
		ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << endl;
		ostr << "Interest Rate (%): " << std::fixed << std::setprecision(2) << (m_interest * 100) << endl;
	}
}