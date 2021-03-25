#pragma once
#ifndef _SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
#define _SDDS_RECTANGLE_H

namespace sdds {
	class Rectangle : public LblShape {
		float m_height;
		float m_width;
	public:
		Rectangle();
		Rectangle(const char* label, float height, float width);
		void draw(std::ostream& ostr)const;
		void getSpecs(std::istream& istr);
	};
}

#endif // _SDDS_RECTANGLE_H
