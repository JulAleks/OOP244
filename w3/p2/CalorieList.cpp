/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 2)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iomanip>
#include <iostream>

#include "CalorieList.h"

using namespace std;
namespace sdds {

	//Sets the CalorieList object to an empty state by assigning m_items to nullptr
	void CalorieList::setEmpty(){	
		m_items = nullptr;
	}

	//Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
	bool CalorieList::isValid()const {
		bool ok = (!(m_items == nullptr)) && (m_itemsAdded >= m_noOfItems);

		for (int i = 0; i < m_itemsAdded && ok; i++) {
			if (!m_items[i].isValid()) {
				ok = false;
				i = m_itemsAdded;
			}
		}
		return ok;
	}

	//Returns the total amount of consumed calories
	int CalorieList::totalCalories()const {
		int total = 0;
		for (int i = 0; i < m_itemsAdded; i++)
		{
			total += m_items[i].kcals();
		}
		return total;
	}

	
	//set a tamplate for a title of the list, if all items in the list are valid will print the title name, if not will print invalid message.
	//will print a header of the report 
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "| " << left << setw(50) << " Daily Calorie Consumption" << " |" << endl;

		}
		else {
			cout << "| " << left << setw(50) << "Invalid Calorie Consumption list" << " |" << endl;
			
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}    

	//sets a tamplate of the footer, if all items in the list are valid will print the total calories for the day, if not will print invalid message.
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
		cout << "|" << std::setw(19) << left << "    Total Calories for today:" << setw(9) << right << fixed << totalCalories() << " | " << setw(12) << "|" << endl;
		}
		else {
			cout << "| " << left << setw(50) << "   Invalid Calorie Consumption list" << " |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}


	// sets the CalorieList to accept the "size" number of Food Items. 
	// This function is called to prepare the CalorieList for accepting food items
	void CalorieList::init(int size) {
		if (!(size <= 0)) {
			m_noOfItems = size;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
		else {
			setEmpty();
		}
	}


	// Adds Food Items using their Name, Calorie count and time of consumption up to 
	// the number set in the init() function, returns true if successful.
	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool ok = false;
			if (m_itemsAdded < m_noOfItems)
			{			
				m_items[m_itemsAdded].set(item_name, calories, when);
				m_itemsAdded += 1;
				ok = true;
			}
			return ok;	
	}

	// Displays the report with food information and the total calorie consumed in the day
	// as shown in the report sample
	void CalorieList::display()const {
		Title();
		 for (int i = 0; i < m_noOfItems; i++)
		  {
			 m_items[i].display();
		  }
		footer();
	}

	// Releases all the memory used. After this function init() can be called for another
	// report;
	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}