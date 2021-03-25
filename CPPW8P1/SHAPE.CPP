#include "Shape.h"

namespace sdds {
	std::ostream& Shape::operator<<(std::ostream& ostr) {
		draw(ostr);
		return ostr;
	}

	std::istream& Shape::operator>>(std::istream& istr) {
		getSpecs(istr);
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
}