// SavingsAccount.h
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"
#include "DepositUtility.h"
#include <iostream>

namespace seneca
{

	class SavingsAccount : public BankAccount
	{
	private:
		double m_interest;
		Date m_interestDate;

		void writeInterest(std::ostream &out) const;

	public:
		SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date &dt);
		std::ostream &write(std::ostream &out) const;
		std::istream &read(std::istream &in);

		friend std::istream &operator>>(std::istream &in, SavingsAccount &acct);
		friend std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct);
	};

}

#endif // SAVINGSACCOUNT_H
