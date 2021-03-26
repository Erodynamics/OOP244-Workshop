#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include <string>

namespace sdds {
	Line::Line() {
		m_length = 0.0;
	}

	Line::Line(const char* label, float length) : LblShape(label) {
		m_length = length;
	}

	void Line::draw(std::ostream& ostr) {
		if (m_length > 0 && strlen(LblShape::label()) > 0) {
			LblShape::draw(ostr);
			ostr << std::endl;
			for (int i = 0; i < m_length; i++) {
				ostr << '=';
			}
			ostr << std::endl;
		}
	}

	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		char temp[256];

		// Reads comma-delimited stream and converts cstring into an int to be placed into m_length.
		if (istr.good()) {
			istr.getline(temp, 256, ',');
<<<<<<< HEAD
			m_length = std::stof(temp);
=======
			m_length = atoi(temp);
>>>>>>> fd6de2add8787f4f9099a810e8675e0a05d39500
		} else {
			std::cerr << "Stream is not usable.";
		}
	}
}