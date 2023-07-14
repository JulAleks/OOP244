/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #3 (PART 2)
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
#include "Food.h"

using namespace std;

namespace sdds {

	//setting the food name up to 30 characters if the passed value is not null 
	void Food::setFoodName(const char* food) {
		if (food != nullptr && food[0] != '\0') {
			strnCpy(f_foodName, food, 30); 
			f_foodName[30] = '\0';
		}
	}

	//Sets the Food items in the class to a recognizable safe Empty State. 
	void Food::setEmpty()
	{
		f_foodName[0] = '\0';
		f_kcals = 0;
		f_timeOfConsumption = 0;
		
	}
	
	//Sets the Food attributes to the corresponding to arguments if they are valid, in not will set to an empty state.
   //VALID: food not NULL, kcals between 0 and 3000 calories (including 3000), timeofConsumption; values 1, 2, 3 or 4
	void  Food::set(const char* food, int kcals, int time) {
		if (food != nullptr && kcals > 0 && kcals <= 3000 && (time >= 1 && time <= 4)) {
			setFoodName(food);
			f_kcals = kcals;
			f_timeOfConsumption = time;
		}
		else {
			setEmpty();
		}
	}

	//returns number of calories 
	int Food::kcals() const {
		return f_kcals;
	}

	//returns the time of consumption
	int Food::timeOfComsumption() const {
		return f_timeOfConsumption;
	}

	//checks that food items are valid, if they are, returns true
	bool Food::isValid() const{
		bool ok = false;
		if (f_foodName[0]!='\0') {
			ok = true; 
		}
		return ok;
	}

	//displays food items, food name, amount of calories, and if the meal was breakfast, lunch, dinner or snack 
	void Food::display() const {
		char mealTime[10];
		if (isValid()) {
			switch (timeOfComsumption()) {
			case 1:
				strCpy(mealTime, "Breakfast");
				break;
			case 2:
				strCpy(mealTime, "Lunch");
				break;
			case 3:
				strCpy(mealTime, "Dinner");
				break;
			default:
				strCpy(mealTime, "Snack");
				break;
				}

			cout << "| " << left << setw(30) << setfill('.') << f_foodName;
			cout << " | " << right << setw(4) << setfill(' ') << fixed << f_kcals<< " | ";
			cout << left<< setw(10)<<setfill(' ') << mealTime <<" |" << endl;
		}
		else {
			cout<<"| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

}