/*------------------------------------------------------------------
 Final Project Milestone 5
 Book Module
 File	Book.cpp
 Version 1.0
  Date 2023-07-31
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Book.h"

using namespace std;

namespace sdds {
	
	//A book is created empty by default, in a safe empty state.
	void Book::setEmpty()
	{
		if (m_authorName) {
			delete[] m_authorName;	
		}
		m_authorName = nullptr;
	}


	//set name
	void Book::setName(const char* name)
	{
		m_authorName = new char[strlen(name) + 1];
		strcpy(m_authorName, name);
		
	}

	//default constructor
	Book::Book() {
		setEmpty();
	}
	//one parameter constructor
	Book::Book(const char* name)
	{
		if (m_authorName) {
			delete[] m_authorName;
		}
		setName(name);
	}

	//The rule of three
	//Implement what is needed to comply with the rule of three so a book can safely be copied or assigned to another book.	
	//destructor
	Book::~Book() {
		setEmpty();
	}

	//copyingand
	Book::Book(const Book& b) {
		if (this != &b) {
			if (m_authorName) {
				delete[] m_authorName;
			}
			if (b.m_authorName && b.m_authorName[0] != '\0') {
				setName(b.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
	}

	// assignmentand
	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			Publication::operator=(b);
			if (m_authorName) {
				delete[] m_authorName;
			}
			if (b.m_authorName && b.m_authorName[0] != '\0') {
				setName(b.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
		return *this;
	}


	//Returns the character "B".
	char Book::type() const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
	//First, it will invoke the write of its Base class
	Publication::write(os);

	//If the incoming argument is a console IO object.
	if (conIO(os)) {
		//writes a single space
		os << " ";
		//writes the author's name in SDDS_AUTHOR_WIDTH spaces.
		//If the author's name is longer than the SDDS_AUTHOR_WIDTH value, it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters. 
		char tempName[SDDS_AUTHOR_WIDTH + 1] = { '\0' };
		// Truncate the name to exactly SDDS_AUTHOR_WIDTH characters.
		strncpy(tempName, m_authorName, SDDS_AUTHOR_WIDTH);
		os <<setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << tempName << " |";	
	}
	//If the incoming argument is not a console IO object
	else {
	//writes a tab character '\t', writes the author's name
		os << "\t" << m_authorName;
	}
	//returns the incoming ostream.
		return os;
	}

	//Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)
	std::istream& Book::read(std::istream& is) {
		//First, invoke the read of the Base class.
		Publication::read(is);
		char tempName[256] = { 0 };
		//Free the memory held for the author's name
		if (m_authorName) {
			setEmpty();
		}

		//If the incoming argument is a console IO object
		if (conIO(is)) {
			//ignore one character (skip the '\n')
			is.ignore();

			//prompt "Author: "
			cout << "Author: ";
		}
		else {
			//ignore one character (skip the '\n')
			is.ignore();
		}

		is.get(tempName, 256);

		//Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
		if (is) {
			if (m_authorName) {
				delete[] m_authorName;
			}
			setName(tempName);
		}

	//At the end return the incoming istream object.
		return is;
	}

	//sets member id and current date.
	void Book::set(int member_id) {
		//invoke the set of the base class to set the member id
		Publication::set(member_id);

		//reset the date to the current date.
		Publication::resetDate();
	}

	//return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
	Book::operator bool() {
		return (m_authorName && m_authorName[0] != '\0' && Publication::operator bool());
	}

}