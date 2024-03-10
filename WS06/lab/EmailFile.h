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
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca
{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char *m_email{nullptr};
		char *m_name{nullptr};
		char m_year[5]{'\0'};
		Email(){};
		Email(const Email &) = delete; // Prohibit the copy constructor for this class:
		Email &operator=(const Email &);
		bool load(std::ifstream &in);
		~Email();

		// Make the EmailFile class a "friend" of the Email class
		friend class EmailFile;
	};

	class EmailFile
	{
		Email *m_emailLines{nullptr};
		char *m_filename{};
		int m_noOfEmails{0};
		void setFilename(const char *filename);
		void setEmpty();
		bool setNoOfEmails();
		void loadEmails();

	public:
		std::ostream &view(std::ostream &ostr) const;

		EmailFile();
		EmailFile(const char *filename);

		~EmailFile();

		EmailFile &operator=(const EmailFile &);

		bool saveToFile(const char *filename) const;
		void fileCat(const EmailFile &obj, const char *name = nullptr);
	};

	std::ostream &operator<<(std::ostream &ostr, const EmailFile &text);

}
#endif // !SENECA_EMAILFILE_H
