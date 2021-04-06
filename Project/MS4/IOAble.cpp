#include "IOAble.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, IOAble& IOAObj) {
		IOAObj.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, IOAble& IOAObj){
		IOAObj.read(istr);
		return istr;
	}
}