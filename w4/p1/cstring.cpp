/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #4 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 7, 2023
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

       

        int strCmp(const char* s1, const char* s2) {
            int x = 0;
            int i = 0;
            while (s1[i] != '\0' && s2[i] != '\0' && x == 0) {
                if (s1[i] < s2[i]) {
                    x = -1;
                }
                else if (s1[i] > s2[i]) {
                    x = 1;
                }
                i++;
            }

            if (s1[i] == '\0' && s2[i] == '\0') {
                x = 0;
            }

            return x;
        }

      

        int strLen(const char* s) {

            int len = 0;
            while (s[len] != '\0') {
                len++;
            }
            return len;

        }

      


      

    
}