#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
	public:
		char* m_symptoms;

		TriagePatient();
		~TriagePatient();

		char type() const;

		std::istream& csvRead(std::istream& istr);
		std::istream& read(std::istream& istr);
		std::ostream& csvWrite(std::ostream& ostr) const;
		std::ostream& write(std::ostream& ostr) const;
	};
}

#endif // !SDDS_TRIAGEPATIENT_H