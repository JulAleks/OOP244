/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 Rectangle Module
 File	Rectangle.cpp
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <iomanip> 

#include "Rectangle.h"
using namespace std;
namespace sdds {

	//Default(no argument) constructor
	//Sets the widthand height member variables to zero.It will also invoke the default constructor of the base class.
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}
	//Three argument constructor
	//Receives a Cstring for the label, and two values for the width and height of the Rectangle from the argument list. 
	Rectangle::Rectangle(const char* Cstring, int width, int height) : LblShape(Cstring) {
		//Passes the Cstring to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values received from the argument list. 
		//However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle to an empty state.
		int sizeOfLabel = strlen(LblShape::label()) + 2;
		if (width > sizeOfLabel && height > 3) {
			m_width = width;
			m_height = height;
		}
		else {
			m_width = 0;
			m_height = 0;
		}
	}

	//Reads comma-separated specs of the Rectangle from istream.
	//This function overrides the getSpecs function of the base class as follows.
	void Rectangle::getSpecs(istream& is) {
		// First, call the getSpecs function of the base class
		
		LblShape::getSpecs(is);

		//then it will read two comma - separated values from istream for m_widthand m_lengthand 
		char comma;
		int width, height;
		is >> width >> comma >> height;
		
		if (is) {
			// then ignores the rest of the characters up to and including the newline character('\n').	
			is.ignore(1000, '\n');
			m_width = width;
			m_height = height;
		}

	}
	

	//This function overrides the draw function of the base class.
	void Rectangle::draw(ostream& os)const {
		// If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows
		if (m_width && m_height) {
			//First line:
			//prints '+', then prints the '-' character(m_width - 2) times and then prints '+' and goes to newline.
			os << '+' << setw(m_width - 2) << setfill('-') << '-' << '+' << endl;

			//Second line: prints '|', then in(m_width - 2) spaces it prints the label() left justifiedand then prints '|' and goes to new line.
			
			os << '|' << setw(m_width - 2) << setfill(' ') <<left<< LblShape::label() << '|'<<endl;;
		
			//In next (m_height - 3) lines:
			for (int i = 0; i < (m_height - 3); i++) {
				//prints '|', (m_width - 2) spaces then prints '|' and goes to new line.
				os << '|' << setw(m_width - 2) << setfill(' ') << ' ' << '|' << endl;
			}
			//Last line: exactly like first line.
			os << '+' << setw(m_width - 2) << setfill('-') << '-' << '+';
		}
		else {
			; //otherwise, it will do nothing:
		}
	}
}

