/***********************************************************************
// OOP244 Workshop #8:
//
// Version: 1.0
// Author:  Alexander Raydan
//
***********************************************************************/

#ifndef SENECA_CHECKING_ACCOUNT_H_
#define SENECA_CHECKING_ACCOUNT_H_
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca
{
    class ChequingAccount : public Account
    {
        double m_transactionFee;
        double m_monthlyFee;

    public:
        ChequingAccount(double initialBalance, double transactionFee, double monthlyFee);
        bool credit(double value);
        bool debit(double value);
        void monthEnd();
        void display(std::ostream &ostr) const;
    };
}
#endif