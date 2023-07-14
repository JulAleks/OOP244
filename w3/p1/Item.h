/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #3 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  2023-05-31
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
    private:
        char m_itemName[21];
        double m_price;
        bool m_taxed;

        void setName(const char* name);

    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        double price() const;
        double tax() const;
        bool isValid() const;
        void display() const;
    };
}

#endif // !SDDS_SUBJECT_H
