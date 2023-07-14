/*/////////////////////////////////////////////////////////////////////////
					   OOP244 Workshop - #4 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip> 

#include "cstring.h"
#include "Canister.h"

#define PI 3.14159265
#define SMALL_H 10.0
#define LARGE_H 40.0
#define SMALL_D 10.0
#define LARGE_D 30.0


	
using namespace std;

namespace sdds {
	/*========================Private methods (member functions)=============================
	
		- this function sets the attributes to their default values.
		- It sets the content name pointer to null, 
		- height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.*/
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	//	Returns true is the content volume is less than 0.00001 CCs.
	bool Canister::isEmpty()const {
		return m_contentVolume < 0.00001;
	}

	/*	Compares the content name of this Canister with the one received from the argument C.
		Using strCmp in cstring.h, it returns true if both content names are not null and are identical. Otherwise, it returns false;
	*/
	bool Canister::hasSameContent(const Canister& C) const {
		if (m_contentName != nullptr && C.m_contentName != nullptr) {
			return strCmp(m_contentName, C.m_contentName) == 0;
		}
		else {
			return false;
		}
		
	}

	/*Sets the content name of the current Canister.
	If the incoming Cstr is not null and the Canister is usable, it will delete the current content name, 
	allocate memory to the length of Cstr(+1 for null) and copies the Cstr into the newly allocated memory.
	Otherwise, it will silently do nothing.*/
	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && Cstr[0] != '\0' && m_usable) {
			delete [] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
		else {
			;//do nothing 
		}
	}

	//================================Constructors=======================================
	/*No argument Constructor (defualt)
	 - Sets the attributes to their default values
	*/
	Canister::Canister() {
		setToDefault();
	}

	/*One argument Constructor:
		- Sets the attributes to their default values(note: reuse code)
		- Sets the Name to the incoming contentName argument.
	*/
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);	
	}

	/*Sets the attributes to their default values.
     If the dimensions are within acceptable values :
    it will set the m_heightand m_diameter to the corresponding argument values
    it will set the content volume to 0.
	it will set the content name to the corresponding argument value.
	If any of the dimensions have invalid values, it will set the Canister unusable*/
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= SMALL_H && height <= LARGE_H && diameter >= SMALL_D && diameter <= LARGE_D) {
			m_diameter = diameter;
			m_height = height;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	//=======================The Destructor==================================================
	//Deallocates the dynamic memory pointed by the content name attribute.
	Canister::~Canister(){
		clear();
	}

	//==Public Methods (member variables)
	/*Clears an unusable Canister back to an empty Canister by:
    deallocating the memory pointed by the content name attribute
    sets the content name attribute to nullptr
    sets the content volume attribute to 0.0
    set the usable flag attribute to true
    */
	void Canister::clear() {
		delete[] m_contentName;
		setToDefault();
	}

	//returns the capacity as stated in Calculating the capacity
	double Canister::capacity() const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	//returns the content volume attribute
	double Canister::volume()const {
		return m_contentVolume;
	}

	/*It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this):
	If the contentName argument is null it will render the Canister unusable
	else if the Canister is empty it will set the Name to the value pointed by the argument
	else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.*/
	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr || contentName[0] == '\0') {
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (!hasSameContent(contentName)) {
			m_usable = false;
		}
		return *this;
	}

	/*Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister. 
	Otherwise, it will render the Canister unusable and then returns the reference of the current object.
	Use this rule to accomplish the above:
	If the Canister is usable and the quantity is more than zero 
	and if the sum of the quantity and the volume() is less than or equal to the capacity(), 
	add the quantity to the content volume,
	otherwise set usable flag attribute to false.*/
	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0 && (volume() + quantity) <= capacity()) {
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		return *this;
	}


	/*Pours the content of the Canister argument into the current Canister following the Specs stated at the top
	Set the content name to the Canister argument using setContent().
	if the volume() of the argument is greater than the capacity() minus the volume()
	Reduce the content volume of the argument by capacity() minus volume() and then set the content volume to capacity()
	else pour the content volume of the argument using pour() method and set the content volume of the argument to 0.0.
	return the reference of the current object at the end.*/
	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.volume() > capacity() - volume()) {
			C.m_contentVolume -= capacity() - volume();
			m_contentVolume = capacity();
		}
		else {
			pour(C.volume());
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	//Prints all the number values with one digit after the decimal point.
	ostream& Canister::display() const {
		cout << setw(7) << right << setprecision(1) << fixed << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			cout << " of " << setw(7) << setprecision(1) << volume() << "cc   " << m_contentName;
		}
		return cout;
	}

}