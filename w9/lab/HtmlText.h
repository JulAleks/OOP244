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

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title; // Holds the title of the HTML conversion dynamically.

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
      
        void setEmpty();

        // rule of three goes here
        ~HtmlText();
        HtmlText(const HtmlText&);
        HtmlText& operator=(const HtmlText&);

        // This override will convert the text file to a simple HTML file as follows:
        void write(std::ostream& os) const;
    };
}
#endif // !SDDS_HTMLTEXT_H__
