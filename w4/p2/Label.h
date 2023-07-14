/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #4 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>
#include <iomanip>

namespace sdds {
	class Label {
	private:
		char* m_labelName; // points to a dynamically allocated Cstring of the name of the label
		char m_labelPattern[9]; // contains the pattern of a label, no need for dynamic memory as we are printing a rectangle that can contain only 8 characters. 4 per each corner and 4 per walls/roof/base
		void setToDefault(); 
		void setName(const char* Cstr);
		void setPattern(const char* Cstr);

	public:
		Label(); 
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel() const;
	};
}

#endif // !SDDS_LABEL_H

