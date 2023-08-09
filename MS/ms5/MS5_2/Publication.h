/*------------------------------------------------------------------
 Final Project Milestone 5
 Publication Module
 File	Publication.h
 Version 1.0
 Date 2023-08-01
 Author	Julia Alekseev
 Student ID 051292134
 Section NEE
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason
Julia Alekseev		2023-07-24		 Original version
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

//Publication class module
//The publication class is a general encapsulation of any periodic publication.
//Later by adding an author to the descendant of the Publication class we will encapsulate a Book for the system.


#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Lib.h"
#include "Streamable.h"
#include "Date.h"

namespace sdds {

	class Publication : public Streamable {

		//=====Publication Attributes

		//m_title is a c-string to hold a dynamic title for the publication.
		//To ease the implementation, let's assume this dynamic array can not be more than 255 characters long
		char* m_title;

		//Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long. 
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];

		//This attribute is an integer to hold a 5 digit membership number of members of the library. 
		int m_membership;
	
		//This serial number is used internally to uniquely identify each publication in the system.
		int m_libRef;
		
		//A Date object.
		//In periodical publications, this date is used for the publish date of the item.
		Date m_date;//The Date, by default, is set to the current date.

	public:

		//default constructor
		Publication();
		
		//safe state
		void setDefault();

		//// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);

		//Sets the libRef attribute value
		void setRef(int value);

		// Sets the date to the current date of the system.
		void resetDate();

		//Queries

		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;

		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;

		//Returns the date attribute
		Date checkoutDate()const;

		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;

		////Returns the title attribute
		operator const char* ()const;

		////Returns the libRef attirbute. 
		int getRef()const;

		//Streamable pure virtual function implementations

		//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		bool conIO(std::ios& io)const;
		
		//If the os argument is a console IO object (use conIO()), print shelfId, title, membership and date attributes as the following format (title is left-justified padded with dots)
		std::ostream& write(std::ostream& os) const;

		//Read all the values in local variables before setting the attributes to any values
		std::istream& read(std::istream& is);
		//Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
		operator bool()const;
	
		//Rule of 3 copy constructor, assigment and destructor
		~Publication();
		Publication(const Publication& Pub);
		Publication& operator=(const Publication& Pub);
	};
}

#endif // !SDDS_PUBLICATION_H