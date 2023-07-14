/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #4 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"

using namespace std;
namespace sdds {
    //creates a dynamic array of Labels to the size of noOfLabels
    LabelMaker::LabelMaker(int noOfLabels) : labels(nullptr), noOfLabels(noOfLabels) {
        if (noOfLabels > 0) {
            labels = new Label[noOfLabels];
        }
    }

    //Gets the contents of the Labels
    void LabelMaker::readLabels() {
        cout << "Enter " << noOfLabels << " labels:" << endl;
        for (int i = 0; i < noOfLabels; i++) {
           cout << "Enter label number " << i + 1 <<endl;
           cout << "> ";
           labels[i].readLabel();
        }  
    }

    //Prints the Labels
    void LabelMaker::printLabels() {
        for (int i = 0; i < noOfLabels; i++) {
            labels[i].printLabel();
            cout << endl;
        }
    }

    //Deallocates the memory when LabelMaker goes out of scope.
    LabelMaker::~LabelMaker() {
        delete[] labels;
    }
}