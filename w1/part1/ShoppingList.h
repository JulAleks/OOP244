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

#ifndef NAMESPACE_SHOPPINGLIST_H 
#define NAMESPACE_SHOPPINGLIST_H

#include "ShoppingRec.h"

namespace sdds {

    const int MAX_NO_OF_RECS = 15;

    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();

}

#endif
