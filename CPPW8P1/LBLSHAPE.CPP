#define _CRT_SECURE_NO_WARNINGS
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
		char temp[256];

		// Reads comma-delimited stream and places the cstring into m_label.
		if (istr.good()) {
			istr.getline(temp, 256, ',');
			istr.get();
			m_label = new char[strlen(temp) + 1]();
			strcpy(m_label, temp);
		} else {
			std::cerr << "Stream is not usable.";
		}
	}
}