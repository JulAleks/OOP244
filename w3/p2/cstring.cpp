/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 2)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "cstring.h"
namespace sdds {

    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src) {
        int srcLen = 0;
        while (src[srcLen] != '\0') {
            srcLen++;
        }
        for (int i = 0; i < srcLen; i++) {
            des[i] = src[i];
        }
        des[srcLen] = '\0';  
    }

    // Copies the source character string into the destination upto "len"
 // characters. The destination will be null terminated only if the number
 // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len) {
        int i = 0;
        for (i = 0; src[i] != '\0' && i < len; i++) {
            des[i] = src[i];
        }

        des[i] = '\0';
    }

}