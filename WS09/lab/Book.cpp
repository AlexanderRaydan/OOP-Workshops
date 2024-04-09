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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace seneca
{
    Book::Book(const char *title, int year, const char *author) : LibraryItem(title, year), m_author(nullptr)
    {
        if (author != nullptr && author[0] != '\0')
        {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
    }

    Book::Book(const Book &book) : LibraryItem(book)
    {
        if (book.m_author != nullptr)
        {
            m_author = new char[strlen(book.m_author) + 1];
            strcpy(m_author, book.m_author);
        }
        else
        {
            m_author = nullptr;
        }
    }
    Book &Book::operator=(const Book &book)
    {
        if (this == &book)
            return *this;

        LibraryItem::operator=(book);

        delete[] m_author;
        m_author = nullptr;

        if (book.m_author != nullptr)
        {
            m_author = new char[strlen(book.m_author) + 1];
            strcpy(m_author, book.m_author);
        }
        else
        {
            m_author = nullptr;
        }

        return *this;
    }
    Book::~Book()
    {
        delete[] m_author;
        m_author = nullptr;
    }
    std::ostream &Book::display(std::ostream &ostr) const
    {
        LibraryItem::display(ostr);
        ostr << endl;
        ostr << "Author: " << m_author;
        return ostr;
    }

    bool Book::operator>(const Book &book) const
    {
        return (m_author != nullptr && book.m_author != nullptr) && (strcmp(m_author, book.m_author) > 0);
    }

}