/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #2

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
#include "Guest.h"
#include <cstring>

using namespace std;

namespace seneca
{

    // sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
    void set(Guest &guest, const char *first, const char *last, int age)
    {
        if (first && last && first[0] && last[0])
        {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);
        }
        else
        {
            guest.m_firstName = nullptr;
            guest.m_lastName = nullptr;
        }
        guest.m_adult = age >= 18;
    }

    // Prints the guest name:
    // "Name Surname(child)"
    // The child flag is printed if the guest is not an adult
    // and if the names are not set, "Vacated!" is printed.
    void print(const Guest &guest)
    {

        if (guest.m_firstName && guest.m_lastName && strcmp(guest.m_firstName, " ") && strcmp(guest.m_lastName, " "))
        {
            cout << guest.m_firstName << " " << guest.m_lastName;

            if (!guest.m_adult)
            {
                cout << "(Child)";
            }

            cout << endl;
        }
        else
        {
            cout << "Vacated!" << endl;
        }
    }

    // books the guest information from the console:
    // Name: Jake<ENTER>
    // Lastname: Doe<ENTER>
    // Age: 10<ENTER>
    void book(Guest &guest)
    {

        char firstName[MAX_NAME_LENGTH + 1];
        cout << "Name: ";
        cin >> firstName;

        char lastName[MAX_NAME_LENGTH + 1];
        cout << "Lastname: ";
        cin >> lastName;

        int age = 0;
        cout << "Age: ";
        cin >> age;

        cin.ignore();

        set(guest, firstName, lastName, age);
    }

    // vacates the guest by dallocating its memory.
    void vacate(Guest &guest)
    {
        delete[] guest.m_firstName;
        delete[] guest.m_lastName;

        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
    }
}