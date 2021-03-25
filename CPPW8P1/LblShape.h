#pragma once
#ifndef _SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
#define _SDDS_LBLSHAPE_H

namespace sdds {
	class LblShape : public Shape {
		char* m_label;
	protected:
		const char* label();
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape operator=(const LblShape&) = delete;
		void getSpecs(std::istream& istr) override;
		std::ostream& operator<<(std::ostream& ostr);
		std::istream& operator>>(std::istream& istr);
	};
}

#endif // _SDDS_LBLSHAPE_H