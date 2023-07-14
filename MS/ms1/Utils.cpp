/*------------------------------------------------------------------
 Final Project Milestone 1
 Utils Module
 File	Utils.cpp
 Version 1.0
 Date July 6, 2023
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
#include "Utils.h"
using namespace std;
namespace sdds {
	
unsigned selection(unsigned low, unsigned high) {
    unsigned choice;

    do {
        cin >> choice;
        if (cin.fail() || choice < low || choice > high) {
            cout << "Invalid Selection, try again: ";
            cin.clear(); // Clear buffer
            cin.ignore(10, '\n');
        } else {
            return choice;
        }
    } while (true);
}


}