/*------------------------------------------------------------------
 Final Project Milestone 2
 LibApp Module
 File	LibApp.h
 Version 1.0
 Date  2023-07-11
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
namespace sdds {
   class LibApp: public Menu {
	   //----------LibApp Attributes---------
	   //A flag to keep track of changes made to the application data. This flag is initially set to false. If any change is made to the data of the application, this flag is set to true.
	   bool m_changed;

	   //This menu will be used as the main menu of the applicationand
	   Menu m_mainMenu;


	   //This menu will be used when exiting the program if any changes are made to the data. This menu should be initialized with the following title:
	   Menu m_exitMenu;

		//--Private Methods

	   //Instantiate a Menu in this function and initialize it with the message argument.
	   bool confirm(const char* message);

	   void load();  // prints: "Loading Data"<NEWLINE>
	   void save();  // prints: "Saving Data"<NEWLINE>
	   void search();  // prints: "Searching for publication"<NEWLINE>

	   void returnPub();  /*  Calls the search() method.
							  prints "Returning publication"<NEWLINE>
							  prints "Publication returned"<NEWLINE>
							  sets m_changed to true;
						  */

	   //prints "Adding new publication to library"+newline
	   void newPublication();

	   //prints "Removing publication from library"+newline
	   void removePublication();

	   //calls the search method
	   void checkOutPub();

   public:
	   //---Constructor
	   LibApp();

	   //The run method is the main application driver.
	   void run();
   };
}
#endif // !SDDS_LIBAPP_H



