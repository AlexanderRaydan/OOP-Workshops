/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #5 p2

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////
*/
#pragma once
#ifndef SENECA_HERO_H_
#define SENECA_HERO_H_
#include "Power.h"

namespace seneca
{
    class Hero
    {

    private:
        char m_name[MAX_NAME_LENGTH + 1];
        Power *m_powers;
        int m_powersNumbers;
        int m_powerLevel;

        void setEmpty();
        void deallocate();

    public:
        Hero();
        Hero(const char *name, Power *powers, int powersNumber);
        ~Hero();
        std::ostream &display(std::ostream &os = std::cout) const;

        void updatePowerLevel();

        void operator+=(const Power &power);
        void operator-=(const int number);

        bool operator<(const Hero &right) const;
        bool operator>(const Hero &right) const;

        void operator<<(const Power &right);
    };

    void operator>>(const Power &left, Hero &right);
}

#endif