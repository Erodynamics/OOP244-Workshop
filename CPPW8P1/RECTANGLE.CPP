#include "Rectangle.h"

namespace sdds {
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, float height, float width) : LblShape(label){
		if (height < 3 || width < (strlen(label) + 2)) {
			m_width = 0;
			m_height = 0;
		} else {
			m_height = height;
			m_width = width;
		}
	}

	void Rectangle::draw(std::ostream& ostr)const {
		// Top
		ostr << '+';
		for (int i = 0; i < m_width - 2; i++) {
			ostr << '-';
		}
		ostr << '+';

		// Sides + Text NOT DONE

		// Bottom
		ostr << '+';
		for (int i = 0; i < m_width - 2; i++) {
			ostr << '-';
		}
		ostr << '+';
	}
	void Rectangle::getSpecs(std::istream& istr) {
		char* temp;
	}
}
