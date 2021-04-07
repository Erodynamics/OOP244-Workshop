#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"

namespace sdds {
	class CovidPatient : public Patient {
	public:
		CovidPatient();
		char type() const;

		std::istream& csvRead(std::istream& istr);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
}

#endif // !SDDS_COVIDPATIENT_H_