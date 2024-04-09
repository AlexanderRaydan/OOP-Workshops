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
#include "ChequingAccount.h"

using namespace std;
namespace seneca
{
    ChequingAccount::ChequingAccount(double initialBalance, double transactionFee, double monthlyFee) : Account(initialBalance)
    {
        transactionFee > 0 ? m_transactionFee = transactionFee : m_transactionFee = 0.0;
        monthlyFee > 0 ? m_monthlyFee = monthlyFee : m_monthlyFee = 0.0;
    }
    bool ChequingAccount::credit(double value)
    {
        if (Account::credit(value))
        {
            Account::debit(m_transactionFee);
            return true;
        }
        return false;
    }
    bool ChequingAccount::debit(double value)
    {
        if (Account::debit(value))
        {
            Account::debit(m_transactionFee);
            return true;
        }
        return false;
    }
    void ChequingAccount::monthEnd()
    {
        Account::debit(m_monthlyFee);
    }

    void ChequingAccount::display(std::ostream &ostr) const
    {
        ostr << "Account type: Chequing" << endl;
        ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << endl;
        ostr << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << m_transactionFee << endl;
        ostr << "Monthly Fee: " << std::fixed << std::setprecision(2) << m_monthlyFee << endl;
    }
}