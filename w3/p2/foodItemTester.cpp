/***********************************************************************
  THIS IS A TESTER FUNCTION TO TEST THAT FOOD.CPP IS WORKING PROPERLY
  OOP244 Workshop - #3 (PART 2)
  Student Name: Julia Alekseev
  Student ID#:  051292134
  Email      :  jalekseev@myseneca.ca
  Section    :  NEE
  Date:      :  2023-05-31
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************/


#include "Food.h"
using namespace sdds;

int main() {
	Food A;
	A.setEmpty();
	A.display();
	A.set("Apple", 52, 4); //valid
	A.display();
	A.set("Pineapple", 30, 0);//invalid time
	A.display();
	A.set("Banana", 0, 3);//invalid calories low
	A.display();
	A.set("Banana", 3001, 2);//invalid calories high
	A.display();
	A.set("", 10, 3);//invalid name
	A.display();

	return 0;
}


/*
Output:
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxxxxxxxxx |
| Apple............... |      52 | Snack      |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxxxxxxxxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxxxxxxxxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxxxxxxxxx |
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxxxxxxxxx |
*/


