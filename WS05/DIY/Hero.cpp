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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

using namespace std;

namespace seneca
{

    Hero::Hero()
    {
        setEmpty();
    }

    Hero::~Hero()
    {
        deallocate();
    }

    Hero::Hero(const char *name, Power *powers, int powersNumber)
    {
        if (!(name && name[0] != '\0' && powers))
        {
            setEmpty();
            return;
        }

        strncpy(m_name, name, MAX_NAME_LENGTH);

        m_powers = new Power[powersNumber];
        for (int i = 0; i < powersNumber; ++i)
        {
            m_powers[i] = powers[i];
        }

        m_powers = powers;

        m_powersNumbers = powersNumber;
        updatePowerLevel();
    }

    void Hero::deallocate()
    {

        delete[] m_powers;
        setEmpty();
    }

    void Hero::setEmpty()
    {
        m_name[0] = '\0';
        m_powers = nullptr;
        m_powersNumbers = 0;
        m_powerLevel = 0;
    }

    std::ostream &Hero::display(std::ostream &os) const
    {
        os << "Name: " << m_name << endl;
        os << "List of available powers: " << endl;
        displayDetails(m_powers, m_powersNumbers);
        os << "Power Level: " << m_powerLevel;
        return os;
    }

    void Hero::updatePowerLevel()
    {
        int sumRarity = 0;
        for (int i = 0; i < m_powersNumbers; i++)
        {
            sumRarity += m_powers[i].checkRarity();
        }
        m_powerLevel = sumRarity * m_powersNumbers;
    }

    void Hero::operator+=(const Power &power)
    {
        Power *temp = new Power[m_powersNumbers + 1];

        for (int i = 0; i < m_powersNumbers; i++)
        {
            temp[i] = m_powers[i];
        }

        temp[m_powersNumbers] = power;

        if (m_powers != nullptr)
        {
            delete[] m_powers;
            m_powers = nullptr;
        }

        m_powers = temp;

        m_powerLevel++;
        m_powersNumbers++;
        updatePowerLevel();
    }

    void Hero::operator-=(const int number)
    {
        m_powerLevel -= number;
    }

    bool Hero::operator<(const Hero &right) const
    {
        return this->m_powerLevel < right.m_powerLevel;
    }

    bool Hero::operator>(const Hero &right) const
    {
        return this->m_powerLevel > right.m_powerLevel;
    }

    void Hero::operator<<(const Power &right)
    {
        *this += right;
    }

    void operator>>(const Power &left, Hero &right)
    {
        right += left;
    }
}