#include "Line.h"

namespace sdds {
	Line::Line() {
		m_length = 0.0;
	}

	Line::Line(const char* label, float length) : LblShape(label) {
		m_length = length;
	}

	void Line::draw(std::ostream& ostr)const {

	}

	void Line::getSpecs(std::istream& istr) {

	}
}
