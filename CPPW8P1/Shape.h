#pragma once
#ifndef _SDDS_SHAPE_H
#define _SDDS_SHAPE_H

#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual ~Shape() {};
		virtual void draw(std::ostream& ostr) = 0;
		virtual void getSpecs(std::istream& istr) = 0;
	};

	std::ostream& operator<<(std::ostream& ostr, Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}

#endif // _SDDS_SHAPE_H