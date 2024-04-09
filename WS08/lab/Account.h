/***********************************************************************
// OOP244 Workshop #8:
//
// Version: 1.0
// Author:  Alexander Raydan
//
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>
#include "iAccount.h"

using namespace std;
namespace seneca
{
    class Account : public iAccount
    {
        double m_balance;

    protected:
        double balance() const;

    public:
        Account(double initialBalance = 0.0);
        bool credit(double value);
        bool debit(double value);
    };
}
#endif