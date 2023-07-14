/*------------------------------------------------------------------
 Final Project Milestone 1
 Menu Module
 File	Menu.h
 Version 1.0
 Date July 6, 2023
 Author	Julia Alekseev 
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const unsigned int  MAX_MENU_ITEMS = 20;

    class MenuItem {
    private:
        //This class holds only one Cstring of characters for the content of the menu item dynamically. The length of the content is unknown.
        char* itemContent{};

        //safe empty state
        void setEmpty();

        //set name for item
        void setItem(const char* description);

        //Constructor
        MenuItem();
        MenuItem(const char* description);
        //Destructor-Deallocates the content
        ~MenuItem();

        //Rule of Three - A MenuItem object cannot be copied from or assigned to another MenuItem object.
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        //Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
        operator bool() const;

       // Overload the indexing operator to return the const char* cast
        operator const char* () const;

        // Display the content of the MenuItem on ostream
        std::ostream& display(std::ostream& os = std::cout);

        //Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
        friend class Menu;
    };

    class Menu {
    private:
        //A MenuItem to possibly hold the title of the Menu.
        MenuItem menuTitle{};

        //An array of MenuItem pointers. The size of this array is set by a constant unsigned integer defined in the Menu header file
        MenuItem* menuItems[MAX_MENU_ITEMS]{};

        //An integer to keep track of how many MenuItem pointers are pointing to dynamic MenuItem objects. 
        unsigned totalItems = 0;

    public:
        //******Constructors
        Menu();
        Menu(const char* description);

        //Destructor
        ~Menu();

        //Rule of Three-A Menu Object can not be copied or assigned to another Menu Object.
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        //********Methods
        // Function to display the title of the menu
        std::ostream& displayMenuTitle(std::ostream& os);

        // Display the content of Menu on ostream
        std::ostream& displayMenu(std::ostream& os = std::cout);

        // Displays the Menu and gets the user selection.
        unsigned int run();

        // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
        unsigned int operator~();

        //Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
        operator int();
        operator unsigned int();

        //Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
        operator bool();

        //set menu
        void setMenu(const char* menuitemConent);

        //Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
        Menu& operator<<(const char* menuitemConent);

        //Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
        const char* operator[](unsigned int index) const;
    };
    //Overload the insertion operator to print the title of the Menu using cout.
    std::ostream& operator<<(std::ostream& os, Menu&);
}

#endif