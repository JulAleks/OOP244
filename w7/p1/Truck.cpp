/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 7 - lAB
 Truck Module
 File	Truck.cpp
 Version 1.0
 Date 2023-07-11
 Author	Julia Alekseev
 Student ID 051292134
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip> 

#include "Truck.h"

using namespace std;

namespace sdds {

	//a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address. 
	Truck::Truck(const char* plate, int year, double cap, const char* address)
		: MotorVehicle(plate, year), m_capacity(cap), m_currentCargo(0)
	{
		if (plate != nullptr && address != nullptr && cap && year)
		{
			MotorVehicle::moveTo(address);
		}
	}


	//a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. Do not exceed the capacity! If the current load has been changed, return true, otherwise return false.
	bool Truck::addCargo(double cargo) {
		bool ok = false;
		if (cargo > 0 && m_currentCargo != m_capacity) {
			m_currentCargo += cargo;
			ok = true;
			m_currentCargo = (m_currentCargo > m_capacity) ? m_capacity : m_currentCargo;
		}
		return ok;
	}


	// a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
	bool Truck::unloadCargo() {
		bool ok = false;
		if (m_currentCargo != 0) {
			m_currentCargo = 0;
			ok = true;
		}
		return ok;
	}

	
	//a query that inserts into os the content of the object in the format
	ostream& Truck::write(ostream& os) {
		MotorVehicle::write(os);
		os << " | " << right << m_currentCargo << "/" << m_capacity;

		return os;
	}

	//a mutator that reads from the stream in the data for the current object
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		cin >> m_capacity;
		cout << "Cargo: ";
		cin >> m_currentCargo;

		return in;
	}

	//-----Helper Functions-------//
  // overload the insertionand extraction operators to insert a Truck into a streamand extract a Truck from a stream.
   //These operators should call the write / read member functions in the class Truck.
	std::ostream& operator<<(std::ostream& os, Truck& rhs) {
		return rhs.write(os);
	}

	std::istream& operator>>(std::istream& is, Truck& rhs) {
		return rhs.read(is);
	}
}