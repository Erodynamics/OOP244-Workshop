#ifndef _SDDS_IOABLE_H
#define _SDDS_IOABLE_H
#include <iostream>

namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() = 0 {};
	};

	std::ostream& operator<<(std::ostream& ostr, IOAble& IOAObj);
	std::istream& operator>>(std::istream& istr, IOAble& IOAObj);
}

#endif // _SDDS_IOABLE_H