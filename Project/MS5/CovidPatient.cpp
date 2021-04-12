#include "CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket){
	   nextCovidTicket++;
   }

   char CovidPatient::type() const{
	   return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   istr.ignore(256, '\n');
	   nextCovidTicket = number() + 1;
	   return istr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {
	   if (fileIO()) {
		   CovidPatient::csvRead(istr);
	   } else {
		   Patient::read(istr);
	   }
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const {
	   if (fileIO()) {
		   Patient::csvWrite(ostr);
	   } else {
		   ostr << "COVID TEST\n";
		   Patient::write(ostr);
		   ostr << std::endl;
	   }

	   return ostr;
   }
}