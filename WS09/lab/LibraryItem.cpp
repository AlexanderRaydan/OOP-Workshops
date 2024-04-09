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

#include "LibraryItem.h"

using namespace std;
namespace seneca
{
    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char *title, int year)
    {
        if (title != nullptr && title[0] != '\0' && year > 0)
        {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            m_year = year;
        }
        else
        {
            m_title = nullptr;
            m_year = 0;
        }
    }

    LibraryItem::LibraryItem(const LibraryItem &libraryItem)
    {
        if (libraryItem.m_title != nullptr)
        {
            m_title = new char[strlen(libraryItem.m_title) + 1];
            strcpy(m_title, libraryItem.m_title);
            m_year = libraryItem.m_year;
        }
        else
        {
            m_year = 0;
            m_title = nullptr;
        }
    }
    LibraryItem &LibraryItem::operator=(const LibraryItem &libraryItem)
    {

        if (this == &libraryItem)
            return *this;

        delete[] m_title;
        m_title = nullptr;

        if (libraryItem.m_title != nullptr)
        {
            m_title = new char[strlen(libraryItem.m_title) + 1];
            strcpy(m_title, libraryItem.m_title);
            m_year = libraryItem.m_year;
        }
        else
        {
            m_year = 0;
            m_title = nullptr;
        }

        return *this;
    }
    LibraryItem::~LibraryItem()
    {
        delete[] m_title;
        m_title = nullptr;
    }
    std::ostream &LibraryItem::display(std::ostream &ostr) const
    {
        ostr << "Title: " << m_title << " (" << m_year << ")";
        return ostr;
    }
}