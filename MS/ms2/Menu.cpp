/*------------------------------------------------------------------
 Final Project Milestone 2
 Menu Module
 File	Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> 
#include <cstring>
#include "Menu.h"
#include "Utils.h"


using namespace std;

namespace sdds {
    /*********The MenuItem Class************/

    //MenuItem should be set to an empty state.
    void MenuItem::setEmpty() {
        itemContent = nullptr;
    }

    //default
    MenuItem::MenuItem() {
        setEmpty();
    }

    //set name for item
    void MenuItem::setItem(const char* description) {
        if (description && description[0] != '\0') {
            setEmpty();
            itemContent = new char[strlen(description) + 1];
            strcpy(itemContent, description);
        }
    }

    //Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization)
    MenuItem::MenuItem(const char* description) {
        if (description && description[0] != '\0') {
            setItem(description);
        }
        else {
            //If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.
            setEmpty();
        }
    }

    //Destructor-Deallocates the content
    MenuItem::~MenuItem() {
        delete[] itemContent;
    }


    //When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.
    MenuItem::operator bool() const {
        return (itemContent && itemContent[0] != '\0') ? true : false;
    }

    //When a MenuItem is casted to “const char*” it should return the address of the content Cstring.
    MenuItem::operator const char* () const {
        return itemContent;
    }

    // Display the content of the MenuItem on ostream
    std::ostream& MenuItem::display(std::ostream& os) {
        if (*this) {
            os << itemContent;
        }
        return os;
    }

    //****The Menu Class*********
    //Constructors
    Menu::Menu() {
        for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
            menuItems[i] = nullptr;
        }
        totalItems = 0;
    };

    Menu::Menu(const char* description) : menuTitle(description) {};

    ////Destructor-Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.
    Menu::~Menu() {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete menuItems[i];
            menuItems[i] = nullptr;
        }
    };

    //methods
     //create a function to display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.
    std::ostream& Menu::displayMenuTitle(std::ostream& os) {
        if (menuTitle) {
            menuTitle.display();
        }
        return os;
    }

    // Display the content of Menu on ostream
    std::ostream& Menu::displayMenu(std::ostream& os) {
        if (menuTitle)
        {
            menuTitle.display();
            os << endl;
        }

        for (unsigned i = 0; i < totalItems; i++) {
            os << setw(2) << setfill(' ') << right << i + 1 << "- ";
            menuItems[i]->display() << endl;
        }
        os << setw(2) << right << 0 << "- Exit" << std::endl;
        os << "> ";

        return os;
    }

    // Displays the Menu and gets the user selection.
    unsigned int Menu::run() {
        displayMenu();
        return selection(0, totalItems);
    }

    // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
    unsigned int Menu::operator~() {
        return run();
    }

    //set menu
    void Menu::setMenu(const char* menuitemConent) {
        if (menuitemConent && menuitemConent[0] != '\0') {
            MenuItem* newMenuItem = new MenuItem(menuitemConent);
            menuItems[totalItems] = newMenuItem;
        }
    }

    //Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
    Menu& Menu::operator<<(const char* menuitemConent) {
        if (totalItems < MAX_MENU_ITEMS && menuitemConent && menuitemConent[0] != '\0') {
            setMenu(menuitemConent);
            totalItems++;
        }
        else {
            ;
        }
        return *this;
    }

    //Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
    Menu::operator int() {
        return totalItems;
    }

    Menu::operator unsigned int() {
        return totalItems;
    }

    //Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
    Menu::operator bool() {
        return totalItems > 0 ? true : false;
    }

    // Overload the indexing operator to return the const char* cast of the corresponding MenuItem
    const char* Menu::operator[](unsigned int index) const {
        if (index > totalItems)
        {
            // If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)
            return menuItems[index %= totalItems]->itemContent;
        }
        else
        {
            return menuItems[index]->itemContent;
        }
    }

    //Overload the insertion operator to print the title of the Menu using cout.
    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os));
    }
};