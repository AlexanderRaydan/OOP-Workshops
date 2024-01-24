/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #1

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include "StMark.h"
using namespace std;
using namespace seneca;
int main()
{
   bool done = false;
   char filename[256];
   while (!done)
   {
      cout << "Enter filename to generate report for or 'X' to exit:\n> ";
      cin >> filename;
      if ((filename[0] == 'X' || filename[0] == 'x') && filename[1] == 0)
      {
         done = true;
      }
      else if (!printReport(filename))
      {
         cout << "Can not open \"" << filename << "\"!" << endl;
      }
   }
   cout << "Exiting program!" << endl;
   return 0;
}