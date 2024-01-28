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
#include <cstring>
#include "Assessment.h"

using namespace std;

namespace seneca
{

    // Read integer
    bool read(int &value, FILE *fptr)
    {
        return fscanf(fptr, "%d", &value) == 1;
    }

    // Read double
    bool read(double &value, FILE *fptr)
    {
        return fscanf(fptr, "%lf", &value) == 1;
    }

    // Read string after ","
    bool read(char *cstr, FILE *fptr)
    {
        if (fscanf(fptr, ",%60[^\n]\n", cstr) == 1)
        {
            return true;
        }

        return false;
    }

    // read Assessment
    bool read(Assessment &assess, FILE *fptr)
    {
        double mark;
        char title[ASSESSMENT_TITLE_WIDTH + 1];

        if (read(mark, fptr) && read(title, fptr))
        {
            assess.m_mark = new double;
            *assess.m_mark = mark;

            assess.m_title = new char[strlen(title) + 1];
            strcpy(assess.m_title, title);

            return true;
        }

        return false;
    }

    void freeMem(Assessment *&aptr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }

        delete[] aptr;
        aptr = nullptr;
    }

    int read(Assessment *&aptr, FILE *fptr)
    {
        int numberOfElements;
        // Check number of element value
        if (read(numberOfElements, fptr) != 1)
        {
            return 0;
        }

        aptr = new Assessment[numberOfElements];

        int numOfReads = 0;

        while (read(aptr[numOfReads], fptr))
        {
            numOfReads++;
        }

        if (numOfReads != numberOfElements)
        {
            freeMem(aptr, numOfReads);
            return 0;
        }

        return numberOfElements;
    }
}