#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CalorieList.h"
namespace sdds {

	// Food Class contains:
	// char m_title[37]
	// Item* m_items
	// int m_noOfItems
	// int m_itemsAdded

	int CalorieList::totalCal() const {
		int totalCalories = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalCalories += foods[i].getCalories();
		}
		return totalCalories;
	}

	void CalorieList::Title() const {
		if (isValid()) {
			std::cout << "+----------------------------------------------------+" << std::endl;
			std::cout << "|  Daily Calorie Consumption                         |" << std::endl;

		} else {
			std::cout << "+----------------------------------------------------+" << std::endl;
			std::cout << "| Invalid Calorie Consumption list                   |" << std::endl;
		}
		std::cout << "+--------------------------------+------+------------+" << std::endl;
		std::cout << "| Food name                      | Cals | When       |" << std::endl;
		std::cout << "+--------------------------------+------+------------+" << std::endl;
	}

	void CalorieList::footer() const {
		std::cout << "+--------------------------------+------+------------+" << std::endl;
		if (isValid()) {
			std::cout << "|    Total Calories for today: ";
			std::cout << std::right; std::cout.width(8);
			std::cout << totalCal() << " |            |" << std::endl;
		} else {
			std::cout << "|    Invalid Calorie Consumption list                |" << std::endl;
		}
		std::cout << "+----------------------------------------------------+" << std::endl;

	}

	void CalorieList::setEmpty() {
		foods = nullptr;
		m_noOfItems = 0;
		m_itemsAdded = 0;
	}

	bool CalorieList::isValid() const {
		bool valid = true;
		for (int i = 0; i < m_noOfItems; i++) {
			if (!foods[i].isValid()) {
				valid = false;
			}
		}
		return(valid);
	}

	void CalorieList::init(int noOfItems) {
		foods = new Food[noOfItems]();
		for (int i = 0; i < noOfItems; i++) {
			foods[i].setEmpty();
		}
		m_noOfItems = noOfItems;
		m_itemsAdded = 0;
	}

	bool CalorieList::add(const char* food_name, int cal, int mealCode) {
		if (m_itemsAdded < m_noOfItems) {
			foods[m_itemsAdded].set(food_name, cal, mealCode);
			m_itemsAdded++;
			return true;
		}
		return false;
	}

	void CalorieList::display() const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			foods[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		for (int i = 0; i < m_noOfItems; i++) {
			foods[i].setEmpty();
		}
		delete[] foods;
	}
}