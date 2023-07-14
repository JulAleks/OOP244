/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 7 - lAB
 MotorVehicle Module
 File	MotorVehicle.h
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

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H


#define CURRENT_YEAR 2024
#define FIRST_CAR 1886
namespace sdds {

    class MotorVehicle {
        char m_licensePlate[9]{}; // A license plate number as a statically allocated array of characters of size 9.
        char m_currentLocation[64]{}; // The address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
        int m_makeYear; // The year when the vehicle was built.

    public:
        //default
        MotorVehicle();

        // A custom constructor that receives as parameters the license plate number and the year when the vehicle was built.
        // Set the location of the vehicle at Factory. Assume all data is valid.
        MotorVehicle(const char* licensePlate, int year);

        // Moves the vehicle to the new address if the new address is different from the current address.
        // Prints to the screen the message.
        void moveTo(const char* address);

        //a query that inserts into os the content of the object in the format
        std::ostream& write(std::ostream& os) const;


        //a mutator that reads from the stream in the data for the current object
        std::istream& read(std::istream& is = std::cin);
    };
    //-----Helper Functions-------//
        //overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream. 
        //These operators should call the write/read member functions in the class MotorVehicle.
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& RO);
    std::istream& operator>>(std::istream& is, MotorVehicle& RO);
}

#endif
