// SavingsAccount.cpp
#include "SavingsAccount.h"
#include <iomanip>

namespace seneca
{

	SavingsAccount::SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
		: BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

	void SavingsAccount::applyInterest(Date &dt)
	{
		double interestAmount = getBalance() * m_interest;

		Date old_interestDate = m_interestDate;
		setBalance(getBalance() + interestAmount);
		m_interestDate = dt;
		std::cout << "   ";
		writeCurrency(std::cout, getBalance() - interestAmount);
		std::cout << " + ";
		writeCurrency(std::cout, interestAmount);
		std::cout << " (" << std::fixed << std::setprecision(3) << m_interest << "%) = ";
		writeCurrency(std::cout, getBalance());
		std::cout << " | " << old_interestDate << " => " << m_interestDate << std::endl;
	}

	void SavingsAccount::writeInterest(std::ostream &out) const
	{
		out << std::fixed << std::setprecision(3) << m_interest << "%";
	}

	std::ostream &SavingsAccount::write(std::ostream &out) const
	{
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | " << m_interestDate;
		return out;
	}

	std::istream &SavingsAccount::read(std::istream &in)
	{
		BankAccount::read(in);
		std::cout << "Interest Date ";
		in >> m_interestDate;
		std::cout << "Interest Rate: ";
		in >> m_interest;
		in.ignore(); // Ignore newline character
		return in;
	}

	std::istream &operator>>(std::istream &in, SavingsAccount &acct)
	{
		return acct.read(in);
	}

	std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct)
	{
		return acct.write(out);
	}

}
