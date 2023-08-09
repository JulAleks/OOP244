/*------------------------------------------------------------------
 Final Project Milestone 5
 Utils Module
 File	Utils.cpp
 Version 1.0
 Date 2023-08-02
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason
Julia Alekseev		2023-07-06		 Original version
Julia Alekseev		2023-08-02		 Additional function
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


int getPositive(int low, int high, const char* error) {
    int choice;
    do {
        cin >> choice;
        if (cin.fail() || choice < low || choice > high) {
            cout << error;
            cin.clear(); // Clear buffer
            cin.ignore(10, '\n');
        }
        else {
            return choice;
        }
    } while (true);
}


}