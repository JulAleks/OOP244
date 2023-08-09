/*------------------------------------------------------------------
 Final Project Milestone 5
 Utils Module
 File	Utils.h
 Version 1.0
 Date 2023-08-02
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason
 Julia Alekseev		2023-07-06		 Original version
 Julia Alekeev		2023-08-02       Additional function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	unsigned selection(unsigned low, unsigned high);
	int getPositive(int low, int high, const char* error);
}
#endif // SDDS_UTILS_H__
