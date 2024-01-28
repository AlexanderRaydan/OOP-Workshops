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
#include "Room.h"
#include "Guest.h"
#include <cstring>

using namespace std;

namespace seneca
{

    // sets the Room by allocating a dynamic array of guests and setting the room number
    // (no validation is done for room number)
    void set(Room &room, int numberOfGuests, const char *roomNumber)
    {
        strcpy(room.m_roomNumber, roomNumber);
        room.m_noOfGuests = numberOfGuests;
        room.m_guests = new Guest[numberOfGuests];

        for (int i = 0; i < numberOfGuests; i++)
        {
            set(room.m_guests[i], nullptr, nullptr, 0);
        }
    }

    // Prints the room number and names of the guests in the following lines with four
    // spaces of indentaion
    // See correct_output.txt for the exact format
    void print(const Room &room)
    {

        if (room.m_noOfGuests > 0)
        {
            cout << "Room Number: " << room.m_roomNumber << endl;

            for (int i = 0; i < room.m_noOfGuests; i++)
            {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
        else
        {
            cout << "Empty Room!" << endl;
        }
    }

    // Books a room by receiving the room number, number of guests and the guest information.
    // See correct_output.txt for the exact format
    void book(Room &room)
    {

        if (room.m_noOfGuests > 0)
        {
            cout << "Vacated!" << endl;
        }

        char roomNumber[6];

        cout << "Room number: ";
        cin >> roomNumber;

        int numberOfGuests = 0;
        cout << "Number of guests: ";
        cin >> numberOfGuests;

        set(room, numberOfGuests, roomNumber);

        for (int i = 0; i < numberOfGuests; i++)
        {
            cout << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
    }

    // vacates the room by dallocating all the memory used.
    void vacate(Room &room)
    {
        for (int i = 0; i < room.m_noOfGuests; i++)
        {
            vacate(room.m_guests[i]);
        }
        delete[] room.m_guests;

        room.m_guests = nullptr;
        room.m_noOfGuests = 0;
    }
}