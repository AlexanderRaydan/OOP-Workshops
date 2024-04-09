/***********************************************************************
// OOP244 Workshop #8:
//
// Version: 1.0
// Author:  Alexander Raydan
//
***********************************************************************/

#ifndef SENECA_IACCOUNT_H_
#define SENECA_IACCOUNT_H_
#include <iostream>

using namespace std;
namespace seneca {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char* str, double); 
}
#endif