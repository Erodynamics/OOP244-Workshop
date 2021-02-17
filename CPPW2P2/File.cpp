// Workshop 2: DIY
// Date: 2/1/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(char* postCode) {
       return fscanf(fptr, "%[^,],", postCode);
   }

   bool read(int& popCount) {
       return fscanf(fptr, "%d\n", &popCount);
   }
}