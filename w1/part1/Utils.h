/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #1 (Part-1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef NAMESPACE_UTILS_H 
#define NAMESPACE_UTILS_H

namespace sdds {

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);

}

#endif

