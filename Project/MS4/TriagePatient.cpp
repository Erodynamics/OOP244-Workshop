#include "TriagePatient.h"
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

   char TriagePatient::type() {
	   return 'T';
   }
}