
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

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H
namespace seneca
{

    const int MAX_NAME_LENGTH = 60;

    struct Guest
    {
        char *m_firstName;
        char *m_lastName;
        bool m_adult;
    };

    void set(Guest &guest, const char *first, const char *last, int age);

    void print(const Guest &guest);

    void book(Guest &guest);

    void vacate(Guest &guest);
}
#endif