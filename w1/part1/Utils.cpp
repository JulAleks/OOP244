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


//A module to hold the general utility functions for the applications. This file may be moved to other workshops and assignments if needed.

#include <iostream>
#include "Utils.h"

using namespace std;


namespace sdds {

    void flushkeys() {
        while (cin.get() != '\n');
    }

    bool ValidYesResponse(char ch) {
        return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
    }

    bool yes() {
        char ch = 0;
        do {
            cin >> ch;
            flushkeys();
        } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
        return ch == 'y' || ch == 'Y';
    }

    void readCstr(char cstr[], int len) {
        char buf[1024] = {};
        int i;
        cin.getline(buf, 1024);
        for (i = 0; i < len && buf[i]; i++) {
            cstr[i] = buf[i];
        }
        cstr[i] = 0;
    }

    int readInt(int min, int max) {
        int value = 0;
        bool done = false;
        while (!done) {
            cin >> value;
            if (!cin) {
                cin.clear();
                cout << "Bad integer, try agian: ";
            }
            else {
                if (value >= min && value <= max) {
                    done = true;
                }
                else {
                    cout << "Value out of range (" << min << "<=value<=" << max << "): ";
                }
            }
            flushkeys();
        }
        return value;
    }

}