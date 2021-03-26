#pragma once
#ifndef _SDDS_LINE_H
#define _SDDS_LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		float m_length;
	public:
		Line();
		Line(const char* label, float length);
		void draw(std::ostream& ostr);
		void getSpecs(std::istream& istr);
	};
}

#endif // _SDDS_LINE_H