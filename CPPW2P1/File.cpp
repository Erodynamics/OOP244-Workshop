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
   bool read(char* empName) {
       return fscanf(fptr, "%[^\n]\n", empName);
   }

   bool read(int& empNum) {
       return fscanf(fptr, "%d,", &empNum);
   }

   bool read(double& empSal) {
       return fscanf(fptr, "%lf,", &empSal);
   }
}