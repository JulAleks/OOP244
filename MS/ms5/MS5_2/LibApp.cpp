/*------------------------------------------------------------------
 Final Project Milestone 5
 LibApp Module
 File	LibApp.cpp
 Version 1.0
 Date 2023-08-01
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name                 Date            Reason
 Julia Alekseev		2023-07-11		 Original version
 Julia Alekseev     2023-07-30       MS5 instrcutions
 Julia Alekseev     2023-08-01       MS5 instrcutions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Book.h"
#include "LibApp.h"
#include "PublicationSelector.h"
using namespace std;
namespace sdds {


	LibApp::LibApp(const char* filename)	
	{
	
		if (filename && filename[0] != '\0' && strlen(filename)< SDDS_MAX_FILENAME)
		{
			m_fileName = new char[strlen(filename) + 1];
			strcpy(m_fileName, filename);
			
		}

		// Setting the bool value to false by default
		m_changed = false;

		// Setting the NOLP to 0
		m_NOLP = 0;

		// Populating main menu items using operator overload in Menu class
		m_mainMenu.changeName("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

		// Populating exit menu items using operator overload in Menu class
		m_exitMenu.changeName("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		// Populating publication type menu items using operator overload in menu class
		m_publicationType.changeName("Choose the type of publication:");
		m_publicationType << "Book" << "Publication";

		load();
	}



	LibApp::~LibApp() {
		// Deleting the dynamically allocated memory
		delete[]m_fileName;
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
		}
	}


	bool LibApp::confirm(const char* message) {
		Menu confirmMenu(message); //Instantiate a Menu in this function and initialize it with the message argument.
		confirmMenu << "Yes";  //Then add only a "yes" as a single menu item to the Menu. 

		//Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
		unsigned select = confirmMenu.run();
		return (select == 1) ? true : false;
	}

	// prints: "Loading Data"<NEWLINE>
	void  LibApp::load() {
		//First print "Loading Data" and then open the data file for reading 
		cout << "Loading Data" << endl;
		ifstream infile(m_fileName);

		//read all the publications in dynamic instances pointed by the PPA Array. 
		//reading a single character for the type of publicationand then dynamically instantiating the corresponding object into the next available PPA element.
		char type='\0';
		for (int i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
			// Reading the first character to determine the type of publication
			infile >> type;

			// Ignoring the white space character
			infile.ignore();

			// Dynamically allocating space for the m_PPA array based on the type of publication
			if (infile) {
				if (type == 'P')
					m_PPA[i] = new Publication;

				else if (type == 'B')
					m_PPA[i] = new Book;

				if (m_PPA[i]) {
					// Extracting the object from the file stream
					infile >> *m_PPA[i];
					m_NOLP++;
					// Setting the LLRN to the reference number of the last publication read
					m_LLRN = m_PPA[i]->getRef();
				}
			}
		}
	}

	// prints: "Saving Data"<NEWLINE>
	void LibApp::save() {
		//First print "Saving Data"
		cout << "Saving Data" << endl;
		ofstream offile(m_fileName);

		for (int i = 0; i < m_NOLP; i++) {
			//Publications that have the reference number of 0 (zero) are deleted by the user (removed from the library) and therefore should not be saved back into the data file
			if (m_PPA[i]->getRef() != 0)
			{
				offile << *m_PPA[i] << std::endl;
			}
		}
		//closing the file
		offile.close();
	}

	//Create a method to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument. 
	Publication* LibApp::getPub(int ref) {
		Publication* pub = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == ref) {
				pub =m_PPA[i];
			}
		}

		return pub;
	}


	// prints: "Searching for publication"<NEWLINE>
	int LibApp::search(int select) {

		/*Search will use an instance of PublicationSelector class to collect the search matches and user selection. 
		The prompt of the PublicSelector should be: "Select one of the following found matches:" The page size for the selector menu should be 15 (the default value)*/
		PublicationSelector selectSearch("Select one of the following found matches:", 15);

		int m_select = 0;
		int selectReff = 0;
		char type = '\0';
		char tempTitle[SDDS_MAX_FILENAME + 1];
		//First, get the type of publication to search for from the user. (user the type selection Menu of the class)
		m_select = m_publicationType.run();
		cin.ignore(1000, '\n'); //flushing the keyboard
		//assigning the selection to the search type
		switch (m_select) {
			// 1- Book
		case 1:
			type = 'B';
			break;
			// 2- Publication
		case 2:
			type = 'P';
			break;
		}


		//Then print "Publication Title: "
		cout << "Publication Title: ";

		//get the title to search the PPA for. (up to 256 characters)
		cin.getline(tempTitle, SDDS_MAX_FILENAME);
	
		/*Go through all the publications in the PPA and base on the method of search (all the items, on loan items or available ones) 
		check each element and if the publication (pointed by the PPA element) is not deleted and type matches the selection of the user 
		and the title contains the title the user entered, insert it into the PublicationSelector object. */
		switch (select) {
			
		//Search all
		case 1:
			
			for (int i=0; i < m_NOLP; i++)
			{
				if (*m_PPA[i] == tempTitle && type == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					selectSearch << m_PPA[i];
				}
			}
			break;

		//Search Checkout Items Search only those publications which are on loan by library members
		case 2:
			
			for (int i = 0; i < m_NOLP; i++)
			{
				if (*m_PPA[i] == tempTitle && type == m_PPA[i]->type() && m_PPA[i]->onLoan() && m_PPA[i]->getRef() != 0) {
					selectSearch << m_PPA[i];
				}
			}
			break;
		//Search Available Items Search only those publications which are not on loan
		case 3:
			
			for (int i = 0; i < m_NOLP; i++)
			{
				if (*m_PPA[i] == tempTitle && type == m_PPA[i]->type() && !m_PPA[i]->onLoan() && m_PPA[i]->getRef() != 0) {
					selectSearch << m_PPA[i];
				}
			}
			break;
		}
		
		//If matches are found, sort the result and get the user's selection and return the library reference number. If not print "No matches found!"
		if (selectSearch) {
			selectSearch.sort();
			selectReff =selectSearch.run();

			if (selectReff) {
				cout << *getPub(selectReff) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}

		//return value of getRef() method
		return  selectReff;
	}



	void LibApp::newPublication() {
		bool exit = false;//setting boolean for condition

		// If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.
		
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
			exit = true;  //setting boolean to true to exit
		}

		if (!exit) {  //if not exiting continue
			cout << "Adding new publication to the library" << endl;

			// Get the publication type from the user.
			int pubType = m_publicationType.run();

			//clearing the enter
			cin.ignore(1000, '\n');

			// Instantiate a dynamic "Publication" or "Book" based on the user's choice.
			Publication* pub = nullptr;

			// Create the appropriate publication based on the user's choice.
			switch (pubType) {
			case 1:
				pub = new Book;
				// Read the instantiated object from the cin object.
				cin >> *pub;
				break;
			case 2:
				pub = new Publication;
				// Read the instantiated object from the cin object.
				cin >> *pub;
				break;
			default:
				cout << "Aborted!" << endl << endl;
				delete pub;
				exit = true; //setting boolean to exit 
				break;
			}

			// If the cin fails, display an error message, and clean up.
			if (cin.fail()) {
				cin.clear();
				cin.ignore('\n');
				cout << "Aborted!" << endl << endl;
				return;
			}
			if (!exit) {  //if not exiting
				// If the cin is ok, then confirm that the user wants to add the publication to the library using prompt
				if (confirm("Add this publication to the library?")) {
					//If the publication object is not valid print: "Failed to add publication!" and delete the allocated memory.
					if (!(*pub)) {
						cout << "Failed to add publication!" << endl;
						delete pub;
					}
					else {
						//Add one to the LLRN and set the library reference number to the value
						m_LLRN++;
						pub->setRef(m_LLRN);

						//Add the publication object's address to the end of the PPA and add one to the NOLP.
						m_PPA[m_NOLP] = pub;

						m_NOLP++;
						m_changed = true;

						//print: "Publication added"
						cout << "Publication added" << endl << endl;
					}
				}
				else {
					//If the user did not confirm, print "Aborted!" and exit.
					cout << "Aborted!" << endl << endl;
				}
			}
		}
	}
	

	void LibApp::returnPub() {
		//Calls the search() method
		//search();

		//prints "Returning publication"<NEWLINE>
		cout << "Returning publication" << endl;

		//prints "Publication returned"<NEWLINE>
		cout << "Publication returned" << endl << endl;

		//sets m_changed to true;
		m_changed = true;
	}


	void  LibApp::removePublication() {
		//print: "Removing publication from the library"
		cout << "Removing publication from the library" << endl;

		//Search all the publications
		int result = 0;
		result=search(1); //1=all publications
		
		//If the user selects a publication and confirms to remove the publication using the prompt: "Remove this publication from the library?"
		if (result) {
			//calls the confirm method with "Remove this publication from the library?"
			bool select = confirm("Remove this publication from the library?");

			if (select) {
				//Set the library reference of the selected publication to 0 (zero)
				getPub(result)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl << endl;
			}
			else {
				cout << endl;
			}
		}
	}



		void LibApp::checkOutPub() {
		//calls the search method
		//search();

		//calls the confirm method with Check out publication?"
		bool select = confirm("Check out publication?");

		//if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
		m_changed = (select) ? (cout << "Publication checked out" << endl << endl, true) : (cout << endl, false);
	}



	//The run method is the main application driver.
	void LibApp::run() {
		unsigned mainSelect, exitSelect;
		//It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
		do {
			mainSelect = m_mainMenu.run();
			switch (mainSelect) {
			//When the user selects exit, the value of m_changed is examined. If the value is false, then since the data of the application is not modified, the program terminates.
			case 0:
				if (m_changed) {
					//If the value is true, the m_exitMenu is used by calling its run method. Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving. 
					exitSelect = m_exitMenu.run();
					if (exitSelect == 0) {
						//If the exit is selected, then the confirm menu will be called using the message: 
						//"This will discard all the changes are you sure?". 
						//If the user selects Yes, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.
						//changing m_changed to false so when the conditon will be checked on case 0 the flag would be canged to 0 and exit the loop
						(confirm("This will discard all the changes are you sure?")) ? m_changed = false : m_changed = true;
					}
					else if (exitSelect == 1) {
						//If the first one is selected, the save() method is called and the program terminates.
						save();
					}
					else if (exitSelect == 2){
						//If the second one is selected the program goes back to the main menu and execution continues.
						mainSelect = 1;
						
					}
				}
				cout << endl;
				break;
			// Carrying out options according to the choice of user in the exit menu
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}
		} while (mainSelect != 0); 

		cout << "-------------------------------------------" <<endl;
		cout << "Thanks for using Seneca Library Application" <<endl;
	}

}





















