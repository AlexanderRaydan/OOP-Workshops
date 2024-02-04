
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

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"
namespace seneca
{

    class Customer
    {

    private:
        int m_id;
        char *m_name;
        Car *m_car;

    public:
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(int customerId, const char *name, const Car *car);
        void display() const;
        const Car &car() const;
    };
}
#endif