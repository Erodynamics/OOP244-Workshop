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
<<<<<<< HEAD
=======
		std::ostream& operator<<(std::ostream& ostr);
		std::istream& operator>>(std::istream& istr);
>>>>>>> fd6de2add8787f4f9099a810e8675e0a05d39500
	};
}

#endif // _SDDS_LBLSHAPE_H