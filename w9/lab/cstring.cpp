/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 9 - LAB
 Cstring Module
 File	 Cstring.cpp
 Version 1.0
 Date 2023-07-24
 Author	Julia Alekseev
 Student ID 051292134
 Description:

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

namespace sdds {
    void strCpy(char* des, const char* src) {

        int srcLen = 0;
        while (src[srcLen] != '\0') {
            srcLen++;
        }

        for (int i = 0; i <= srcLen; i++) {
            des[i] = src[i];
        }

    }

    int strLen(const char* s) {

        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;

    }

}