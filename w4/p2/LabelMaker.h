/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #4 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

#include "Label.h"

namespace sdds {
    class LabelMaker {
        Label* labels; //points to a dynamically allocated Cstring of the labels to be printed
        int noOfLabels; //the number of requested labels 

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif // SDDS_LABELMAKER_H