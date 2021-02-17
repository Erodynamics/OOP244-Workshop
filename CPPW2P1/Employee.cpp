#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
	  int i, j;
	  Employee temp;
	  for (i = noOfEmployees - 1; i > 0; i--) {
		 for (j = 0; j < i; j++) {
			if (employees[j].m_empNo > employees[j + 1].m_empNo) {
			   temp = employees[j];
			   employees[j] = employees[j + 1];
			   employees[j + 1] = temp;
			}
		 }
	  }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(struct Employee* emp, int index) {
	  bool ok = false;
	  char name[128];
	  int nameLen;
	  /* if reading of employee number, salary and name are successful
			  allocate memory to the size of the name + 1
			  and keep its address in the name of the Employee Reference

			  copy the name into the newly allocated memroy

			  make sure the "ok" flag is set to true
		 end if
	  */

	  if (read(name) && read(emp[index].m_empNo) && read(emp[index].m_salary)) {
		  // allocate memory
		  nameLen = strLen(name) + 1;
		  emp[index].m_name = new char(nameLen);
		  // copy name to memory
		  strCpy(emp[index].m_name, name);
		  emp[index].m_name[nameLen] = 0;
		  // set ok flag
		  ok = true;
	  }
	  return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
	  bool ok = false;
	  int i = 0;
	  if (openFile(DATAFILE)) {
		 /* 
		  Set the noOfEmployees to the number of recoreds in the file.
		  dyanamically allocated an array of employees into the global
		  Employee pointer; "employees" to the size of the noOfEmployees.

		  In a loop load the employee records from the file into 
		  the dynamic array.

		  If the number of the records does not match the number of reads
			 print the message
			"Error: incorrect number of records read; the data is possibly corrupted"
		  Otherwise
			 set the ok flag to true
		  End if

		  close the file
		  */
		  noOfEmployees = noOfRecords();
		  employees = new Employee[noOfEmployees];
		  for (; i < noOfEmployees; i++) {
			  char name[128];
			  employees[i].m_name = new char[128];
			  if (read(employees[i].m_empNo) && read(employees[i].m_salary) && read(name)) {
				  strCpy(employees[i].m_name, name);
				  employees[i].m_name[strLen(employees[i].m_name) + 1] = 0;
				  ok = true;
			  } else {
				  cout << "Error: incorrect number of records read; the data is possibly corrupted.";
			  }
		  }
		  closeFile();
		  return ok;
	  }
	  else {
		 cout << "Could not open data file: " << DATAFILE<< endl;
	  }
	  return ok;
   }

   // TODO: Implementation for the display functions go here
   void display() {
	   cout << "Employee Salary report, sorted by employee number" << endl;
	   cout << "no- Empno, Name, Salary" << endl;
	   cout << "------------------------------------------------" << endl;
	   sort();
	   for (int i = 0; i < noOfEmployees; i++) {
		   cout << i + 1 << "- ";
		   display(employees, i);
	   }
   }

   void display(const struct Employee* emp, int index) {
	   cout << emp[index].m_empNo << ": ";
	   cout << emp[index].m_name << ", ";
	   cout << emp[index].m_salary << endl;
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
	   for (int i = 0; i < noOfEmployees; i++) {
		   delete[] employees[i].m_name;
	   }
	   delete[] employees;
   }
}