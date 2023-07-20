/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
  Workshop 8 - LAB
 Shape Module
 File	Shape.h
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Description:

 =====This is the Shape interface=====

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/


#include <iostream>
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
namespace sdds {

    //shape class
    class Shape {
    public:
        //Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
        virtual void draw(std::ostream& os) const = 0;

        //Returns void and receives a reference to istream as an argument. 
        virtual void getSpecs(std::istream& is) = 0;

        //Create a virtual empty destructor for the shape interface. 
        virtual ~Shape() {};
        // virtual ~Shape()=0
    };

    //Shape helper functions

    //Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.
    std::ostream& operator<<(std::ostream& os, const Shape& RO);
    std::istream& operator>>(std::istream& is,  Shape& RO);

}
#endif // !SDDS_SHAPE_H_

