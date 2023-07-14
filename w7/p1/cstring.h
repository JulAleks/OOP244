/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 7 - lAB
Cstring Module
 File	cstring.h
 Version 1.0
 Date 2023-07-11
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/



#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
    void strCpy(char* des, const char* src);
    int strCmp(const char* s1, const char* s2);
    int strLen(const char* s);
    void strnCpy(char* des, const char* src, int len);
}
#endif // !SDDS_CSTRING_H_

