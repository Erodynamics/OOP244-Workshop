#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Food {
        char foodName[31];
        int calories;
        int meal;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int meal);
        void display()const;
        bool isValid()const;
        int getCalories()const;
        int getMeal ()const;
    };
}

#endif // !SDDS_SUBJECT_H
