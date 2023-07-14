/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 2)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {

	class Food {
		char f_foodName[30];
	    int f_kcals;
		int f_timeOfConsumption;
		void setFoodName(const char* food);
	public:
		void setEmpty();
		void set(const char* food, int kcals, int time);
		int kcals() const;
		int timeOfComsumption() const;
		bool isValid() const;
		void display() const;
		
	};
}
#endif // !SDDS_TRANSCRIPT_H
