/*------------------------------------------------------------------
 Final Project Milestone 2
 LibApp Module
 File	LibApp.cpp
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
#include "LibApp.h"
using namespace std;
namespace sdds {

	//---Constructor
	LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		//when exiting the program, we can warn the userand ask if they like the changes to be saved or discarded.
		m_changed = false;

		//populated with the following menu items using overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		load();
	}

	//Private Methods
	bool LibApp::confirm(const char* message) {
		Menu confirmMenu(message); //Instantiate a Menu in this function and initialize it with the message argument.
		confirmMenu << "Yes";  //Then add only a "yes" as a single menu item to the Menu. 

		//Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
		unsigned select = confirmMenu.run();
		return (select == 1) ? true : false;
	}

	// prints: "Loading Data"<NEWLINE>
	void  LibApp::load() {
		cout << "Loading Data" << endl;
	}

	// prints: "Saving Data"<NEWLINE>
	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	// prints: "Searching for publication"<NEWLINE>
	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}


	void LibApp::returnPub() {
		//Calls the search() method
		search();

		//prints "Returning publication"<NEWLINE>
		cout << "Returning publication" << endl;

		//prints "Publication returned"<NEWLINE>
		cout << "Publication returned" << endl<<endl;

		//sets m_changed to true;
		m_changed = true;
	}


	//---Methods with confirmation----ca

	void  LibApp::newPublication() {
		//prints "Adding new publication to library"+newline
		cout << "Adding new publication to library" << endl;

		//calls the confirm method with "Add this publication to library?"
		bool select = confirm("Add this publication to library?");

		//if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
		m_changed = (select) ? (cout << "Publication added" << endl << endl , true) : (cout << endl, false);
		
	}

	void  LibApp::removePublication() {
		//prints "Removing publication from library"+newline
		cout << "Removing publication from library" << endl;

		//calls the search method
		search();

		//calls the confirm method with "Remove this publication from the library?"
		bool select = confirm("Remove this publication from the library?");

		//if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
		m_changed = (select) ? (cout << "Publication removed" << endl << endl, true) : (cout << endl, false);
	}


	void LibApp::checkOutPub() {
		//calls the search method
		search();

		//calls the confirm method with Check out publication?"
		bool select = confirm("Check out publication?");

		//if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
		m_changed = (select) ? (cout << "Publication checked out" << endl << endl, true) : (cout << endl, false);
	}


	//---The run method----

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





















