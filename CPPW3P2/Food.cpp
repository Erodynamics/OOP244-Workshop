#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Food.h"

// Food class contains:
// char foodName[31];
// int calories;
// int meal;

namespace sdds {
	void Food::setName(const char* name) {
		if (name == nullptr) {
			foodName[0] = 0;
		} else {
			strncpy(foodName, name, 30);
		}
	}

	void Food::setEmpty() {
		// Initializes the item with zeros
		for (int i = 0; i < 21; i++) {
			foodName[i] = 0;
		}
		calories = 0;
		meal = 0;
	}

	void Food::set(const char* name, int foodcalories, int mealCode) {
		if (name == nullptr) {
			foodName[0] = 0;
		} else {
			strncpy(foodName, name, 30);
		}
		calories = foodcalories;
		meal = mealCode;
	}

	void Food::display() const {
		// Checks if the item is valid
		if (isValid()) {
			// Prints out item
			std::cout << "| " << std::left << std::fixed; std::cout.width(30); std::cout.fill('.');
			std::cout << foodName;

			std::cout << " | " << std::right; std::cout.width(4); std::cout.fill(' ');
			std::cout << calories;

			switch (meal) {
			case 1:
				std::cout << " | Breakfast ";
				break;
			case 2:
				std::cout << " | Lunch     ";
				break;
			case 3:
				std::cout << " | Dinner    ";
				break;
			case 4:
				std::cout << " | Snack     ";
				break;
			}

			std::cout << " |" << std::endl;
		} else {
			// If the item isn't valid, print a placeholder instead
			std::cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << std::endl;
		}
	}

	bool Food::isValid() const {
		if (foodName[0] != '\0' && meal > 0 && calories > 0 && calories <= 3000) {
			return true;
		} else {
			return false;
		}
	}

	int Food::getCalories() const {
		return calories;
	}

	int Food::getMeal() const {
		return meal;
	}

}