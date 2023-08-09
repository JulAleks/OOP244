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

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>


namespace sdds {
   class Text {
      char* m_filename { nullptr }; //Hold the name of the file dynamically
      char* m_content { nullptr };  //Holds the content of the text file dynamically. 
      int getFileLength()const; //// Code provided in Text.cpp
   protected:
      const char& operator[](int index)const;
   public: 
      Text(const char* filename=nullptr); // implement rule of three here

      //sets to an empty state
      virtual void setEmpty();

      //sets name
      void setName(const char *name);

      //The rule of three, Implement the rule of three so memory is managed properly in case of copyingand assignment.
      virtual ~Text(); //destructor
      Text (const Text&); //copy costructor
      Text & operator=(const Text &); //assigment constructor

      void read(); //reading from a file

      virtual void write(std::ostream& os)const; //writing to a file
   };

   // prototype of insertion overload into ostream goes here
   std::ostream& operator<<(std::ostream& os, const Text & t);  


}

#endif // !SDDS_TEXT_H__

