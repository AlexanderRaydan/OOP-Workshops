// BankAccount.cpp
#include "BankAccount.h"
#include <cstring>
#include <iomanip>

namespace seneca
{

	BankAccount::BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance)
		: m_openDate(openDate), m_depInfo(depInfo), m_balance(balance)
	{
		strncpy(m_name, name, 50);
		m_name[50] = '\0'; // Ensure null-termination
	}

	double BankAccount::getBalance() const
	{
		return m_balance;
	}

	Date BankAccount::getDate() const
	{
		return m_openDate;
	}

	void BankAccount::setBalance(double balance)
	{
		m_balance = balance;
	}

	void BankAccount::writeCurrency(std::ostream &out, double amount) const
	{
		out << "$" << std::fixed << std::setprecision(2) << amount;
	}

	std::ostream &BankAccount::write(std::ostream &out) const
	{
		out << ">> " << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | " << m_openDate << " | " << m_depInfo;
		return out;
	}

	std::istream &BankAccount::read(std::istream &in)
	{
		std::cout << "Name: ";
		in.getline(m_name, 51);
		std::cout << "Opening Balance: ";
		in >> m_balance;
		std::cout << "Date Opened ";
		in >> m_openDate >> m_depInfo;
		in.ignore(); // Ignore newline character
		return in;
	}

	std::istream &operator>>(std::istream &in, BankAccount &acct)
	{
		return acct.read(in);
	}

	std::ostream &operator<<(std::ostream &out, const BankAccount &acct)
	{
		return acct.write(out);
	}

}
