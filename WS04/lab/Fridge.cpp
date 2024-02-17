/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca
{

   // ***************************** Fridge *****************************

   void Fridge::setEmpty()
   {
      m_numFoods = 0;
      m_model = nullptr;

      for (int i = 0; i < FRIDGE_CAP; i++)
      {
         m_foods[i] = Food();
      }
   }

   void Fridge::deallocateMemory()
   {
      delete[] m_model;
      setEmpty();
   }

   Fridge::Fridge()
   {
      setEmpty();
   }

   Fridge::~Fridge()
   {
      deallocateMemory();
   }

   Fridge::Fridge(Food farr[], int nf, const char *mod)
   {
      setEmpty();

      if (nf > 0 && mod != nullptr && *mod != '\0')
      {
         m_numFoods = (nf < FRIDGE_CAP) ? nf : FRIDGE_CAP;
         m_model = new char[strlen(mod) + 1];
         strcpy(m_model, mod);

         for (int i = 0; i < m_numFoods; ++i)
         {
            m_foods[i] = farr[i];
         }
      }
   }

   bool Fridge::addFood(const Food &f)
   {
      if (m_numFoods < FRIDGE_CAP)
      {
         m_foods[m_numFoods] = f;
         m_numFoods++;
         return true;
      }
      return false;
   }

   void Fridge::changeModel(const char *m)
   {
      if (m != nullptr && *m != '\0')
      {
         delete[] m_model;
         m_model = new char[std::strlen(m) + 1];
         strcpy(m_model, m);
      }
   }

   bool Fridge::fullFridge() const
   {
      return m_numFoods == FRIDGE_CAP;
   }

   bool Fridge::findFood(const char *f) const
   {
      for (int i = 0; i < m_numFoods; ++i)
      {
         if (strcmp(m_foods[i].name(), f) == 0)
         {
            return true;
         }
      }
      return false;
   }

   std::ostream &Fridge::display(std::ostream &os) const
   {
      {
         if (m_model == nullptr || *m_model == '\0')
         {
            return os;
         }

         os << "Fridge Model: " << m_model << endl;
         os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;
         os << "List of Foods" << endl;
         for (int i = 0; i < m_numFoods; ++i)
         {
            os.width(NAME_LEN);
            os << m_foods[i].name() << " | " << m_foods[i].weight() << endl;
         }
         return os;
      }

      // Overloaded insertion operator to support ostream
   }

   // ostream &operator<<(ostream &os, const Fridge &fridge)
   // {
   //    return fridge.display(os);
   // }

   // ***************************** Food *****************************

   const char *Food::name() const
   {
      return m_name;
   }
   int Food::weight() const
   {
      return m_weight;
   }
   Food::Food() {}

   Food::Food(const char *nm, int wei)
   {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }
}
