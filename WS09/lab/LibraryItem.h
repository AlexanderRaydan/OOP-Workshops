/******************************************************************************
                        Workshop - #9
Author   Alexander Raydan

Revision History
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_LIBRARY_ITEM_H_
#define SENECA_LIBRARY_ITEM_H_
#include <iostream>

namespace seneca
{
    class LibraryItem
    {
        char *m_title;
        int m_year;

    public:
        LibraryItem();
        LibraryItem(const char *title, int year);
        LibraryItem(const LibraryItem &from);
        LibraryItem &operator=(const LibraryItem &from);
        virtual ~LibraryItem();
        virtual std::ostream &display(std::ostream &ostr = std::cout) const;
    };
}
#endif