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
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca
{

   const int MAT_LEN = 10;
   const int MODEL_LEN = 15;

   class GuitarStr
   {
      char m_material[MAT_LEN]{};
      double m_gauge{};

   public:
      const char *material() const;
      double gauge() const;
      GuitarStr();
      GuitarStr(const char *ma, double ga);
   };

   class Guitar
   {
   private:
      GuitarStr *m_strings;
      int m_numStrings;
      char m_model[MODEL_LEN + 1];

      void setEmpty();
      void deallocateMemory();

   public:
      Guitar(const char *mod = "Stratocaster");
      Guitar(GuitarStr strs[], int ns, const char *mod);
      ~Guitar();

      bool changeString(const GuitarStr &gs, int sn);
      void reString(GuitarStr strs[], int ns);
      void deString();

      bool strung() const;
      bool matchGauge(double ga) const;
      std::ostream &display(std::ostream &os = std::cout) const;
   };
}

#endif
