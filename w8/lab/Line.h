/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 Line Module
 File	 Line.h
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


#include "LblShape.h"

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
namespace sdds {
	//Line inherits the LblShape class to create a horizontal line with a label.
	class Line : public LblShape {
		int m_length{ 0 };
	public:

		//Default (no argument) constructor
		Line();

		//Two argument constructor
		Line(const char *Cstring, int num);

		//This function overrides the getSpecs function of the base class
		void getSpecs(std::istream& is);

		//This function overrides the draw function of the base class.
		void draw(std::ostream& os)const;

	};



}
#endif // !SDDS_LINE_H_

