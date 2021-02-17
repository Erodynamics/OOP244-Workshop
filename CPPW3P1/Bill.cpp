#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bill.h"
namespace sdds {

	// Bill Class contains:
	// char m_title[37]
	// Item* m_items
	// int m_noOfItems
	// int m_itemsAdded

	double Bill::totalTax() const {
		double tax = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			tax += m_items[i].tax();
		}
		return tax;
	}

	double Bill::totalPrice() const {
		double subTotal = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			subTotal += m_items[i].price();
		}
		return subTotal;
	}

	void Bill::Title() const {
		if (isValid()) {
			std::cout << "+--------------------------------------+" << std::endl;
			std::cout << "| " << std::left;
			std::cout.width(36); std::cout << m_title;
			std::cout << " |" << std::endl;

		} else {
			std::cout << "+--------------------------------------+" << std::endl;
			std::cout << "| Invalid Bill                         |" << std::endl;
		}
		std::cout << "+----------------------+---------+-----+" << std::endl;
		std::cout << "| Item Name            | Price   + Tax |" << std::endl;
		std::cout << "+----------------------+---------+-----+" << std::endl;
	}

	void Bill::footer() const {
		std::cout << "+----------------------+---------+-----+" << std::endl;
		if (isValid()) {
			std::cout << "|                Total Tax: ";
			std::cout << std::right; std::cout.width(10);
			std::cout << totalTax() << " |" << std::endl;

			std::cout << "|              Total Price: ";
			std::cout << std::right; std::cout.width(10);
			std::cout << totalPrice() << " |" << std::endl;

			std::cout << "|          Total After Tax: ";
			std::cout << std::right; std::cout.width(10);
			std::cout << (totalTax() + totalPrice()) << " |" << std::endl;
		} else {
			std::cout << "| Invalid Bill                         |" << std::endl;
		}
		std::cout << "+--------------------------------------+" << std::endl;

	}

	void Bill::setEmpty() {
		for (int i = 0; i < 37; i++) {
			m_title[i] = 0;
		}
		m_items = nullptr;
		m_noOfItems = 0;
		m_itemsAdded = 0;
	}

	bool Bill::isValid() const {
		bool valid = true;
		if (strcmp(m_title, "\0") == 0 || m_noOfItems == 0 || m_itemsAdded == 0) {
			valid = false;
		}
		for (int i = 0; i < m_noOfItems; i++) {
			if (!m_items[i].isValid()) {
				valid = false;
			}
		}
		return(valid);
	}

	void Bill::init(const char* title, int noOfItems) {
		m_items = new Item[noOfItems]();
		for (int i = 0; i < noOfItems; i++) {
			m_items[i].setEmpty();
		}
		strncpy(m_title, title, 37);
		m_noOfItems = noOfItems;
		m_itemsAdded = 0;
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			debug();
			return true;
		}
		return false;
	}

	void Bill::display() const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].setEmpty();
		}
		delete[] m_items;
	}

	void Bill::debug() {
		bool debug = false;
		if (debug) {
			std::cout << "m_title: " << m_title << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < m_noOfItems; i++) {
				std::cout << "m_items[" << i << "]: " << std::endl;
				std::cout << "m_items[" << i << "].m_itemName: " << m_items[i].getName() << std::endl;
				std::cout << "m_items[" << i << "].m_price: " << m_items[i].getPrice() << std::endl;
				std::cout << "m_items[" << i << "].m_taxed: " << m_items[i].getTaxed() << std::endl;
				std::cout << std::endl;
			}
			std::cout << "m_noOfItems: " << m_noOfItems << std::endl;
			std::cout << "m_itemsAdded: " << m_itemsAdded << std::endl;
			std::cout << std::endl;
		}
	}
}