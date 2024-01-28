
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
#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H
#include "Guest.h"

namespace seneca
{
    struct Room
    {
        char m_roomNumber[6];
        int m_noOfGuests;
        Guest *m_guests;
    };

    void set(Room &room, int numberOfGuests, const char *roomNumber);

    void print(const Room &room);

    void book(Room &room);

    void vacate(Room &room);
}
#endif