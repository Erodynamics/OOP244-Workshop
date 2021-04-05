#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "utils.h"

namespace sdds {
	void Menu::display() {
		std::cout << m_text << std::endl;
		std::cout << "0- Exit" << std::endl;
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		if (strlen(MenuContent) != 0) {
			m_text = new char[strlen(MenuContent) + 1]();
			strcpy(m_text, MenuContent);
			m_noOfSel = NoOfSelections;
		} else {
			m_text = nullptr;
			m_noOfSel = NoOfSelections;
		}
	}

	Menu::~Menu() {
		delete[] m_text;
		m_noOfSel = 0;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid Option ", true);
		return Selection;
	}

	Menu::Menu(const Menu& source) {
		m_text = nullptr;
		m_noOfSel = 0;

		if (source.m_text != nullptr) {
			m_text = new char[strlen(source.m_text) + 1]();
			strcpy(m_text, source.m_text);
			m_noOfSel = source.m_noOfSel;
		}
	}
}
