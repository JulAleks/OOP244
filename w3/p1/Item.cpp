/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include<cstring>
#include "Item.h"
using namespace std;

namespace sdds {
	//This function sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters. 
	void Item::setName(const char* name) {
		if (name != nullptr && name[0] != '\0') {
			strncpy(m_itemName, name, 20);
			m_itemName[20] = '\0';

		}
	}

	//Sets the Item to a recognizable safe Empty State. Do this by setting the price to an impossible value like 0.0 and setting the m_itemName to a blank string (first character set to null). 
	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
		m_taxed = false;
	}
	//Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method and sets the m_price and m_taxed attributes to the corresponding arguments.
	//If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state(safe empty state).
	void Item::set(const char* name, double price, bool taxed) {
		if (price > 0 && name &&  name != nullptr) {

			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else {
			setEmpty();
		}
	}

	//Returns the m_price attribute;
	double Item::price() const {
		return m_price;
	}

	//Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns 0.0 if the m_taxed is false.

	double Item::tax() const
	{
		double returnPrice = 0.0;
		const double tax = 0.13;
		if (m_taxed) {
			returnPrice = m_price * tax;
		}
			return returnPrice;
	}

	//Returns true if the Item is not set to the empty state (As done in setEmpty function) .This function can not modify its owner.
	bool Item::isValid()const {
		bool ok = false;
		if (m_itemName[0] != '\0') {
			ok = true;
		}
		return ok;

	}

	//Prints an item in the following format.If the Item is valid :
	void Item::display()const {
		if (isValid()) {
			cout << "| " << left << setw(20) << setfill('.') << m_itemName;
			cout << " | " << right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price;
			cout << setfill(' ') << " | " << (m_taxed ? "Yes |" : "No  |")<<endl;
			
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

}