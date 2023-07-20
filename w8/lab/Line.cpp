/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 Line Module
 File	 Line.cpp
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Description:

********The Line concrete class******
Line inherits the LblShape class to create a horizontal line with a label.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {

	//Sets the m_length member variable to zero, and invokes the default constructor of the base class. 
	Line::Line():LblShape(){
		m_length = 0;
	}

	//Two argument constructor
	//Receives a Cstring and a value for the length of the line. 
	//Passes the Cstring to the constructor of the base class and sets the m_length member variable to the value of the second argument.*/
	Line::Line(const char* Cstring, int num):LblShape(Cstring) {
		if (num > 0) {
			m_length = num;
		}
	}

	//Reads comma-separated specs of the Line from istream.
	//This function overrides the getSpecs function of the base class as follows.
	void Line::getSpecs(std::istream& is) {
		//First, it will call the getSpecs function of the base class then it will read the value of the m_length attribute from the istream argument, 
		LblShape::getSpecs(is);
		int length;
		is >> length;
		//and then it will ignore The rest of the characters up to and including the newline character '\n'.
		m_length = (is.ignore(), is) ? length : (is.clear(), is.ignore(1000, '\n'), 0);	
	}


	//This function overrides the draw function of the base class.
	void Line::draw(ostream& os) const{
		//If the m_length member variable is greater than zero and the label() is not null
		if (m_length > 0 && LblShape::label() != nullptr) {
			//this function will first print the label() and then go to the new line. 
			os << LblShape::label() << endl;
			//Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
			for (int i= 0; i < m_length; i++) {
				os << "=";
			}
		}
		else {
			;	//Otherwise, it will take no action.
		}

	}
}


