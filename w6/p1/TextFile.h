/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #6 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  July 05, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
   class Line {
      char* m_value{ nullptr }; //holds the address of the dynamically allocated Cstring (to hold a line of the text file)
      operator const char* ()const; 
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
      // copy and copy assignment prevention goes here
      Line& operator=(const Line& src) = delete;
      Line(const Line& src) = delete;
   };

   class TextFile {
      Line* m_textLines; // pointer to hold the dynamic array of Lines. This attribute should be initialized to nullptr
      char* m_filename; //A pointer to hold the dynamic Cstring holding the name of the file. This attribute should be initialized to nullptr
      unsigned m_noOfLines; //An unsigned integer to be set to the number of lines in the file.
      unsigned m_pageSize; //the page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, the user must hit enter for the next page to appear. 
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);
      TextFile& operator=(const TextFile&);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
