/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #1

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZRA

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.///////////////////////////////////////////////////////////////////////////
*/

#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca
{

   const int STMARK_LENGTH = 10;

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark
   {
      char name[21];
      char surname[31];
      int mark;
   };

   bool printReport(const char *filename);

   void printStMarks(StMark stMarks[], int numberOfMarks);

   void swapStudent(StMark &a, StMark &b);

   void sortStudentByMarks(StMark stMarks[], int numberOfMarks);
}
#endif // !SENECA_STMARK_H
