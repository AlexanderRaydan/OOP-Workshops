
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
#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H
namespace seneca
{
    const int ASSESSMENT_TITLE_WIDTH = 60;

    struct Assessment
    {
        double *m_mark;
        char *m_title;
    };

    bool read(int &value, FILE *fptr);

    bool read(double &value, FILE *fptr);

    bool read(char *cstr, FILE *fptr);

    bool read(Assessment &assess, FILE *fptr);

    void freeMem(Assessment *&aptr, int size);

    int read(Assessment *&aptr, FILE *fptr);
}
#endif