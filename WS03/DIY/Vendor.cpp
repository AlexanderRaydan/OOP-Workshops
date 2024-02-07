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

#include "Vendor.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca
{
    Vendor::Vendor()
    {
        setEmpty();
    }

    Vendor::~Vendor()
    {
        clearData();
    }

    void Vendor::setEmpty()
    {
        orders = nullptr;
        numOrders = 0;
    }

    void Vendor::takeOrders()
    {
        clearData();

        cout << "Seneca Icecream shop" << endl;
        cout << "          @" << endl;
        cout << "        (' .)" << endl;
        cout << "       (*.`. )" << endl;
        cout << "        \\###/" << endl;
        cout << "         \\#/" << endl;
        cout << "          V" << endl;

        cout << "How many Icecreams?" << endl;
        cout << "> ";
        cin >> numOrders;

        if (numOrders <= 0)
        {
            cout << "Invalid number of orders." << endl;
            return;
        }

        orders = new Icecream[numOrders];

        for (int i = 0; i < numOrders; ++i)
        {
            cout << "Order number " << (i + 1) << ":" << endl;
            orders[i].getOrder();
        }
    }

    void Vendor::displayOrders() const
    {
        if (numOrders <= 0)
        {
            cout << "No orders to display." << endl;
            return;
        }

        double totalBeforeTax = 0.0;
        cout << "" << endl;

        cout << "********** Order Summary **********" << endl;

        for (int i = 0; i < numOrders; ++i)
        {
            cout << "Order No: " << (i + 1) << ":" << endl;

            orders[i].printOrder();
            totalBeforeTax += orders[i].calculateTotalPrice();
            if (i < (numOrders - 1))
            {
                cout << "" << endl;
            }
        }

        double tax = 0.13 * totalBeforeTax;
        double totalPriceAfterTax = totalBeforeTax + tax;

        cout << "-----------------------------------" << endl;
        cout << "Price:" << setw(29) << totalBeforeTax << endl;
        cout << "Tax:" << setw(31) << tax << endl;
        cout << "Total Price ($):" << setw(19) << totalPriceAfterTax << endl;
    }

    void Vendor::clearData()
    {
        delete[] orders;
        setEmpty();
    }
}
