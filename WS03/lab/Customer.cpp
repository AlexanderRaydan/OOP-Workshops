
/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #3

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Customer.h"

using namespace std;

namespace seneca
{
    bool Customer::isEmpty() const
    {
        bool result =
            m_id == 0 ||
            m_name == nullptr ||
            m_name[0] == '\0';

        return result;
    }

    void Customer::setEmpty()
    {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::deallocateMemory()
    {
        delete[] m_name;
        delete m_car;

        setEmpty();
    }

    void Customer::set(int customerId, const char *name, const Car *car)
    {
        deallocateMemory();

        if (customerId != 0 && name != nullptr && name[0] != '\0' && car != nullptr)
        {
            m_id = customerId;

            m_name = new char[strlen(name) + 1];

            strcpy(m_name, name);

            m_car = new Car(*car);
        }
        else
        {
            setEmpty();
        }
    }

    void Customer::display() const
    {
        if (!isEmpty())
        {
            cout << left << setw(15) << "Customer ID:" << right << setw(20) << m_id << endl;
            cout << left << setw(15) << "First Name:" << right << setw(20) << m_name << endl;

            m_car->display();
        }
    }

    const Car &Customer::car() const
    {
        return *m_car;
    }
}
