#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Item.h"

/// Item Class contains:
/// char m_itemName[21];
/// double m_price;
/// bool m_taxed;

namespace sdds {

	void Item::setName(const char* name){
		if (name == nullptr) {
			m_itemName[0] = 0;
		} else {
			strncpy(m_itemName, name, 20);
		}
	}

	void Item::setEmpty(){
		// Initializes the item with zeros
		for (int i = 0; i < 21; i++) {
			m_itemName[i] = 0;
		}
		m_price = 0.0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed) {
		// Sets the name and price of the item, as well as if the item is taxed
		Item::setName(name);
		m_price = price;
		m_taxed = taxed;
	}

	void Item::display() const {
		// Checks if the item is valid
		if (isValid()) {
			// Prints out item
			std::cout << "| " << std::left << std::fixed << std::setprecision(2); std::cout.width(20); std::cout.fill('.');
			std::cout << m_itemName;

			std::cout << " | " << std::right; std::cout.width(7);  std::cout.fill(' ');
			std::cout << m_price;

			if (m_taxed) {
				std::cout << " | " << std::left; std::cout.width(3);
				std::cout << "Yes";
			} else {
				std::cout << " | " << std::left; std::cout.width(3);
				std::cout << "No";
			}
			std::cout << " |" << std::endl;
		} else {
			// If the item isn't valid, print a placeholder instead
			std::cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << std::endl;
		}
	}

	bool Item::isValid() const {
		// Checks if the item is null terminated or has its price zeroed
		if (m_itemName[0] != '\0' && m_price > 0) {
			return true;
		} else {
			return false;
		}
	}

	double Item::price() const {
		// Returns the price of the item
		return m_price;
	}

	double Item::tax() const {
		// Returns the item price plus Ontario GST
		if (m_taxed) {
			return m_price * 0.13;
		} else {
			return 0;
		}
	}
	char* Item::getName() {
		return m_itemName;
	}
	double Item::getPrice(){
		return m_price;
	}
	bool Item::getTaxed() {
		return m_taxed;
	}
}