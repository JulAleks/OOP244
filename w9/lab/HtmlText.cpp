/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 9 - LAB
 HtmlText Module
 File	 HtmlText.cpp
 Version 1.0
 Date 2023-07-24
 Author	Julia Alekseev
 Student ID 051292134
 Description:

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#include <iostream>
#include "cstring.h"
#include "HtmlText.h"

using namespace std;
namespace sdds {
	//constructor
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		if (title && title[0] != '\0') {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
	}

	//set empty
	void HtmlText::setEmpty()
	{
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		
	}
	//The rule of three
	  //destrcutor
	HtmlText::~HtmlText()
	{
		setEmpty();
	}
	//copy constructor
	HtmlText::HtmlText(const HtmlText& rhs):Text(rhs), m_title(nullptr)
	{
		if (rhs.m_title != nullptr && rhs.m_title[0] != '\0') {
			Text::operator=(rhs);
			if (rhs.m_title != nullptr && rhs.m_title[0] != '\0') {
				m_title = new char[strLen(rhs.m_title) + 1];
				strCpy(m_title, rhs.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
	}
	//equal assignment
	HtmlText& HtmlText::operator=(const HtmlText&rhs)
	{
		if (this != &rhs) {	
			Text::operator=(rhs);
			if (rhs.m_title != nullptr && rhs.m_title[0] != '\0') {
				if (m_title) {
					setEmpty();
				}
				m_title = new char[strLen(rhs.m_title) + 1];
				strCpy(m_title, rhs.m_title);
			}
			else {
					HtmlText::setEmpty();
			}
		}
		return *this;
	}

	//This override will convert the text file to a simple HTML file
	void HtmlText::write(std::ostream& os) const
	{
		//create a boolean variable and set it to false to keep track of the occurance of multiple spaces (let's call it MS for Multiple Spaces)
		bool MS = false; 

		//insert 
		os << "<html><head><title>";

		//if m_title is not null, insert the title, otherwise insert "No Title"
		(m_title) ? os << m_title : os << "No Title";

		//insert

		os << "</title></head>\n<body>\n";

		//if "\n\n" is not null insert "<h1>" << m_title << "</h1>\n"
		if ("\n\n") {
			os << "<h1>" << m_title << "</h1>\n";
		}

		if (m_title) {
			//loop through all the elements of the m_content (using the protected index operator) and convert the characters 
			int i = 0;
			while (Text::operator[](i) != '\0') {
				char m_char = Text::operator[](i);

				switch (m_char) {
				case (' '):
					if (MS) {
						os << "&nbsp;";
					}
					else {
						MS = true;
						os << " ";
					}
					break;
				case ('<'):
					os << "&lt;";
					MS = false;
					break;
				case ('>'):
					os << "&gt;";
					MS = false;
					break;
				case ('\n'):
					os << "<br />\n";
					MS = false;
					break;
				default:
					MS = false;
					os << m_char;
				}
				i++;
			}
		}

		//at the end insert "</body>\n</html>" to end the html page.
		os << "</body>\n</html>";
	}
}