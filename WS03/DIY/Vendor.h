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

#ifndef VENDOR_H
#define VENDOR_H

#include "Icecream.h"

namespace seneca
{
    class Vendor
    {
    private:
        Icecream *orders;
        int numOrders;

    public:
        Vendor();
        ~Vendor();

        void setEmpty();
        void takeOrders();
        void displayOrders() const;
        void clearData();
    };
}

#endif
