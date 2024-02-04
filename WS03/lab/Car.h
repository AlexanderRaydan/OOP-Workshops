
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
#ifndef SENECA_CAR_H
#define SENECA_CAR_H
namespace seneca
{

    const int MAX_LENGTH_LICENSE_PLATE = 8;

    class Car
    {

    private:
        char m_licencePlate[MAX_LENGTH_LICENSE_PLATE + 1];
        char *m_makeModel;
        char *m_serviceDesc;
        double m_cost;

    public:
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost);
        void display() const;
    };
}
#endif