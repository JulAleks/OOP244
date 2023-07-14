/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds {
	//Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	//Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
	bool Bill::isValid() const {
		bool ok = (!(m_title[0] == '\0' || m_items == nullptr)) && (m_itemsAdded >= m_noOfItems);

		for (int i = 0; i < m_itemsAdded && ok; i++) {
			if (!m_items[i].isValid()) {
				ok = false;
				i = m_itemsAdded;
			}
		}
		return ok;
	}

	//Adds all the taxes of the items using a loopand returns the sum
	double Bill::totalTax()const {
		double tax = 0.0;
		for (int i = 0; i < m_itemsAdded; i++)
		{
			tax += m_items[i].tax();
		}
		return tax;
	}

	//Adds all the prices of the items using a loop and returns the sum; 
	double Bill::totalPrice() const {
		double price = 0.0;
		for (int i = 0; i < m_itemsAdded; i++)
		{
			price += m_items[i].price();
		}
		return price;
	}

	//Prints the title: 
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| " << left << setw(36) << m_title << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	//Prints the footer
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << right << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	/*If any of the arguments are invalid, it will set the Bill to an empty state (ie. title is null or noOfItems is zero or less)
	Otherwise, if the incoming arguments are valid:
    init() function will first set the m_noOfItems member variable to the incoming corresponding argument and sets m_itemsAdded to zero.
    Next, it will copy the Cstring pointed by the title argument into m_title attribute up to 36 characters
    Then it will dynamically allocate an array of Items pointed by m_items member variable. The length of this array will be m_noOfItems.
	 Make sure all the dynamically allocated Items are set to empty
	 */
	void Bill::init(const char* title, int noOfItems) {
		if (title==nullptr || noOfItems<=0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_title[36] = '\0';
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}	
		}
	}

	//If the number of added Items (m_itemsAdded) is less than the length of the m_items array, 
	//this function will set the next available subject to the incoming argument values. Then it will add one to the m_itemsAdded and return true;
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool ok = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			ok = true;
		}
		return ok;
	}

	//This function will first print the title(), then it will loop through the m_items elements, printing every one of them, and finally prints the footer(). This function can not modify the Bill. 
	void Bill::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}

		footer();
	}

	//Deallocates the m_items arrays and sets the pointers to null.
	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}