#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include <string>
#include <regex>

namespace sdds {
	Line::Line() {
		m_length = 0.0;
	}

	Line::Line(const char* label, float length) : LblShape(label) {
		m_length = length;
	}

	void Line::draw(std::ostream& ostr) {
		if (m_length > 0 && strlen(label()) > 0) {
			ostr << label() << std::endl;
			ostr << std::endl;
			for (int i = 0; i < m_length; i++) {
				ostr << '=';
			}
			ostr << std::endl;
		}
	}

	void Line::getSpecs(std::istream& istr) {
		char temp[256];
		std::stringstream temp2();
		LblShape::getSpecs(istr);
		

		// Reads comma-delimited stream and converts cstring into an int to be placed into m_length.
		if (istr.good()) {
			istr.getline(temp, 256);
			
			m_length = std::stof(temp);
		} else {
			std::cerr << "Stream is not usable.";
		}
	}
}
