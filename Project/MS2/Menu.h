#ifndef _SDDS_MENU_H
#define _SDDS_MENU_H
#include <iostream>

namespace sdds {
	class Menu {
		char* m_text;
		int m_noOfSel;
		void display();

	public:
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);

		Menu(const Menu& source);
		Menu& operator=(Menu& copy) = delete;
	};
}

#endif // _SDDS_MENU_H