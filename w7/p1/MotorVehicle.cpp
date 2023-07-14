/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 7 - lAB
 MotorVehicle Module
 File	MotorVehicle.cpp
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

#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds {


    //default
    MotorVehicle::MotorVehicle() {
        m_makeYear = 0;
    }

    // A custom constructor that receives as parameters the license plate number and the year when the vehicle was built.
    // Set the location of the vehicle at Factory. Assume all data is valid.
    MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
        strnCpy(m_licensePlate, licensePlate, sizeof(m_licensePlate) - 1); //copy licensePlate number, make sure it won't overfllow the array of m_licensePlate
        strCpy(m_currentLocation, "Factory");
        m_makeYear = year;
    }

    // Moves the vehicle to the new address if the new address is different from the current address.
    // Prints to the screen the message.
    void MotorVehicle::moveTo(const char* address) {
        if (strCmp(m_currentLocation, address) != 0) {
            //Prints to the screen the message
            //|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
            cout << "|" << setw(8) << setfill(' ') << right << m_licensePlate << "| |" << setw(20) << setfill(' ') << right << m_currentLocation << " ---> " << setw(20) << setfill(' ') << left << address << "|" << endl;
            int currLocSize = sizeof(m_currentLocation) - 1;
            if (strLen(address) >= currLocSize) { //checking if address is bigger than the location array
                strnCpy(m_currentLocation, address, currLocSize); //if it is bigger copy up to the size of the array 
                m_currentLocation[currLocSize] = '\0';  // Add null terminator explicitly
            }
            else {
                strCpy(m_currentLocation, address); //if address is in the range of the array copy it
            }
        }
    };


    //a query that inserts into os the content of the object in the format
    std::ostream& MotorVehicle::write(std::ostream& os) const{
        //| [YEAR] | [PLATE] | [ADDRESS]
        os << "|" << setw(5) << setfill(' ') << right << m_makeYear << " | " << setw(5) << setfill(' ') << right << m_licensePlate << " | " << setw(5) << setfill(' ') << right << m_currentLocation;
        return os;
    }

    //a mutator that reads from the stream in the data for the current object
    std::istream& MotorVehicle::read(std::istream& in) {
        // Built year: [USER TYPES HERE]
       do{
            cout << "Built year: ";
            cin >> m_makeYear;
            if (m_makeYear > CURRENT_YEAR || m_makeYear < FIRST_CAR) {
                m_makeYear = 0;
                cout << "Error Invalid Year"<<endl;
            }
       } while (m_makeYear == 0);
       
        // License plate: [USER TYPES HERE]
        cout << "License plate: ";
        cin.ignore(); // clear buffer
        cin.getline(m_licensePlate, sizeof(m_licensePlate));

        // Current location: [USER TYPES HERE]
        cout << "Current location: ";
        cin.getline(m_currentLocation, 63);

        return in;
    }
    //-----Helper Functions-------//
   //overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream. 
   //These operators should call the write/read member functions in the class MotorVehicle.
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& RO)
    {
        return RO.write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& RO)
    {
        return RO.read(is);
    }

}

