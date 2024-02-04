
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

#include <cstring>
#include "Car.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace seneca
{

    bool Car::isEmpty() const
    {

        bool result =
            strcmp(m_licencePlate, "") == 0 ||
            m_makeModel == nullptr ||
            m_makeModel[0] == '\0' ||
            m_serviceDesc == nullptr ||
            m_serviceDesc[0] == '\0';

        return result;
    }

    void Car::setEmpty()
    {
        strcpy(m_licencePlate, "\0");
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }
    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        delete[] m_serviceDesc;

        setEmpty();
    }
    void Car::set(
        const char plateNo[],
        const char *carMakeModel,
        const char *serviceDesc,
        double serviceCost)
    {

        if (strcmp(plateNo, "") != 0 && carMakeModel != nullptr && carMakeModel[0] != '\0' && serviceDesc != nullptr && serviceDesc[0] != '\0')
        {
            deallocateMemory();

            strcpy(m_licencePlate, plateNo);

            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);

            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);

            m_cost = serviceCost;
        }
        else
        {
            setEmpty();
        }
    }
    void Car::display() const
    {
        if (!isEmpty())
        {
            cout << fixed << setprecision(2);
            cout << left << setw(15) << "License Plate:" << right << setw(20) << m_licencePlate << endl;
            cout << left << setw(15) << "Model:" << right << setw(20) << m_makeModel << endl;
            cout << left << setw(15) << "Service Name:" << right << setw(20) << m_serviceDesc << endl;
            cout << left << setw(15) << "Service Cost:" << right << setw(20) << m_cost << endl;
        }
    }
};
