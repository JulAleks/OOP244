/*------------------------------------------------------------------
 Final Project Milestone 5
 LibApp Module
 File	LibApp.h
 Version 1.0
 Date 2023-08-02
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name                 Date            Reason
 Julia Alekseev		2023-07-11		 Original version
 Julia Alekseev     2023-07-30       MS5 instrcutions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
#include "Lib.h"
#include "Publication.h"




namespace sdds {
   class LibApp: public Menu {
	   //----------LibApp Attributes---------
	   // upadted for MS5
	   //Add an array of 256 characters to hold the publication data file name.
	   char *m_fileName{};
	    

	   //Create and add an array of Publication pointers to the size of SDDS_LIBRARY_CAPACITY. This array will be populated with all the records of the publication data file when the LibApp is instantiated. 
	   Publication* m_PPA[SDDS_LIBRARY_CAPACITY];


	   //Add an integer to hold the number of Publications loaded into the PPA. 
	   int m_NOLP{ 0 };

	   /*Add an integer to hold the last library reference number read from the data file. This number will be used to assign new library reference numbers to new publications added to the library. 
	   When a new publication is added to the library, this number will be added by one and then assigned to the new publication. 
	   Doing this; each publication in the library will have a unique library reference number.*/
	   int m_LLRN{ 0 };

	   //Add a Menu to the LibApp for selection of publication type. The title of this menu is: "Choose the type of publication"
	   Menu m_publicationType;


	   //Create a method to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument. 
	   Publication* getPub(int libRef);

	   //If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit. 
	   void newPublication();




	    //previous MS implementation
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
	   int search(int select);  // prints: "Searching for publication"<NEWLINE>

	   void returnPub();  /*  Calls the search() method.
							  prints "Returning publication"<NEWLINE>
							  prints "Publication returned"<NEWLINE>
							  sets m_changed to true;
						  */

	 
	   //prints "Removing publication from library"+newline
	   void removePublication();

	   //calls the search method
	   void checkOutPub();

   public:
	   //---Constructor
	   LibApp(const char* fileName);

	   //destructor 
	   ~LibApp();
	   //The run method is the main application driver.
	   void run();


   };
}
#endif // !SDDS_LIBAPP_H



