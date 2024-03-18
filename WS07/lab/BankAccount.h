#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "DepositUtility.h"
#include <iostream>

namespace seneca
{

	class BankAccount
	{
	private:
		char m_name[51];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance;

	protected:
		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(std::ostream &out, double amount) const;
		Date getDate() const;

	public:
		BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance);
		std::ostream &write(std::ostream &out) const;
		std::istream &read(std::istream &in);

		friend std::istream &operator>>(std::istream &in, BankAccount &acct);
		friend std::ostream &operator<<(std::ostream &out, const BankAccount &acct);
	};

}

#endif // BANK_ACCOUNT_H
