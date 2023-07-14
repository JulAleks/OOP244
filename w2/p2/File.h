/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #2 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-26
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char* postalCode);
   bool read(int& resident);

}
#endif // !SDDS_FILE_H_

