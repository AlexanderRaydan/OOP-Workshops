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
#ifndef SENECA_BOOK_H_
#define SENECA_BOOK_H_
#include <iostream>
#include "LibraryItem.h"

namespace seneca
{
    class Book : public LibraryItem
    {
        char *m_author;

    public:
        Book(const char *title, int year, const char *author);
        Book(const Book &from);
        Book &operator=(const Book &from);
        ~Book();
        std::ostream &display(std::ostream &ostr = std::cout) const;
        bool operator>(const Book &other) const;
    };
}
#endif