#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* foods;
        int m_noOfItems;
        int m_itemsAdded;
        int totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfItems);
        bool add(const char* food_name, int cal, int mealCode);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
