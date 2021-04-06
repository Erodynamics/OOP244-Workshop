#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"

namespace sdds {
	class CovidPatient : public Patient {
		CovidPatient();
		char type();

		std::istream& csvRead(std::istream& istr);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr);
	};
}

#endif // !SDDS_COVIDPATIENT_H_