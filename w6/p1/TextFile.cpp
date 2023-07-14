/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #6 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  July 05, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   //Returns the address held in the m_value attribute.
   Line::operator const char* () const {
      return (const char*)m_value; 
   }

   //Dynamically allocates memory in m_value and copies the Cstring pointed by lineContent into it.
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   //Makes sure all the allocated memory is freed. 
   Line::~Line() {
      delete[] m_value;
   }
   //////*******************TextFile***************************//////
   //***Private


   //If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it. 
   //If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
   void TextFile::setFilename(const char* fname, bool isCopy) {
       delete[] m_filename; 

       if (!isCopy) {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
       }
       else {
           char tempName[100] = "C_";
           strCat(tempName, fname);
           m_filename = new char[strLen(tempName) + 1];
           strCpy(m_filename, tempName);
       }
   }

   //Counts the number of lines in the file:
   void TextFile::setNoOfLines() {
       // Creates a local ifstream object to open the file with the name held in m_filename. 
       ifstream file(m_filename);
       char charachter;

       if (file.is_open()) {
           while (file) {
               //Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
              file.get(charachter);
               if (charachter == '\n')
                   m_noOfLines++;
           }
           file.clear();
           // In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
           m_noOfLines++;
           file.close();
       }
       else {
           // delete the m_filename and set it to nullptr
           delete[] m_filename;
           m_filename = nullptr;
       }

       //If the number of lines is zero, it will delete the m_filenameand set it to nullptr. (Setting the TextFile to a safe empty state)
       if(m_noOfLines==0){
           setEmpty();
       }
   }
   

   //Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
  void TextFile::loadText() {
    if (m_filename != nullptr && m_filename[0] != '\0') {
        // If the m_filename is not null (TextFile is not in a safe empty state), loadText() will dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines
        delete[] m_textLines;
        m_textLines = nullptr;
        m_textLines = new Line[m_noOfLines];
        // Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
        ifstream file(m_filename);

        // Since the length of each line is unknown, read the line using a local C++ string object and the getline helper function. (note: this is the HELPER getline function and not a method of istream).
        if (file.is_open()) {
            string str;
            unsigned i = 0;
            while (getline(file, str, '\n') && i < m_noOfLines) {
                m_textLines[i].m_value = new char[str.length() + 1];
                strCpy(m_textLines[i].m_value, str.c_str());
                i++;
            }
            // After all the lines are read, make sure to update the value of m_noOfLines to the actual number of lines read (This covers the possibility of one extra empty line at the end of the file)
            m_noOfLines = i;
            file.close();
        }
    }
    else {
        ; // If the m_filename is null, this function does nothing.
    }
}




   //Saves the content of the TextFile under a new name.
   //Use a local ofstream object to open a new file using the name kept in the argument filename.Then loop through the elements of the m_textLines arrayand write them in the opened file adding a new line to the end of each line.
   void TextFile::saveAs(const char* fileName) const {
       ofstream newFile(fileName);

       if (!newFile.is_open()) {
           cout << "File is not open" << endl;
       }
       else {
           unsigned i;
           for (i=0; i < m_noOfLines; i++) {
               newFile << m_textLines[i] << endl;
           }
       }
       newFile.close();
   }

   //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring and sets is to nullptr sets m_noOfLines attribute to zero.
   void TextFile::setEmpty() {
      
      m_filename = nullptr;
      m_textLines = nullptr;
       m_noOfLines = 0;
   }

   //****Public*****

   //Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
   TextFile::TextFile(unsigned pageSize) {
       setEmpty();
       m_pageSize = pageSize;
   }


   //Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. 
   //Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;

       if (filename != nullptr && filename[0] != '\0') {
           delete[] m_filename;
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);

           setNoOfLines();
           loadText();
       }
   }


   //Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero
   TextFile::TextFile(const TextFile& rhs) {
       setEmpty();
       m_pageSize = rhs.m_pageSize;

       // If the incoming Text object is in a valid state, performs the following tasks to copy the textfile and the content safely:
       if (this != &rhs) {
           if (rhs.m_filename != nullptr && rhs.m_filename[0] != '\0') {
               setFilename(rhs.m_filename, true);
               m_noOfLines = rhs.m_noOfLines;

               m_textLines = new Line[m_noOfLines];
               for (unsigned i = 0; i < m_noOfLines; i++) {
                   m_textLines[i].m_value = new char[strLen(rhs.m_textLines[i].m_value) + 1];
                   strCpy(m_textLines[i].m_value, rhs.m_textLines[i].m_value);
               }

               saveAs(m_filename);
               loadText();
           }
       }
   }


   //If the current and the incoming TextFiles are valid it will first delete the current text and then overwrites the current file and data by the content of the incoming TextFile.
   TextFile& TextFile::operator=(const TextFile& rhs) {
       if (this != &rhs) {
     // deallocate the dynamic array of Text and sets the pointer to nul
           delete[] m_textLines;
           m_textLines = nullptr;
           //Sets the number of lines
           m_noOfLines = rhs.m_noOfLines;

           if (rhs.m_textLines && rhs.m_noOfLines > 0) {
               m_textLines = new Line[m_noOfLines];

               for (unsigned i = 0; i < m_noOfLines; i++) {
                   m_textLines[i].m_value = new char[strLen(rhs.m_textLines[i].m_value) + 1];
                   strCpy(m_textLines[i].m_value, rhs.m_textLines[i].m_value);
               }
               //Saves the content of the incoming TextFile under the current filename
               saveAs(m_filename);
               //loads the Text
               loadText();
           }
       }
       return *this;
   }
  

   //Deletes all the dynamic data.
   TextFile::~TextFile() {
       delete[] m_textLines;
       delete[] m_filename;
   }

   //Prints the filename and then the content of the file "m_pageSize" lines at a time.
   ostream& TextFile::view(ostream& ostr)const {
       if (m_filename != nullptr && m_filename[0] != '\0') {
           //print the file name
           ostr << m_filename << endl;
           //underline the file name with '=' characte
           int size = strLen(m_filename);
           for (int i=0; i < size; i++) {
               ostr << "=";
           }
           //loops through the lines and print them one by line
           ostr << endl;
           unsigned line;
           unsigned display = 0;

           for (line = 0; line < m_noOfLines; line++) {
               ostr << m_textLines[line].m_value << endl;
               display++;
               // Pause after displaying m_pageSize lines
               if (display == m_pageSize) {
                   ostr << "Hit ENTER to continue...";
                   char enter;
                   cin.get(enter);
                   display = 0;
               }
           }
       }
       return ostr;
   }

 
   //Receives a filename from istr to set the file name of the TextFile.  
   istream& TextFile::getFile(istream& istr) {
       string fileName;
       istr >> fileName;
       
       // Set the file name of the TextFile
       delete[] m_filename;
       setFilename(fileName.c_str(), false);

       // Set the number of lines and load the Text
     
       setNoOfLines();
       loadText();
       istr.ignore();//clears the buffer

       return istr;
   }

   //Returns true if the TextFile is not in an empty state and returns false if it is.
   TextFile::operator bool()const {
       return m_filename != nullptr ? true : false;
   }

   //returns m_noOfLines;
   unsigned TextFile::lines()const {
       return m_noOfLines;
    }

   //Returns the filename.
   const char* TextFile::name()const {
       return m_filename;
    }

   //Returns the element in the m_textLine array corresponding to the index argument. 
   //If the TextFile is in an empty state, it will return null. If the index exceeds the size of the array it should loop back to the beginning.
   const char* TextFile::operator[](unsigned index) const {
       if (m_filename != nullptr && m_filename[0] != '\0' && m_noOfLines > 0) {
           if (index >= m_noOfLines) {
               index -= m_noOfLines; 
           }
           return m_textLines[index].m_value;
       }
       return nullptr; 
   }

   //uses the view() method to print the TextFile
   ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       text.view(ostr);
       return ostr;
    }

   //uses the getFile() method to get the file name from console and load the content from the file
   istream& operator>>(std::istream& istr, TextFile& text) {
       text.getFile(istr);
       return istr;
    }

}