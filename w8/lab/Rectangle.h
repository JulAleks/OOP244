/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 Rectangle Module
 File	Rectangle.h
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Description:

********The Rectangle concrete class******
The Rectangle class inherits the LblShape class to create a frame with a label inside.

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#include "LblShape.h"

#ifndef SDDS_RECTANGLE_H_

#define SDDS_RECTANGLE_H_
namespace sdds {

	class Rectangle : public LblShape
	{
		//Private Member variable
		//Create two member variables called m_widthand m_height to hold the widthand the height of a rectangular frame(number of characters).
		int m_width{ 0 };
		int m_height{ 0 };
	public:

		//Default (no argument) constructor
		Rectangle();
		
		//Three argument constructor
		Rectangle(const char * Cstring, int width, int height);

		//Reads comma-separated specs of the Rectangle from istream.
		void getSpecs(std::istream& is);

		//This function overrides the draw function of the base class.
		void draw(std::ostream& os)const;

	};



}
#endif // !SDDS_RECTANGLE_H_
