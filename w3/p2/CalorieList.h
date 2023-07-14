/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 2)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {

	class CalorieList {
		Food* m_items;
		int m_noOfItems;
		int m_itemsAdded;

		void setEmpty();
		bool isValid()const;
		int totalCalories()const;
		void Title()const;
		void footer()const;

	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();

	};

}
#endif // #endif // SDDS_CALORIELIST_H_
