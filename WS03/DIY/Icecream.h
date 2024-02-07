/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #3

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
#ifndef ICECREAM_H
#define ICECREAM_H

namespace seneca
{
    class Icecream
    {
    private:
        int flavorChoice;
        int numScoops;
        bool hasVanillaWafer;

    public:
        void getOrder();
        void printOrder() const;

        double calculateTotalPrice() const;
    };
}

#endif