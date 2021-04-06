#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		~TriagePatient();

		char type();

		std::istream& csvRead(std::istream& istr);
		std::istream& read(std::istream& istr);
		std::ostream& csvWrite(std::ostream& ostr);
		std::ostream& write(std::ostream ostr);
	};
}

#endif // !SDDS_TRIAGEPATIENT_H