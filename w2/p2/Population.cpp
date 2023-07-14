/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #2 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-26
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h" 
using namespace std;
namespace sdds {
    int noOfPeople;
    Population *canPopulation;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPeople - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (canPopulation[j].resident > canPopulation[j + 1].resident) {
                    temp = canPopulation[j+1];
                    canPopulation[j+1] = canPopulation[j];
                    canPopulation[j] = temp;
                 
                }
            }
        }
        
    }

    bool load(struct Population& canPopulation) {
        bool ok = false;
        char postalCodeTemp[128];
        if (read(postalCodeTemp) && read(canPopulation.resident)) {
            canPopulation.postalCode = new char[strLen(postalCodeTemp) + 1];
            strCpy(canPopulation.postalCode, postalCodeTemp);
            ok = true;
        }
        else {
            ok = false;
        }
        return ok;
    }



    bool load(const char fileName[]) {
        bool ok = false;
        int i = 0;
        if (openFile(fileName)) {

            noOfPeople = noOfRecords();
            canPopulation = new Population[noOfPeople];

            for (i = 0; i < noOfPeople; i++) {
                if (load(canPopulation[i])) {
                    ok = true;
                }
                else
                {
                    ok = false;
                    cout << "Error: Incorrect number of records read; the data is possibly corrupted." << endl;
                }
            }
          
            closeFile();
        }
        else {
            cout << "Could not open data file: " << fileName << endl;
        }
        return ok;
    }
    int totalPopulation(const Population& canPopulation) {
        int totalResident = canPopulation.resident;
        return totalResident;
    }

    int totalPopulation() {
        int  totalResident = 0;
        for (int i = 0; i < noOfPeople; i++) {
            totalResident += totalPopulation(canPopulation[i]);
        }
        return  totalResident;
    }

    void display(struct Population& canPopulation) {
        cout << canPopulation.postalCode << ":  " << canPopulation.resident << endl;
    } 
    
    void display() {
        sort();   
        cout << "Postal Code: population" << endl; 
        cout << "-------------------------" << endl;
        for (int i = 0; i < noOfPeople; i++) {
            cout << i + 1 << "- ";
            display(canPopulation[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation() << endl;
    }
    void  deallocateMemory() {
        int i;
        for (i = 0; i < noOfPeople; i++) {
            delete[] canPopulation[i].postalCode;
            canPopulation[i].postalCode = nullptr;
        }
        delete[]  canPopulation;
        canPopulation = nullptr;
    } 
}
