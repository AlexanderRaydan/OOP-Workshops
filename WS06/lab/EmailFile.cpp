/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #5 p1

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

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email &Email::operator=(const Email &rhs)
    {

        if (this != &rhs && rhs.m_email && rhs.m_name)
        {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream &in)
    {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ','))
        {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ','))
            {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n'))
                {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

    Email::~Email()
    {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char *filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails()
    {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open())
        {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file)
            {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else
            {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    std::ostream &EmailFile::view(std::ostream &ostr) const
    {
        if (m_filename)
        {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++)
            {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const EmailFile &text)
    {
        return text.view(ostr);
    }

    EmailFile::EmailFile()
    {
        setEmpty();
    }

    EmailFile::EmailFile(const char *filename)
    {
        if (filename == nullptr)
        {
            setEmpty();
            return;
        }

        setFilename(filename);

        if (setNoOfEmails())
        {
            loadEmails();
            m_noOfEmails--; // remove last empty line
        }
    }

    EmailFile::~EmailFile()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        setEmpty();
    }

    EmailFile &EmailFile::operator=(const EmailFile &other)
    {
        m_noOfEmails = other.m_noOfEmails;

        m_filename = new char[strlen(other.m_filename) + 1];
        strcpy(m_filename, other.m_filename);

        m_emailLines = new Email[m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; ++i)
        {
            m_emailLines[i] = other.m_emailLines[i];
        }

        return *this;
    }

    void EmailFile::loadEmails()
    {

        ifstream file(m_filename);

        if (!file.is_open())
        {
            cout << "Failed to open file: " << m_filename << endl;
            return;
        }

        delete[] m_emailLines;
        m_emailLines = new Email[m_noOfEmails];

        Email email;

        for (int i = 0; i < m_noOfEmails && email.load(file); i++)
        {
            m_emailLines[i] = email;
        }

        file.close();
    }

    bool EmailFile::saveToFile(const char *filename) const
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Failed to open file: " << m_filename << endl;
            return false;
        }

        for (int i = 0; i < m_noOfEmails; ++i)
        {
            // Write
            file << m_emailLines[i].m_email << ","
                 << m_emailLines[i].m_name << ","
                 << m_emailLines[i].m_year << endl;
        }

        file.close();
        return true;
    }

    void EmailFile::fileCat(const EmailFile &obj, const char *name)
    {
        if (m_noOfEmails <= 0 || obj.m_noOfEmails <= 0)
            return;

        int totalEmails = m_noOfEmails + obj.m_noOfEmails;

        Email *combinedEmails = new Email[totalEmails];

        int index = 0;
        for (int i = 0; i < m_noOfEmails; ++i)
        {
            combinedEmails[index++] = m_emailLines[i];
        }
        for (int i = 0; i < obj.m_noOfEmails; ++i)
        {
            combinedEmails[index++] = obj.m_emailLines[i];
        }

        delete[] m_emailLines;
        m_emailLines = nullptr;
        m_noOfEmails = 0;

        m_emailLines = combinedEmails;
        m_noOfEmails = totalEmails;

        if (name != nullptr)
        {
            delete[] m_filename;
            m_filename = new char[strlen(name) + 1];
            strcpy(m_filename, name);
        }

        saveToFile(m_filename);
    }
}