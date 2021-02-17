// Workshop 2: DIY
// Date: 2/1/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	// TODO: Declare read prototypes
	bool read(char*);
	bool read(int&);
}
#endif // !SDDS_FILE_H_