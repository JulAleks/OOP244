/*------------------------------------------------------------------
 Final Project Milestone 5
 Streamable Module
 File	Streamable.cpp
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
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

    //Insertion operator overload
    //Overload the insertion operator so a constant object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state.Otherwise, the function will quietly ignore the insertion action.
    ostream& operator<<(ostream& os, const Streamable& rhs) {
        // Object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state
        if (rhs) {
            rhs.write(os);
        }
        return os;
    }

   istream& operator>>(istream& is, Streamable& rhs) {
        return (rhs.read(is));
    }
}

