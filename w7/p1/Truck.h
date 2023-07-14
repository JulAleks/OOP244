/*------------------------------------------------------------------
 Intro. to Object Oriented Programming
 Workshop 7 - lAB
 Truck Module
 File	Truck.h
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

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"


namespace sdds {


    //Design and code a class named Truck that holds information about a motor vehicle that can carry cargo. This class should inherit from MotorVehicle class.
    class Truck : public MotorVehicle {
        //a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
        double m_capacity;

        //the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.
        double m_currentCargo;
    public:
        //a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address. 
        Truck(const char *plate, int year, double cap, const char * address);

        //a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. Do not exceed the capacity! If the current load has been changed, return true, otherwise return false.
        bool addCargo(double cargo);


        // a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
        bool unloadCargo();

        //a query that inserts into os the content of the object in the format
        std::ostream& write(std::ostream& os);
    
        //a mutator that reads from the stream in the data for the current object
        std::istream& read(std::istream& in);
    };

    
    //-----Helper Functions-------//
   // overload the insertionand extraction operators to insert a Truck into a streamand extract a Truck from a stream.
    //These operators should call the write / read member functions in the class Truck.
    std::ostream& operator<<(std::ostream& os, Truck& RO);
    std::istream& operator>>(std::istream& is, Truck& RO);

}

#endif