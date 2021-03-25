#pragma once
#ifndef _SDDS_SHAPE_H
#include <iostream>
#define _SDDS_SHAPE_H

namespace sdds {
	class Shape {
	public:
		virtual ~Shape() = 0;
		virtual void draw(std::ostream& ostr) = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual std::ostream& operator<<(std::ostream& ostr) = 0;
		virtual std::istream& operator>>(std::istream& istr) = 0;
	};
}

#endif // _SDDS_SHAPE_H
