// Workshop 2: DIY
// Date: 2/1/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////


#pragma once
#ifndef SDDS_POPULATION_H

namespace sdds {
	// postCode struct
	struct PostalCode {
		char* prefix;
		int popCount;
	};

	// Prototypes
	void sort();
	bool load(const char filename[]);
	void display();
	void display(const struct PostalCode* pc, int index);
	void deallocateMemory();
}

#endif