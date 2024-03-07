#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace seneca {

    Hero::Hero() {
        setEmpty();
    }

    Hero::Hero(const char *name, Power *power, int num) {
        setup(name, power, num);
    }

    Hero::~Hero() {
        delete[] m_Power;
    }

    Hero::Hero(const Hero &other) {
        setup(other.m_name, other.m_Power, other.m_numOfPowers);
    }

    Hero& Hero::operator=(const Hero &other) {
        if (this != &other) {
            delete[] m_Power;
            setup(other.m_name, other.m_Power, other.m_numOfPowers);
        }
        return *this;
    }

    void Hero::setEmpty() {
        m_Power = nullptr;
        m_name[0] = '\0';
        m_numOfPowers = 0;
        m_powerLevel = 0;
    }

    void Hero::setup(const char *name, Power *power, int num) {
        if (power != nullptr && name && name[0] != '\0' && num > 0) {
            m_Power = new Power[num]; // Allocate power array size
            for (int i = 0; i < num; i++) {
                m_Power[i] = power[i]; // Copy powers
            }

            strcpy(m_name, name); // Copy name
            m_numOfPowers = num; // Set number of powers
            calculatePowerLevel();
        } else {
            setEmpty(); // Set hero to empty state if input is invalid
        }
    }

    void Hero::calculatePowerLevel() {
        int sumRarity = 0;
        for (int i = 0; i < m_numOfPowers; ++i) {
            sumRarity += m_Power[i].checkRarity();
        }
        m_powerLevel = sumRarity * m_numOfPowers;
    }

    std::ostream &Hero::display(std::ostream &os) const {
        std::cout << "Name: " << m_name << std::endl;
        displayDetails(m_Power, m_numOfPowers);
        std::cout << "Power Level: " << m_powerLevel;
        return std::cout;
    }

//    std::ostream &Hero::display(std::ostream &os) const
//    {
//        os << "Name: " << m_name << endl;
//        os << "List of available powers: " << endl;
//        displayDetails(m_Power, m_numOfPowers;
//        os << "Power Level: " << m_powerLevel;
//        return os;
//    }

    Hero &Hero::operator+=(const Power &newPower) {
        Power *temp = new Power[m_numOfPowers + 1];
        for (int i = 0; i < m_numOfPowers; i++) {
            temp[i] = m_Power[i];
        }
        temp[m_numOfPowers] = newPower;
        delete[] m_Power; // Delete old array
        m_Power = temp; // Update to new array

        m_numOfPowers++;
        calculatePowerLevel();

        return *this;
    }

    Hero &Hero::operator-=(int powerLevel) {
        m_powerLevel -= powerLevel;
        return *this;
    }

    bool Hero::operator<(const Hero other) const {
        return m_powerLevel < other.m_powerLevel;
    }

    bool Hero::operator>(const Hero other) const {
        return m_powerLevel > other.m_powerLevel;
    }

    void operator>>(const Power &power, Hero &hero) {
        hero += power;
    }

    void operator<<(Hero &hero, const Power &power) {
        hero += power;
    }

}