/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #6 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  July 05, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "cstring.h"
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

    void strCat(char* des, const char* src) {

        int sizeOfDes = strLen(des);
        int sizeOfSrc = strLen(src);

        for (int i = 0; i < sizeOfSrc; i++) {
            des[sizeOfDes + i] = src[i];
        }
        des[sizeOfDes + sizeOfSrc] = '\0';

    }

}