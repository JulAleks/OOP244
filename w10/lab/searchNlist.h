/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #10 (PART 1-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  July 31, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNIST_H_

namespace sdds {

    //Have a comment section for both functions and explain what requirements each of types of your templates must have to be able to work with your logic.


    /*
    Template type requirements: search
    -----------------------------------
    This fucntion accepts a reference to an object and an array, goes through the arry and tries to match a key vlue in the arry.
    If it finds it, the function will return true, if not will return false.

    Each template must use a key word to create a function template "template".
    In the search template we must have a refference to an object, a refferance to an array, a key value.
    As well an size veriable the MUST always be an int
    */

    template <typename T, typename T1>

    //A reference to a Collection of templated objects (template type 1).
    //An array of templated objects; the same type as the Collection type
    //Number of elements in the array of objects
    //A key templated value to search for, in the array of objects. (template type 2)
    bool search(Collection<T>& myObj, const T* myArr, int size, T1 myKey) {
        bool ret = false;

        //The search function template returns a bool that is true only if at least one match to the key is found in the array of objects and false otherwise. 
        for (int i = 0; i < size; i++) {

            //The search function goes through all the elements of the array of objects and adds all the matches found to the Collection. (use the "==" operator to check for a match between the objects and the key) 
            if (myArr[i] == myKey) {
                ret = true;
              myObj.add(myArr[i]);
            }
        }
        return ret;
    }



    /*
    Template type requirements: listArrayElements
    ----------------------------------------------
    This function will print the a title.
    Then it will print a line number (i+1) and the value of the array in index #i.

    Each template must use a key word to create a function template "template".
    In the listArrayElements template we must have a refference to a title and a refferance to an array.
    As well an size veriable the MUST always be an int
    */
    template <typename T1>

    //A const char* for a Title to be printed as the Title of the list.
   //A constant array of templated objects(template type)
  //The number of the elements of the array.
    void listArrayElements(const char* title, const T1* myArr, int size) {
        //This function first prints the Title and then goes to newline.
       std:: cout << title << std::endl;


        for (int i = 0; i < size; i++) {
            //Then it will print the row number and then insert each element of the array into cout with a newline attached.
            std::cout << i + 1 << ": " << myArr[i] << std::endl;
        }
    }
}
#endif // !SEARCHNIST_H_

