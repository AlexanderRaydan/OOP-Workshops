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
#include "Account.h"

using namespace std;
namespace seneca
{
    double Account::balance() const
    {
        return m_balance;
    }
    Account::Account(double initialBalance)
    {

        initialBalance > 0 ? m_balance = initialBalance : m_balance = 0.0;
    }
    bool Account::credit(double value)
    {
        if (value > 0)
        {
            m_balance += value;
            return true;
        }
        return false;
    }
    bool Account::debit(double value)
    {
        if (value > 0)
        {
            m_balance -= value;
            return true;
        }
        return false;
    }
}
