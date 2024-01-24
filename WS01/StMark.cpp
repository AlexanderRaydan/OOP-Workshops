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

#include <iostream>
#include <iomanip>
#include "StMark.h"
#include "graph.h"
#include "io.h"
#include "file.h"

using namespace std;
using namespace seneca;

namespace seneca
{
    bool printReport(const char *filename)
    {

        // Verify if file exist
        if (!openFile(filename))
        {
            return false;
        }

        // Read file

        struct StMark marks[MAX_NO_RECS];

        int samples[STMARK_LENGTH] = {0};
        int group = 0;

        int numberOfMarks = readMarks(marks);

        sortStudentByMarks(marks, numberOfMarks);
        int mark = 0;

        for (int i = 0; i < numberOfMarks; i++)
        {
            mark = marks[i].mark;
            group = (mark - 1) / 10;
            samples[(STMARK_LENGTH - 1) - group]++;
        }

        // Show graph
        printMarkGraph(samples, STMARK_LENGTH, "Students' mark distribution");
        printStMarks(marks, numberOfMarks);

        // Finish and close file
        closeFile();
        return true;
    }

    void swapStudent(StMark &a, StMark &b)
    {
        StMark temp = a;
        a = b;
        b = temp;
    }

    // sorting StMark array based
    void sortStudentByMarks(StMark stMarks[], int numberOfMarks)
    {
        for (int i = 0; i < numberOfMarks - 1; ++i)
        {
            for (int j = 0; j < numberOfMarks - i - 1; ++j)
            {
                if (stMarks[j].mark < stMarks[j + 1].mark)
                {
                    swapStudent(stMarks[j], stMarks[j + 1]);
                }
            }
        }
    }

    void printStMarks(StMark stMarks[], int numberOfMarks)
    {
        for (int i = 0; i < numberOfMarks; ++i)
        {
            cout << left << setw(3) << i + 1 << ": [" << setw(3) << stMarks[i].mark << "] " << stMarks[i].name << " " << stMarks[i].surname << endl;
        }

        cout << "----------------------------------------" << endl;
    }
}
