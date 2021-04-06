#include "CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket){
       nextCovidTicket++;
   }

   char CovidPatient::type(){
       return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
       Patient::csvRead(istr);
       nextCovidTicket = number() + 1;
       istr.ignore(256, '\n');
       return istr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {
       if (this->fileIO()) {
           CovidPatient::csvRead(istr);
       } else {
           Patient::read(istr);
       }
       return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) {
       if (this->fileIO()) {
           Patient::csvWrite(ostr);
       } else {
           ostr << "COVID TEST\n";
           Patient::write(ostr);
       }

       return ostr;
   }
}