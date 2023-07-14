/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #4 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 8, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> 
#include "Label.h"
#include "cstring.h"



using namespace std;

namespace sdds {
	//sets the label to default
	void Label::setToDefault() {  
		m_labelName = nullptr;
		strCpy(m_labelPattern, "+-+|+-+|");
	}

	//sets the pattern of the label
	void Label::setPattern(const char* Cstr) { 
		strCpy(m_labelPattern, Cstr);
	}

	//sets the label name, if the sting is not empty, allocate the proper size for the name
	void Label::setName(const char* Cstr) {
		if (Cstr != nullptr && Cstr[0] != '\0') { 
			delete[] m_labelName;
			m_labelName = new char[strLen(Cstr) + 1];
			strCpy(m_labelName, Cstr);
		}
	}

	// Creates an empty label and defaults the frame to "+-+|+-+|"
	Label::Label() {
		setToDefault();
	}

    //Creates an empty label and sets the frame to the frameArg argument.
	Label::Label(const char* frameArg) {
		setToDefault();
		setPattern(frameArg);
	}

	//Creates a Label with the frame set to frameArgand the content of the Label set to the corresponding argument.
	//Note that you must keep the content dynamically even though it should never be more than 70 characters.
	Label::Label(const char* frameArg, const char* content) {
		setToDefault();
		setPattern(frameArg);
		if (content != nullptr && content[0] != '\0') {
			int len = strLen(content);
			if (len > 70) {
				len = 70; // Limit the length to 70 characters
			}
			m_labelName = new char[len + 1];
			strnCpy(m_labelName, content, len);
			m_labelName[len] = '\0'; // Null-terminate the string
		}
		else {
			m_labelName = nullptr;
		}
	}
	

	//Makes sure there is no memory leak when the label goes out of scope
	Label::~Label() {
		delete[] m_labelName;
	}


   //Reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample
	void Label::readLabel() {
		char input[80]; //allowing a bigger input incase someone enters a bigger string 

		cin.getline(input, 79);
		cin.clear(); //clearing the buffer

		if (strLen(input) > 70) {
			input[70] = '\0';// Null-terminate the string at 70
		}

		setName(input); //setting the name of the label
	}

	ostream& Label::printLabel() const {
		if (m_labelName != nullptr) {   //if the label is not eampty print it
			
			int labelLength = strLen(m_labelName); //check the size of the label that is needed
			
			// Print the Top line
			cout << m_labelPattern[0];
			for (int i = 0; i < labelLength + 2; i++) {
				cout << m_labelPattern[1];
			}
			cout << m_labelPattern[2] << endl;

			// Print the label and line
			cout << m_labelPattern[7] << setw(labelLength + 2) << right << " " << m_labelPattern[3] << endl;
			cout << setw(2) << left << m_labelPattern[7] << m_labelName << setw(2) << right << m_labelPattern[3] << endl;
			cout << m_labelPattern[7] << setw(labelLength + 2) << right << " " << m_labelPattern[3] << endl;

			// Print the bottom border
			cout << m_labelPattern[6];
			for (int i = 0; i < labelLength + 2; i++) {
				cout << m_labelPattern[5];
			}
			cout << m_labelPattern[0];
		}
		else {
			;    //if the label is empty skip
		}
		return cout;
	}
}
	