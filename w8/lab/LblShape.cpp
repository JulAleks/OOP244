/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 LblShape Module
 File	 LblShape.cpp
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Description:

********The LblShape abstract Class (the Labeled Shape class)******
Inherit an abstract class from the interface Shape called LblShape. This class adds a label to a Shape.
This class will implement the pure virtual function getSpecs but will not implement the draw function; therefore it remains abstract.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds {

	//Default (no argument) constructor
	LblShape::LblShape() {
		m_label = nullptr;
	}

	//One argument constructor
	//Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable.Then copies the Cstring argument to the newly allocated memory.
	LblShape::LblShape(const char* Cstring) {
		if (Cstring != nullptr && Cstring[0] != '\0') {
			m_label = new char[strlen(Cstring) + 1];
			strcpy(m_label, Cstring);
		}
	}

	//Deletes the memory pointed by m_label member variable.
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	//Add a query called label that returns the unmodifiable value of m_label member variable. 
	const char *LblShape::label() const{
		return m_label;
	}

	//getSpecs Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character (and then extract and ignore the comma). 
	void LblShape::getSpecs(istream& is) {
		//storing the new label input
		string n_label;

		//Reads a comma-delimited Cstring form istream:
		getline(is, n_label, ',');

		//Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory. */
		if (n_label[0] != '\0') {
			delete[] m_label;
			m_label = new char[strlen(n_label.c_str()) + 1];
			strcpy(m_label, n_label.c_str());
		}
	}

}

