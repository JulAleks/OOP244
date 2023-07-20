/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 8 - LAB
 Shape Module
 File	Shape.cpp
 Version 1.0
 Date 2023-07-17
 Author	Julia Alekseev
 Student ID 051292134
 Description:

 =====This is the Shape interface implementation of overloading operators=====
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#include <iostream>

#include "Shape.h"

using namespace std;
namespace sdds {

    //Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be written or read using ostream and istream.
    ostream& operator<<(ostream& os, const Shape& RO) {
       RO.draw(os);
       return os;
   }
    istream& operator>>(istream& is, Shape& RO) {
        RO.getSpecs(is);
        return is;
    }

}
