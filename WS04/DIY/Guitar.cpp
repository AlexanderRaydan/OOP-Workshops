/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #4 p2

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
#include "Guitar.h"
#include <iomanip>
using namespace std;

namespace seneca
{
   const char *GuitarStr::material() const
   {
      return m_material;
   }
   double GuitarStr::gauge() const
   {
      return m_gauge;
   }
   GuitarStr::GuitarStr(){};

   GuitarStr::GuitarStr(const char *ma, double ga)
   {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   void Guitar::setEmpty()
   {
      m_numStrings = 0;
      m_model[MODEL_LEN] = '\0';
      m_strings = nullptr;
   }

   void Guitar::deallocateMemory()
   {
      delete[] m_strings;
      setEmpty();
   }

   // Constructors/Destructor
   Guitar::Guitar(const char *mod)
   {
      setEmpty();
      strncpy(m_model, mod, MODEL_LEN);
   }

   Guitar::Guitar(GuitarStr strs[], int ns, const char *mod) : m_numStrings(ns)
   {
      strncpy(m_model, mod, MODEL_LEN);
      m_strings = new GuitarStr[ns];
      for (int i = 0; i < ns; ++i)
      {
         m_strings[i] = strs[i];
      }
   }

   Guitar::~Guitar()
   {
      deallocateMemory();
   }

   bool Guitar::changeString(const GuitarStr &gs, int sn)
   {
      if (sn < 0 || sn >= m_numStrings)
      {
         return false;
      }
      m_strings[sn] = gs;
      return true;
   }

   void Guitar::reString(GuitarStr strs[], int ns)
   {
      deallocateMemory();
      m_numStrings = ns;
      m_strings = new GuitarStr[ns];
      for (int i = 0; i < ns; ++i)
      {
         m_strings[i] = strs[i];
      }
   }

   void Guitar::deString()
   {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
   }

   // Queries
   bool Guitar::strung() const
   {
      return m_numStrings > 0;
   }

   bool Guitar::matchGauge(double ga) const
   {
      for (int i = 0; i < m_numStrings; ++i)
      {
         if (m_strings[i].gauge() == ga)
         {
            return true;
         }
      }
      return false;
   }

   std::ostream &Guitar::display(std::ostream &os) const
   {
      if (!strung())
      {
         os << "***Empty Guitar***" << endl;
         return os;
      }

      os << "Guitar Model: " << m_model << endl;
      os << "Strings: " << m_numStrings << endl;
      for (int i = 0; i < m_numStrings; ++i)
      {
         os << "#" << (i + 1) << setw(MAT_LEN) << m_strings[i].material() << " | "
            << fixed << setprecision(1) << m_strings[i].gauge() << endl;
      }
      return os;
   }
}
