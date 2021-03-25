#define _CRT_SECURE_NO_WARNINGS
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

	void Rectangle::draw(std::ostream& ostr) {
		int labelLen = strlen(label());
		// Top
		ostr << '+';
		for (int i = 0; i < m_width - 2; i++) {
			ostr << '-';
		}
		ostr << '+';

		// Sides + Text NOT DONE
		
		ostr << '|' << std::left;
		ostr << label();
		ostr << ostr.flags();
		for (int i = 0; i < m_width - labelLen - 1; i++) {
			ostr << ' ';
		}
		ostr << '|';
		
		
		// Sides
		ostr << '|';
		for (int i = 0; i < m_width - 2; i++) {
			ostr << ' ';
		}
		ostr << '|';
		

		// Bottom
		ostr << '+';
		for (int i = 0; i < m_width - 2; i++) {
			ostr << '-';
		}
		ostr << '+';
	}
	void Rectangle::getSpecs(std::istream& istr) {
		
		LblShape::getSpecs(istr);
		if (istr.good()) {
			
		}
	}
}
