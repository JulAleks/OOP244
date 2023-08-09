/*------------------------------------------------------------------
 Final Project Milestone 5
 Publication Module
 File	Publication.cpp
 Version 1.0
 Date 2023-08-01
 Author	Julia Alekseev
 Student ID 051292134
 Section NEE
 Revision History
 -----------------------------------------------------------
 Name            Date            Reason
Julia Alekseev   2023-07-24		 Original version
Julia Alekseev   2023-08-01      Updated setRef to accept 0 as valid
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
------------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <iomanip>
#include <cstring>

#include "Publication.h"

using namespace std;

namespace sdds {

    //safe state
    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    // Constructor(default) - Sets all the attributes to their default values.
    Publication::Publication() {
        setDefault();
    }
  
    // Destructor
    Publication::~Publication() {
        delete[] m_title;
        setDefault();
    }
        
    // Sets the membership attribute to either zero or a five-digit integer.
    void Publication::set(int member_id) {
        if (member_id >= 10000 && member_id <= 99999) {
            // If the membership number is a five-digit number, it means the publication is checked out by the member holding that membership number.
            m_membership = member_id;
        }
        else if (member_id == 0) {
       // In this class, if the membership number is '0', it means the publication is available and is not checked out by any members.
          m_membership = member_id;
        }
    }

    //Sets the libRef attribute value
    void Publication::setRef(int value) {
        // This serial number is used internally to uniquely identify each publication in the system.
      if (value >= 0 && m_libRef != value) { // checks it is a positive number and not the same as the current value
        m_libRef = value;
      }
    }

    // Sets the date to the current date of the system.
    void Publication::resetDate() {
        m_date = Date();
    }

    // Queries
   // Returns the character 'P' to identify this object as a "Publication object"
    char Publication::type() const {
        return 'P';
    }

    // Returns true if the publication is checked out (membership is non-zero)
    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    // Returns the date attribute
    Date Publication::checkoutDate() const {
        return m_date;
    }

    // Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)
    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    // Returns the title attribute
    Publication::operator const char* () const {
        return m_title;
    }

    // Returns the libRef attribute.
    int Publication::getRef() const {
        return m_libRef;
    }
    // Streamable pure virtual function implementations
     // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
    bool Publication::conIO(ios& io) const {
        return (&io == &cin || &io == &cout);
    }

    // If the os argument is a console IO object (use conIO()), print shelfId, title, membership, and date attributes in the following format (title is left-justified padded with dots)
    ostream& Publication::write(ostream& os) const {
        char tempTitle[SDDS_TITLE_WIDTH + 1] = { 0 };
        strncpy(tempTitle, m_title, SDDS_TITLE_WIDTH);

        if (conIO(os)) {
            os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << tempTitle << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            os << type();
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            os << m_membership;
            os << "\t" << m_date;
        }

        return os;
    }


    //Read all the values in local variables before setting the attributes to any values
    std::istream& Publication::read(std::istream& is) {
        // Temporary variables
        char tempTitle[256]{};
        char tempShelfId[SDDS_SHELF_ID_LEN + 1]{};
        int tempLibRef = -1;
        int Tempmembership = 0;
        Date tempDate;

        // Clearing the memory if it is allocated and setting the values to default
        if (m_title) {
             setDefault(); 
        }

        // Then, if the istr argument is a console IO object (use conIO()), read the attributes as follows:
        if (conIO(is)) {

            // Prompt: "Shelf No: "
            cout << "Shelf No: ";
            // Read the shelf number up to its limit (see Lib.h).
            is.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);

            //if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
            if (strlen(tempShelfId) != SDDS_SHELF_ID_LEN) {
                is.setstate(ios::failbit);
            }

            // Prompt: "Title: "
            cout << "Title: ";
            // Read the title
            is.getline(tempTitle, 256);

            // Prompt: "Date: "
            cout << "Date: ";
            //Read date
            is >> tempDate;
        }

        //Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.
        else {

            //read the libRef number
            is >> tempLibRef;

            //skip the tab
            is.ignore();

            //read the shelf number
            is.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');

            //read the title 
            is.getline(tempTitle, 256, '\t');

            //read the membership
            is >> Tempmembership;

            //skip the tab
            is.ignore();

            //read the date
            is >> tempDate;

        }

        //Either way if the date is in an invalid state set the istr to a fail state manually
        if (!tempDate) {
            is.setstate(ios::failbit);
        }

        //After the process of reading is done if istr is in a valid state:
        if (is) {
            //Dynamically store the title into the title attribute
            m_title = new char[strlen(tempTitle) + 1];

            //copy the shelf id into the shelfId attribute
            strcpy(m_title, tempTitle);
            strcpy(m_shelfId, tempShelfId);

            //set the membership
            m_membership = Tempmembership;

            //set the date
            m_date = tempDate;

            //set the libRef attribute
            m_libRef = tempLibRef;
        }
        //At the end return the istr argument.
        return is;
    }

    // Returns true if neither of the title or shelfId attributes is null or empty.Otherwise, it will return false.
    Publication::operator bool() const {
       return (m_title != nullptr && m_title[0] != '\0');
    }


    //The Rule of three
    //Make sure this object complies with the guidelines of the Rule of three so the copyingand assignmentand destruction are done safelyand without any memory leak.

    Publication::Publication(const Publication& Pub) {

        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
       
        m_title = new char[strlen(Pub.m_title) + 1];
        strcpy(m_title, Pub.m_title);  

        strcpy(m_shelfId, Pub.m_shelfId); 

        m_membership = Pub.m_membership;
        m_date = Pub.m_date;
        m_libRef = Pub.m_libRef;
    }


    Publication& Publication::operator=(const Publication& Pub) {
        if (this != &Pub) {

            if (m_title) {
                delete[] m_title;
                m_title = nullptr;
            }

            set(Pub.m_membership);
            setRef(Pub.m_libRef);
            strcpy(m_shelfId, Pub.m_shelfId);
            m_date = Pub.m_date;

            if (Pub.m_title != nullptr && Pub.m_title[0] != '\0') {
                m_title = new char[strlen(Pub.m_title) + 1];
                strcpy(m_title, Pub.m_title);
            }
            else {
                m_title = nullptr;
            }
        }
        return *this;
    }



}