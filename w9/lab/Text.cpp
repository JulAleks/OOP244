/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 9 - LAB
 Text Module
 File	Text.cpp
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
#include <fstream>
#include "cstring.h"
#include "Text.h"

using namespace std;

namespace sdds {

    //Code provided (int Text.cpp) ; it returns the length (size) of the text file on the disk. It returns zero if either the file does not exist or the content is empty.
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
   /*This index operator provides read-only access to the content of the text for the derived classes of Text.
    The behaviour of the operator is not defined if the index goes out of bounds.*/
   const char& Text::operator[](int index) const
   {
       int num = 0;
       (index >= 0 || index < getFileLength()) ? num = index : num = getFileLength(); //since only one rturn can be for a function setting the if else tvalue to num
       return m_content[num]; //returning index of the value assigned to num
   }

   //default constructor 
   Text::Text(const char* filename)
   {
       if (m_filename) { //if current name exist, delete and set yo nullptr
           delete[] m_filename;
           m_filename = nullptr;
       }
       if (filename && filename[0] != '\0') {
           m_filename = new char[strLen(filename) + 1]; //dynemically allocating size for new name
           strCpy(m_filename, filename); //coping new name
           read(); //reding file content 
       }
     
   }

   //sets the attributes to a safe state
   void Text::setEmpty()
   {
       if (m_filename) {
           delete[] m_filename;
       }
       if (m_content) {
           delete[] m_content;
       }
       m_filename = nullptr;
       m_content = nullptr;
   }

   //sets file name
   void Text::setName(const char* name)
   {
       if (m_filename) {
           delete[] m_filename;
           m_filename = nullptr;
       }
       m_filename = new char[strLen(name) + 1];
       strCpy(m_filename, name);
      
   }


   //The rule of three, Implement the rule of three so memory is managed properly in case of copyingand assignment.
  
  //destrcutor
   Text::~Text()
   {
       setEmpty();
   }

   //copy constructor
   Text::Text(const Text& rhs)
   {
       if (this != &rhs) {
           setEmpty();
           setName(rhs.m_filename);
           read();
       }
       else {
           setEmpty();
       }
   }


   //equal assignment
   Text& Text::operator=(const Text& rhs)
   {
       if (this != &rhs) {
           setEmpty();
           setName(rhs.m_filename);
           read();
       }
       else {
           setEmpty();
       }
       return *this;
   }

   //void read()
   //First, read will the current content of the fileand then allocates memory to the size of the file on the disk + 1 (for the null byte)
   void Text::read()
   {
       int i = 0;
       char charRead;

       ifstream f(m_filename);

       if (f.is_open()) {
           if (m_content) {
               delete[] m_content;
               m_content = nullptr;
           }
           m_content = new char[getFileLength() + 1];

           //it will read the contents of the file character by character into the newly allocated memory
           while (f.get(charRead)) {
               m_content[i] = charRead;
               i++;
           }

           //terminates it with a null byte at the end.
           m_content[i] = '\0';
       }
       else {
           m_content = nullptr;
       }
   }

   //This virtual function will insert the content of the Text class into the ostream if m_content is not null.
   void Text::write(ostream& os) const
   {
       if (m_content != nullptr) {
           os << m_content;
       }
   }


   // definiton of insertion overload into ostream
   //write function in overload
   ostream& operator<<(ostream& os, const Text& t)
   {
       t.write(os);
       return os;
   }


}