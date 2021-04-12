#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket){
	   m_symptoms = NULL;
	   nextTriageTicket++;
   }

   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }

   char TriagePatient::type() const {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   ostr << ',';
	   ostr << m_symptoms;
	   nextTriageTicket = number() + 1;
	   return ostr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const {
	   if (fileIO()) {
		   TriagePatient::csvWrite(ostr);
	   } else {
		   ostr << "TRIAGE\n";
		   Patient::write(ostr);
		   ostr << std::endl;
		   ostr << "Symptoms: ";
		   ostr << m_symptoms;
		   ostr << std::endl;
	   }

	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   char tempSymptoms[1024];

	   delete[] m_symptoms;
	   m_symptoms = nullptr;

	   Patient::csvRead(istr);

	   istr.ignore(256, ',');
	   istr.getline(tempSymptoms, 1024, '\n');
	   m_symptoms = new char[strlen(tempSymptoms) + 1]();
	   strcpy(m_symptoms, tempSymptoms);

	   nextTriageTicket = number() + 1;
	   return istr;
   }

   std::istream& TriagePatient::read(std::istream& istr) {
	   if (fileIO()) {
		   TriagePatient::csvRead(istr);
	   } else {
		   delete[] m_symptoms;
		   m_symptoms = nullptr;

		   Patient::read(istr);
		   m_symptoms = getcstr("Symptoms: ", istr);
	   } 
	   return istr;
   }
}