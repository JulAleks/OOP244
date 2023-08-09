/*------------------------------------------------------------------
 Final Project Milestone 5
 Lib Module
 File	Lib.h
 Version 1.0
 Date 2023-08-02
 Author	Julia Alekseev
 Student ID 051292134
 Section NEE
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason
  Julia Alekseev		2023-07-11		 Original version
  Julia Alekseev		2023-07-30		 MS5 updates
  Julia Alekseev		2023-08-02		 MS5 updates
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

//Create a header file called "Lib.h" to hold all the general values of the system. Add the following and any other general values you find necessary to this header file. This header file should be included anywhere any of these values are needed. 
#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds {
    //the max size of a fule name
    const int SDDS_MAX_FILENAME = 256;

    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty

    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console

    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console

    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console

    const int SDDS_LIBRARY_CAPACITY = 333;
    // Maximum number of publications the library can hold.


}

#endif //!SDDS_LIB_H_