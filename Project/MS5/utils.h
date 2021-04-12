#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
#include "Time.h"
namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"

   int getTime(); // returns the time of day in minutes
   int getInt(const char* prompt = nullptr);
   int getInt(
       int min,   // minimum acceptable value
       int max,   // maximum acceptable value
       const char* prompt = nullptr,  // User entry prompt
       const char* errorMessage = nullptr, // Invalid value error message
       bool showRangeAtError = true    // display the range if invalud value entered 
   );
   char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');
   int getHour(int minutes); // returns hour conversion
   int getMinute(int minutes); // returns minutes after hour conversion

   template <typename type>
   void removeDynamicElement(type* array[], int index, int& size) {
       delete array[index];
       for (int j = index; j < size; j++) {
           array[j] = array[j + 1];
       }
       size--;
   }
}
#endif // !SDDS_UTILS_H_

