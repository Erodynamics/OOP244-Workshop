#include <iostream>
#include <cstring>
#include "LblShape.h"

namespace sdds {
	const char* LblShape::label() {
		return m_label;
	}

	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		m_label = new char[strlen(label + 1)]();
		strcpy(m_label, label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& istr) {
		
	}

	std::ostream& LblShape::operator<<(std::ostream& ostr) {

	}
	std::istream& LblShape::operator>>(std::istream& istr) {
		
	}
}