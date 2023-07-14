/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #2 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-26
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct Population {
        char *postalCode; 
        int resident;
    };

    void sort();
    bool load(Population & canPopulation);
    bool load(const char fileName[]);
    int totalPopulation(const Population& canPopulation);
    int totalPopulation();
    void display(const Population& canPopulation);
    void display();
    void  deallocateMemory();
}
#endif // SDDS_POPULATION_H_