#pragma once
#ifndef _SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
#define _SDDS_LINE_H

namespace sdds {
	class Line : public LblShape {
		float m_length;
	public:
		Line();
		Line(const char* label, float length);
		void draw(std::ostream& ostr)const;
		void getSpecs(std::istream& istr);
	};
}

#endif // _SDDS_LINE_H