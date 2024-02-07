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

#include "Icecream.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

namespace seneca
{

    void Icecream::getOrder()
    {
        cout << "Select flavour:" << endl;
        cout << "----------------" << endl;
        cout << "1: Chocolate" << endl;
        cout << "2: Strawberry" << endl;
        cout << "3: Mango" << endl;
        cout << "4: Tutti fruit" << endl;
        cout << "5: Almond crunch" << endl;
        cout << "----------------" << endl;

        bool flag = false;

        do
        {
            flag = false;
            cout << "> ";
            cin >> flavorChoice;

            if (cin.fail())
            {
                flag = true;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }
            else if (flavorChoice < 1 || flavorChoice > 5)
            {
                flag = true;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invlid value(1<=val<=5)" << endl;
            }

        } while (flag);

        cout << "Number of Scoops (max 3)" << endl;

        do
        {
            cout << "> ";
            cin >> numScoops;
            flag = false;

            if (cin.fail())
            {
                flag = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry, retry" << endl;
            }
            else if (numScoops < 1 || numScoops > 3)
            {
                flag = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invlid value(1<=val<=3)" << endl;
            }

        } while (flag);

        string vanillaWaferChoice;

        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o > ";
        do
        {
            flag = false;
            cin >> vanillaWaferChoice;

            if (!(vanillaWaferChoice.length() == 1 && (toupper(vanillaWaferChoice[0]) == 'Y' || toupper(vanillaWaferChoice[0]) == 'N')))
            {
                flag = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Only Y or N are acceptable:" << endl;
                cout << "> ";
            }
        } while (flag);

        hasVanillaWafer = (toupper(vanillaWaferChoice[0]) == 'Y');
    }

    void Icecream::printOrder() const
    {
        cout << "Order details:                Price" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Number of scoops, " << numScoops << " total:" << setw(9) << fixed << setprecision(2) << numScoops * 5.00 << endl;

        switch (flavorChoice)
        {
        case 1:
            cout << "Chocolate flavour:" << setw(17) << fixed << setprecision(2) << numScoops * 1.00 << endl;
            break;
        case 2:
            cout << "Strawberry flavour" << endl;
            break;
        case 3:
            cout << "Mango flavour" << endl;
            break;
        case 4:
            cout << "Tutti fruit flavour" << endl;
            break;
        case 5:
            cout << "Almond crunch flavour" << endl;
            break;
        }

        cout << "Vanilla Wafer:" << setw(21) << fixed << setprecision(2) << (hasVanillaWafer ? 5.00 : 0.00) << endl;
        cout << "Price:" << setw(29) << fixed << setprecision(2) << calculateTotalPrice() << endl;
    }

    double Icecream::calculateTotalPrice() const
    {
        double price = numScoops * 5.00;

        if (flavorChoice == 1)
        { // Chocolate flavor
            price += numScoops * 1.00;
        }

        if (hasVanillaWafer)
        {
            price += 5.00;
        }

        return price;
    }

}
